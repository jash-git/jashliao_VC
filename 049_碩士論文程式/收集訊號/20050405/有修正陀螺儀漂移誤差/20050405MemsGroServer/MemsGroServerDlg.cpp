// MemsGroServerDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MemsGroServer.h"
#include "MemsGroServerDlg.h"
#include "Filter.h"
#include "Fuzzy.h"
#include "Kalman.h"
struct Net_Data
{
	float pitch;
	float yaw;
	float roll;
};
FILE *p,*f;
int count;
float pitch,yaw,roll;
CSocket sockListen;
float GyroError[3][2],FollowError[3][2];
//////////////////////////////////////////////以下為四元素的變數區
float delt=0.01f;
float theta=0.0f, phi=0.0f, psi=0.0f ;
float s11=0.0f,s22=0.0f,s33=0.0f,c11=0.0f,c22=0.0f,c33=0.0f;
float e0=0.0f,e1=0.0f,e2=0.0f,e3=0.0f;
float epsilon=0.0f;
float e0d=0.0f,e1d=0.0f,e2d=0.0f,e3d=0.0f;//e0"d"d為微分的意思,0為四元素
                                          //第一個參數.到3第四個參數
float l1=0.0f,l2=0.0f,l3=0.0f,m3=0.0f,n3=0.0f,ll3=0.0f;
float phasenow=0.0f,invphi=0.0f,invpsi=0.0f;
float P_value=0.0f,Q_value=0.0f,R_value=0.0f;//PQR為陀螺儀所量測到之角速率
///////////////////////////////以上為四元素的變數區
#include "D2kDASK.H"
#include <sys\timeb.h>
#include <stdio.h>
#include <math.h>
FILE *GyroTheta,*GyroPhi,*GyroPsi;//三個檔為存陀螺儀三個角度參數三個檔
//////////////////////////////
/////////////////////////////////////////////
I16 card;
U16 card_num=0;
U16 Channel[4]={0,1,2,3};
U16 Data[4]={0,0,0,0};
FILE *TimerGet1,*TimerGet2,*TimerGet3;//未濾波前分別為PQR的三個檔
FILE *FilterGet1,*FilterGet2,*FilterGet3;//濾波後分別為PQR的三個檔
FILE *GyroV1,*GyroV2,*GyroV3;//三個檔為存三顆陀螺儀三個因變換角度所改變之電壓
FILE *tp;
bool bopencard=false;
bool bontimer=false;
CFilter Filter1,Filter2,Filter3;//三個低濾波器供三顆陀螺儀
///////////////////////////////////////////
CKalman EKF;
FILE *EKF_file1,*EKF_file2,*EKF_file3;
FILE *alphafile,*betafile;
bool bGroError;
///////////////////////////////////////////
int MeanCount;
float Sumtheta,Sumphi,Sumpsi;
float Meantheta,Meanphi,Meanpsi;
/////
int MeanCount2;
float Sumtheta2,Sumphi2,Sumpsi2;
float Meantheta2,Meanphi2,Meanpsi2;
float Angle_a[3],AngleCount,Angle_y0[3],Angle_x0[3],Angle_b[3],Angle_y1[3],Angle_x1[3],SumAngleCount;
/////////////////////////////////////////////
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMemsGroServerDlg dialog

CMemsGroServerDlg::CMemsGroServerDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMemsGroServerDlg::IDD, pParent)
{
	//int i;
	//{{AFX_DATA_INIT(CMemsGroServerDlg)
	m_str1 = _T("");
	m_v1 = 0.0;
	m_v2 = 0.0;
	m_v3 = 0.0;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	p=fopen("netdata.txt","w");
	f=fopen("data.txt","w");
	pitch=0.0f;
	yaw=0.0f;
	roll=0.0f;
	count=1;
	MeanCount=0;
	Sumtheta=0.0f;
	Sumphi=0.0f;
	Sumpsi=0.0f;
	Meantheta=0.0f;
	Meanphi=0.0f;
	Meanpsi=0.0f;
	////////////////////////
	/*
	for(i=0;i<3;i++)
	{
		Angle_a[i]=0.0f;
		Angle_b[i]=0.0f;
		Angle_y0[i]=0.0f;
		Angle_y1[i]=0.0f;
		Angle_x0[i]=0.0f;
		Angle_x1[i]=0.0f;
	}
	AngleCount=0;
	SumAngleCount=0;
	*/
	////////////////////////////////
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMemsGroServerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMemsGroServerDlg)
	DDX_Text(pDX, IDC_EDIT1, m_str1);
	DDX_Text(pDX, IDC_EDIT2, m_v1);
	DDX_Text(pDX, IDC_EDIT3, m_v2);
	DDX_Text(pDX, IDC_EDIT4, m_v3);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMemsGroServerDlg, CDialog)
	//{{AFX_MSG_MAP(CMemsGroServerDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_DESTROY()
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMemsGroServerDlg message handlers

BOOL CMemsGroServerDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	for(int j=0;j<3;j++)
		for(int i=0;i<2;i++)
		{
			GyroError[j][i]=0.0f;
			FollowError[j][i]=0.0f;
		}
	////////////////////////////////////////////////////四元數變數初始化
	delt=0.01f;
	theta=0.0f;phi=0.0f;psi=0.0f ;
	s11=0.0f;s22=0.0f;s33=0.0f;c11=0.0f;c22=0.0f;c33=0.0f;
	e0=0.0f;e1=0.0f;e2=0.0f;e3=0.0f;
	epsilon=0.0f;
	e0d=0.0f;e1d=0.0f;e2d=0.0f;e3d=0.0f;
	l1=0.0f;l2=0.0f;l3=0.0f;m3=0.0f;n3=0.0f;ll3=0.0f;
	phasenow=0.0f;invphi=0.0f;invpsi=0.0f;
	P_value=0.0f;Q_value=0.0f;R_value=0.0f;
	///////////////////////////////////////////
	card=D2K_Register_Card(DAQ_2006,card_num);
	/////////////////////////////////////////
	D2K_AI_CH_Config(card,Channel[0],AD_U_5_V);
	D2K_AI_CH_Config(card,Channel[1],AD_U_5_V);
	D2K_AI_CH_Config(card,Channel[2],AD_U_5_V);
	D2K_AI_CH_Config(card,Channel[3],AD_U_5_V);
	TimerGet1=fopen("R未濾波.txt","w");
	TimerGet2=fopen("P未濾波.txt","w");
	TimerGet3=fopen("Q未濾波.txt","w");
	FilterGet1=fopen("R.txt","w");
	FilterGet2=fopen("P.txt","w");
	FilterGet3=fopen("Q.txt","w");
	GyroV1=fopen("GyroV1.txt","w");
	GyroV2=fopen("GyroV2.txt","w");
	GyroV3=fopen("GyroV3.txt","w");
	EKF_file1=fopen("EKF_X.txt","w");
	EKF_file2=fopen("EKF_Y.txt","w");
	EKF_file3=fopen("EKF_Z.txt","w");
	alphafile=fopen("alphafile.txt","w");
	betafile=fopen("betafile.txt","w");
	////////////////////////////////////////////
	bopencard=true;
	////////////////////////////////////////////
	GyroTheta=fopen("Theta.txt","w");
	GyroPhi=fopen("Phi.txt","w");
	GyroPsi=fopen("Psi.txt","w");
	tp=fopen("時間差.txt","w");
	UpdateData(true);
	m_str1="等待網路啟動";
	UpdateData(false);
	bGroError=false;
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMemsGroServerDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMemsGroServerDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMemsGroServerDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMemsGroServerDlg::OnDestroy() 
{
	CDialog::OnDestroy();
	
	// TODO: Add your message handler code here
	
}

BOOL CMemsGroServerDlg::DestroyWindow() 
{
	// TODO: Add your specialized code here and/or call the base class
	KillTimer(1);
	fclose(p);
	fclose(f);
	fclose(tp);
	fclose(TimerGet1);
	fclose(TimerGet2);
	fclose(TimerGet3);
	fclose(GyroTheta);
	fclose(FilterGet1);
	fclose(FilterGet2);
	fclose(FilterGet3);
	fclose(GyroPhi);
	fclose(GyroPsi);
	fclose(EKF_file1);
	fclose(EKF_file2);
	fclose(EKF_file3);
	D2K_Release_Card(card);
	bopencard=false;
	return CDialog::DestroyWindow();
}

void CMemsGroServerDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	struct Net_Data data1;
	//float dGyroError[3],dFollowError[3];
	int a,iSend,i,j;
	struct timeb t,t1;
	float EKF_X[3],EKF_Z[3];
	float R1[3][3],Q1[3][3];
	//////////////////////////////////////
	CFuzzy EGyroFuzzy[2][3],EFollowFuzzy[2][3];
	CFuzzy OGyroFuzzy[3],OFollowFuzzy[3];
	float EBuffer1[3],EBuffer2[3];
	float EBuffer3[3],EBuffer4[3];
	float alpha[3],beta[3];
	float alpha1[3][3],beta1[3][3];
	float jj;
	//////////////////////////////////////
	float de[3]={0};
	double Tovalue[3]={0.0};
	double ToRadian[3]={0.0};
	float theta1,phi1,psi1;
	theta1=0.0f;
	phi1=0.0f;
	psi1=0.0f;
	/////////////////////////////////////////
	ftime(&t);
	/*
	//////////////////////////////////////////////
	for(i=0;i<3;i++)
	{
		dGyroError[i]=0.0f;
		dFollowError[i]=0.0f;
	}
	///////////////////////////////////////////////
	*/
	if(bopencard)
	{
		//////////////////////////////////////////////////把網路值收下來
		a=sizeof(data1.pitch)+sizeof(data1.yaw)+sizeof(data1.roll);
		iSend=m_sockSend.Receive(&data1,a,0);
		if(data1.pitch>-200.0f && data1.roll>-200.0f &&data1.yaw>-200.0f)
		{
			fprintf(p,"%f\t%f\t%f\n",data1.pitch,data1.yaw,data1.roll);
			////////////////////////////////////////////////////////////
			D2K_AI_ReadChannel(card,Channel[0],&Data[0]);
			D2K_AI_ReadChannel(card,Channel[1],&Data[1]);
			D2K_AI_ReadChannel(card,Channel[2],&Data[2]);
			D2K_AI_ReadChannel(card,Channel[3],&Data[3]);
			de[0]=(Data[3]/2.0f)-Data[0];//先扣去基本電壓2.5V
			de[1]=(Data[3]/2.0f)-Data[1];//先扣去基本電壓2.5V
			de[2]=(Data[3]/2.0f)-Data[2];//先扣去基本電壓2.5V
			Tovalue[0]=(2.5*(double)de[0])/(Data[3]/2.0f);//得到變化電壓
			Tovalue[1]=(2.5*(double)de[1])/(Data[3]/2.0f);//得到變化電壓
			Tovalue[2]=(2.5*(double)de[2])/(Data[3]/2.0f);//得到變化電壓
			fprintf(GyroV1,"%f\n",Tovalue[0]);
			fprintf(GyroV2,"%f\n",Tovalue[1]);
			fprintf(GyroV3,"%f\n",Tovalue[2]);
			//////////////////////////////////////////
			ToRadian[0]=Tovalue[0]/0.02f/57.29578f;
			ToRadian[1]=Tovalue[1]/0.02f/57.29578f;
			ToRadian[2]=Tovalue[2]/0.02f/57.29578f;
			ToRadian[0]-=(-0.008f);
			ToRadian[1]-=(-0.008f);
			ToRadian[2]-=(-0.008f);
			//////////////////////////////////////////
			fprintf(TimerGet1,"%f\n",ToRadian[0]);
			fprintf(TimerGet2,"%f\n",ToRadian[1]);
			fprintf(TimerGet3,"%f\n",ToRadian[2]);
			//////////////////////////////////////////
			P_value=Filter1.SecOrderLowPass(float(ToRadian[1]));//P_value=float(ToRadian[1]); 
			Q_value=Filter2.SecOrderLowPass(float(ToRadian[2]));//Q_value=float(ToRadian[2]); 
			R_value=Filter3.SecOrderLowPass(float(ToRadian[0]));//R_value=float(ToRadian[0]); 			
			////////////////////////////////////////////////////
			/////////////////////////////////////////////////////////減去由計算出來的平均誤差
			P_value-=Meanphi;
			Q_value-=Meantheta;
			R_value-=Meanpsi;
			/////////////////////////////////////////////////////////
			MeanCount++;
			MeanCount2++;
			if(MeanCount<=300)//以下是moving windows改善主軸瓢移法
			{
				Sumtheta+=Q_value;
				Sumphi+=P_value;
				Sumpsi+=R_value;
			}
			else
			{
				Meantheta=Sumtheta/float(MeanCount-1);
				Meanphi=Sumphi/float(MeanCount-1);
				Meanpsi=Sumpsi/float(MeanCount-1);
				/////////////////////////////////
				MeanCount=1;
				Sumtheta=Q_value;
				Sumphi=P_value;
				Sumpsi=R_value;
			}//以上是moving windows改善主軸瓢移法
			fprintf(FilterGet1,"%f\n",R_value);
			fprintf(FilterGet2,"%f\n",P_value);
			fprintf(FilterGet3,"%f\n",Q_value);
			////////////////////////////////////////////////////////以下為四元數法
			s11=float(sin(theta/2.0f)); s22=float(sin(phi/2.0f)); s33=float(sin(psi/2.0f));
			c11=float(cos(theta/2.0f)); c22=float(cos(phi/2.0f)); c33=float(cos(psi/2.0f));
			e0 =  c11*c22*c33 + s11*s22*s33;
			e1 =  c11*s22*c33 - s11*c22*s33;
			e2 =  s11*c22*c33 + c11*s22*s33;
			e3 = -s11*s22*c33 + c11*c22*s33;
			epsilon = 1.0f - e0*e0 - e1*e1 - e2*e2 - e3*e3;
			e0d = -0.5f * (e1*P_value + e2*Q_value + e3*R_value) + epsilon * e0;
			e1d =  0.5f * (e0*P_value - e3*Q_value + e2*R_value) + epsilon * e1;
			e2d =  0.5f * (e3*P_value + e0*Q_value - e1*R_value) + epsilon * e2;
			e3d =  0.5f * (-e2*P_value + e1*Q_value + e0*R_value) + epsilon * e3;
				
			e0 += e0d * delt; //微分乘以一個得而塔再作累加動作為"積分"
			e1 += e1d * delt;
			e2 += e2d * delt;
			e3 += e3d * delt;
			l1 = e0*e0+e1*e1-e2*e2-e3*e3;//
			l2 = 2.0f * (e1*e2 + e0*e3);//
			l3 = 2.0f * (e1*e3 - e0*e2);//
			m3 = 2.0f * (e2*e3 + e0*e1);//
			n3 = e0*e0-e1*e1-e2*e2+e3*e3;//
			theta=float(asin(-l3));
			phi=float(atan(m3/n3));
			psi=float(atan(l2/l1));
			theta1=float(asin(-l3)*57.29578*10.0f);
			phi1=float(atan(m3/n3)*57.29578*10.0f);
			psi1=float(atan(l2/l1)*57.29578*10.0f);
			///////////////////////以上為四元數法
			////////////////////////////以下為motion window補另兩軸(非主軸)斜率
			if(MeanCount2==300)
			{
				Angle_y1[0]=theta1;
				Angle_y1[1]=phi1;
				Angle_y1[2]=psi1;
				AngleCount++;
				Angle_x1[0]=float(MeanCount2);
				Angle_x1[1]=float(MeanCount2);
				Angle_x1[2]=float(MeanCount2);
				for(i=1;i<3;i++)
				{
					Angle_a[i]=(Angle_y1[i]-Angle_y0[i])/(Angle_x1[i]-Angle_x0[i]);
					Angle_b[i]=Angle_y0[i]-(Angle_a[i]*Angle_x0[i]);
				}
				for(i=1;i<3;i++)
				{
					Angle_y0[i]=Angle_y1[i];
					Angle_x0[i]=0.0f;
				}
				SumAngleCount=0;/////
			}
			else
			{
				SumAngleCount++;/////
				phi1-=(Angle_a[1]*SumAngleCount+Angle_b[1]);
				psi1-=(Angle_a[2]*SumAngleCount+Angle_b[2]);
				if(bGroError==true)
				{
					theta1-=(Angle_a[0]*SumAngleCount+Angle_b[0]);
				}
			}
			///////////////////////////////////以上為motion window補斜率
			///////////////////////////////////////////////
			phi1-=Meanphi2;
			theta1-=Meantheta2;
			psi1-=Meanpsi2;
			if(MeanCount2<=300)
			{
				Sumtheta2+=theta1;
				Sumphi2+=phi1;
				Sumpsi2+=psi1;
			}
			else
			{
				Meantheta2=Sumtheta2/float(MeanCount2-1);
				Meanphi2=Sumphi2/float(MeanCount2-1);
				Meanpsi2=Sumpsi2/float(MeanCount2-1);
				/////////////////////////////////
				MeanCount2=1;
				Sumtheta2=theta1;
				Sumphi2=phi1;
				Sumpsi2=psi1;
			}
			//////////////////////////////////////////////////////
			/*
			if(MeanCount2>180)//創造陀螺儀誤差，測試FUZZY
			{
				theta1+=4.0f;
				phi1+=1.8f;
				psi1+=1.5f;
			}
			*/
			/////////////////////////////////////////////////////
			fprintf(GyroTheta,"%f\n",theta1);
			fprintf(GyroPhi,"%f\n",phi1);
			fprintf(GyroPsi,"%f\n",psi1);
			//////////////////////////////////////////////////
			pitch=float(15.0f*sin(2*3.14159*count/300.0f));
			yaw=float(0.0f*sin(2*3.14159*count/300.0f));
			roll=float(0.0f*sin(2*3.14159*count/300.0f));
			fprintf(f,"%f\t%f\t%f\n",pitch,yaw,roll);
			count++;
			/////////////////////////////////////////---------e(k+1)
			GyroError[0][1]=roll-phi1;//X-----P
			GyroError[1][1]=pitch-theta1;//Y-----Q
			GyroError[2][1]=yaw-psi1;//Z-----R
			//////////////////////////////////////////////////
			FollowError[0][1]=roll-data1.roll;//X-----P
			FollowError[1][1]=pitch-data1.pitch;//Y-----Q
			FollowError[2][1]=yaw-data1.yaw;//Z-----R
			//////////////////////////////////////////////////
			for(i=0;i<3;i++)
			{
				/////////////////////////////////////////////////
				EGyroFuzzy[0][i].InputFun(GyroError[i][0]);//E(k) 
				EGyroFuzzy[1][i].InputFun(GyroError[i][1]);//E(k+1)
				EFollowFuzzy[0][i].InputFun(FollowError[i][0]);//E(k)
				EFollowFuzzy[1][i].InputFun(FollowError[i][1]);//E(k+1)
			}
			for(i=0;i<3;i++)
			{
				for(j=0;j<3;j++)
				{
					////////////////////////////////////////////////////////
					//第一個變數為E(k+1)，第二個變數為E(k)
					//EBuffer1[0],EBuffer1[1],EBuffer1[2]分別為P,Q,R的E(k+1)
					//EBuffer2[0],EBuffer2[1],EBuffer2[2]分別為P,Q,R的E(k)
					EBuffer1[j]=EGyroFuzzy[1][i].SwInputMem[(j+1)];
					EBuffer2[j]=EGyroFuzzy[0][i].SwInputMem[(j+1)];
					///////////
					EBuffer3[j]=EFollowFuzzy[1][i].SwInputMem[(j+1)];
					EBuffer4[j]=EFollowFuzzy[0][i].SwInputMem[(j+1)];
					//////////
				}
				alpha[i]=OGyroFuzzy[i].FuzzyOutPut(&jj,EBuffer1,EBuffer2);
				beta[i]=OFollowFuzzy[i].FuzzyOutPut(&jj,EBuffer3,EBuffer4);
			}
			if(beta[1]>=0.5)
			{
				bGroError=true;	
			}
			else
			{
				bGroError=false;
			}
			fprintf(alphafile,"%f\t%f\t%f\n",alpha[0],alpha[1],alpha[2]);
			fprintf(betafile,"%f\t%f\t%f\n",beta[0],beta[1],beta[2]); 
			////////////////////////卡爾曼Init
			for(i=0;i<3;i++)
			{
				for(j=0;j<3;j++)
				{
					R1[i][j]=0.0f;
					Q1[i][j]=0.0f;
				}
			}
			Q1[0][0]=0.567f;//0.0099f;
			Q1[1][1]=0.567f;//0.0134f;
			Q1[2][2]=0.567f;//0.0117f;
			/*
			R1[0][0]=Q1[0][0];
			R1[1][1]=Q1[1][1];
			R1[2][2]=Q1[2][2];			
			*/
			R1[0][0]=Q1[0][0]/2.0f;
			R1[1][1]=Q1[1][1]/2.0f;
			R1[2][2]=Q1[2][2]/2.0f;
			
			EKF.Init(R1,Q1,bGroError);
			//////////////////////////////////////////////////////////////
			EKF_X[0]=phi1;
			EKF_X[1]=theta1;
			EKF_X[2]=psi1;
			///////////////////
			EKF_Z[0]=data1.roll;
			EKF_Z[1]=data1.pitch;
			EKF_Z[2]=data1.yaw;
			for(i=0;i<3;i++)
				for(j=0;j<3;j++)
				{
					alpha1[i][j]=0.0f;
					beta1[i][j]=0.0f;
					if(i==j)
					{
						alpha1[i][j]=alpha[i];
						beta1[i][j]=beta[i];
					}
				}
			EKF.comput(EKF_X,EKF_Z,alpha1,beta1);
			EKF.Output();
			fprintf(EKF_file1,"%f\n",EKF.y[0]); 
			fprintf(EKF_file2,"%f\n",EKF.y[1]);
			fprintf(EKF_file3,"%f\n",EKF.y[2]);
			//////////////////////////////////////////////////////////////////////
			for(i=0;i<3;i++)
			{
				GyroError[i][0]=GyroError[i][1];
				FollowError[i][0]=FollowError[i][1];
			}
			//////////////////////////////////////////////////////////////////////
			UpdateData(true);
				m_str1="網路啟動，等待客戶端連接!!!!!!!";
				m_v1=data1.roll;
				m_v2=data1.pitch;
				m_v3=data1.yaw;
			UpdateData(false);
			//////////////////////////////////////////////////
			ftime(&t1);
			fprintf(tp,"%d\t%d\n%d\t%d\n",t.time,t.millitm,t1.time,t1.millitm);
		}
    }
	//////////////////////////////////////////////////
	else
	{
		MessageBox("還未開卡");
	}
	CDialog::OnTimer(nIDEvent);
}

void CMemsGroServerDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
		m_str1="網路啟動，等待客戶端連接!!!!!!!";
	UpdateData(false);
	////////////////////////////////////////////網路程式
	sockListen.Create(6801,SOCK_STREAM,"140.134.32.77");
	//sockListen.Bind(6801,"140.134.32.74");
	sockListen.Listen(5);
	sockListen.Accept(m_sockSend);
	sockListen.Close();
	//////////////////////////////////////////////////////
	UpdateData(true);
		m_str1="網路啟動，客戶端連，開始接收資料!!!!!!!";
	UpdateData(false);
	SetTimer(1,10,NULL);//啟動ontimer
	////////////////////////////////////////////	
}
