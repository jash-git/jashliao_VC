//patternView.cpp

#include "stdafx.h"
#include "pattern.h"

#include "patternDoc.h"
#include "patternView.h"
#include "InputDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#include<windows.h>
#include<math.h>

#define startX 8  //ģ������X���
#define startY 8  //ģ������Y���
#define stepX 11  //X����ÿ��ĳ���
#define stepY 15  //Y����ÿ��ĳ���
int disable=0;


/////////////////////////////////////////////////////////////////////////////
// CPatternView

IMPLEMENT_DYNCREATE(CPatternView, CView)

BEGIN_MESSAGE_MAP(CPatternView, CView)
	//{{AFX_MSG_MAP(CPatternView)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPatternView construction/destruction

CPatternView::CPatternView()
{
	// TODO: add construction code here
	mouseDown=0;

	//��ʼ����ʹ��ÿ�����Ϊ�׵�
	for(int i=0;i<16;i++)
		for(int j=0;j<16;j++)
			bitgraph[i][j]=0;

	//��ʼ����ʹ�����������еĵ��Ϊ�յ�
	mytime=0;
	for(i=0;i<100;i++){
		mypoint[i].x=-1;
		mypoint[i].y=-1;
	}

	mytime=0;
	curvalue=-1;
	mytezheng=(TEZHENG *)malloc(sizeof(TEZHENG));
	mytezheng->value=-1;
	mytezheng->lenth=0;
	mytezheng->lenth1=0;
	for(i=0;i<15;i++)
		mytezheng->VHDerection[i]=-1;
	mytezheng->decon=0;

	//�򿪱���ģ�����������ļ�
	if(cf.Open("mydata.dat",CFile::modeCreate|CFile::modeNoTruncate|CFile::modeReadWrite)==NULL){
		AfxMessageBox("���ļ�ʧ�ܣ�\n������˳�����");
	}
}

CPatternView::~CPatternView()
{
	cf.Close();
}

BOOL CPatternView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CPatternView drawing

void CPatternView::OnDraw(CDC* pDC)
{
	CPatternDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	//������ϵͳ�ı���
	//Erase the background
	// Create a pruple brush.
	CBrush Brush (RGB (128, 0 , 0) );
	// Select the brush into the device context .
	CBrush* pOldBrush = pDC->SelectObject (&Brush);
	// Get the area that needs to be erased .
	CRect rcClip;
	pDC->GetClipBox (&rcClip);
	//Paint the area.
	pDC-> PatBlt (rcClip.left , rcClip.top , rcClip.Width ( ) , rcClip.Height( ) , PATCOPY );
	//Unselect brush out of device context .
	
	pDC->SelectObject (pOldBrush );

	//�ĸ�ģ��λͼ��ť
	CBitmap bitmapstudy,bitmaprecognize,bitmapclear,bitmaphelp; // Sequence is important
    CDC dcMemory1,dcMemory2,dcMemory3,dcMemory4;

    bitmapstudy.LoadBitmap(IDB_BITMAP_STUDY);
    dcMemory1.CreateCompatibleDC(pDC);
    dcMemory1.SelectObject(&bitmapstudy);
    pDC->BitBlt(220, 20, 50, 20, &dcMemory1, 0, 0, SRCCOPY);

	bitmaprecognize.LoadBitmap(IDB_BITMAP_RECOGNIZE);
    dcMemory2.CreateCompatibleDC(pDC);
    dcMemory2.SelectObject(&bitmaprecognize);
    pDC->BitBlt(220, 60, 50, 20, &dcMemory2, 0, 0, SRCCOPY);

	bitmapclear.LoadBitmap(IDB_BITMAP_CLEAR);
    dcMemory3.CreateCompatibleDC(pDC);
    dcMemory3.SelectObject(&bitmapclear);
    pDC->BitBlt(220, 100, 50, 20, &dcMemory3, 0, 0, SRCCOPY);

	bitmaphelp.LoadBitmap(IDB_BITMAP_HELP);
    dcMemory4.CreateCompatibleDC(pDC);
    dcMemory4.SelectObject(&bitmaphelp);
    pDC->BitBlt(220,140, 50, 20, &dcMemory4, 0, 0, SRCCOPY);

	//����
	CBrush BrushBoard (RGB (255, 255 , 255) );
	// Select the brush into the device context .
	pOldBrush = pDC->SelectObject (&BrushBoard);
	//Paint the area.
	pDC-> PatBlt (8,8,176,240, PATCOPY );
	//Unselect brush out of device context 
    pDC->SelectObject (pOldBrush );
	pDC->SetTextColor(RGB(255,255,255));
	pDC->SetTextAlign(TA_CENTER|TA_TOP);
	pDC->SetBkMode(TRANSPARENT);
	pDC->TextOut(245,175,"��������");
	pDC->TextOut(245,200,"д��һ��");
	pDC->TextOut(245,225,"  �Ǻǣ�");
}

/////////////////////////////////////////////////////////////////////////////
// CPatternView printing

BOOL CPatternView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CPatternView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CPatternView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CPatternView diagnostics

#ifdef _DEBUG
void CPatternView::AssertValid() const
{
	CView::AssertValid();
}

void CPatternView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPatternDoc* CPatternView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPatternDoc)));
	return (CPatternDoc*)m_pDocument;
}
#endif //_DEBUG

//�����µ��������ͣ��Լ���ģ���ļ���
void CPatternView::OnStudy(void)
{
	//��������ֵ�ĶԻ���
	InputDialog inputdlg;
	cf.SeekToBegin();
	int nFileSize=cf.GetLength();
	int i=nFileSize/sizeof(TEZHENG);
	TEZHENG *temp;
	temp=(TEZHENG *)malloc(sizeof(TEZHENG));

	//���㵱ǰ���������ֵ�����ֵ
	GetTeZheng();

	//�����жϵ�ǰ�����������Ƿ��Ѿ���ģ����
	for(int j=0;j<i;j++){
		cf.Read((void *)temp,sizeof(TEZHENG));
		for(int k=0;k<15;k++){
			if(temp->VHDerection[k]!=mytezheng->VHDerection[k])
				break;
		}
		if((k==15)&&(temp->decon==mytezheng->decon)&&(temp->lenfirst==mytezheng->lenfirst)&&(temp->lenth1==mytezheng->lenth1)&&(temp->lenth==mytezheng->lenth)&&(temp->lenend==mytezheng->lenend)){
			char s[20];
			sprintf(s,"��������ǣ�%d����������",temp->value);
			AfxMessageBox(s);
			break;
		}
	}
	//˵�����������Ͳ���ģ����
	if(j==i){
		if(inputdlg.DoModal()==IDOK){
			//�ж���������Ի����е����������Ƿ���ͬ
			if(inputdlg.m_value1!=inputdlg.m_value2){
				AfxMessageBox("������������\n����������");
			}
			//��ͬ�����µ���������д��ģ���ļ���
			else{
				GetTeZheng();
				try{
					mytezheng->value=inputdlg.m_value1;
					cf.SeekToEnd();
					cf.Write(&mytezheng->value,sizeof(signed char));
					cf.Write(mytezheng->VHDerection,sizeof(signed char)*15);
					cf.Write(&mytezheng->lenth1,sizeof(signed char));
					cf.Write(&mytezheng->lenth,sizeof(signed char));
					cf.Write(&mytezheng->decon,sizeof(signed char));
					cf.Write(&mytezheng->lenfirst,sizeof(signed char));
					cf.Write(&mytezheng->lenend,sizeof(signed char));
				}
				catch(CFileException *e){
					//Alert user to error
					e->Delete();
				}//end try-catch
			}//end if-else
		}//end if
	}//end if

	OnClear();

	return;
}

//ʶ����
void CPatternView::OnRecognize(void)
{
	cf.SeekToBegin();
	int nFileSize=cf.GetLength();
	int i=nFileSize/sizeof(TEZHENG);
	TEZHENG *temp;
	temp=(TEZHENG *)malloc(sizeof(TEZHENG));
	//��������ֵ
	GetTeZheng();

	//��ģ���ļ���Ѱ�ң��Ƿ����뵱ǰ����ֵ��ͬ��
	for(int j=0;j<i;j++){
		cf.Read((void *)temp,sizeof(TEZHENG));
		for(int k=0;k<15;k++){
			if(temp->VHDerection[k]!=mytezheng->VHDerection[k])
				break;
		}
		//�ҵ�ʶ����
		if((k==15)&&(temp->decon==mytezheng->decon)&&(temp->lenfirst==mytezheng->lenfirst)&&(temp->lenth1==mytezheng->lenth1)&&(temp->lenth==mytezheng->lenth)&&(temp->lenend==mytezheng->lenend)){
			char s[20];
			sprintf(s,"��������ǣ�%d",temp->value);
			AfxMessageBox(s);
			break;//��������
		}
	}
	if(j==i){
		AfxMessageBox("��Ǹ���޷�ʶ��");
	}

	OnClear();

	return;
}

//��ջ���
void CPatternView::OnClear(void)
{
	CDC *pDC=GetDC();

	CBrush BrushBoard (RGB (255, 255 , 255) );
	CBrush pOldBrush;
	pDC-> PatBlt (8,8,176,240, PATCOPY );

	for(int i=0;i<16;i++)
		for(int j=0;j<16;j++)
			bitgraph[i][j]=0;

	mouseDown=0;
	mytime=0;
	for(i=0;i<100;i++){
		mypoint[i].x=-1;
		mypoint[i].y=-1;
	}
	
	curvalue=-1;
	mytezheng->value=-1;
	mytezheng->lenth=0;
	mytezheng->lenth1=0;
	for(i=0;i<15;i++)
		mytezheng->VHDerection[i]=-1;
	mytezheng->decon=0;

	return;
}

void CPatternView::OnMyHelp(void)
{
	return;
}

///////////////////////////////////////////////////////////////////////////
//���������������ȡ����
void CPatternView::GetTeZheng()
{
	int p,q;
	int i=0;
	//�ӵ�һ���㵽���һ����
	for(int j=0;j<mytime-1;j++){
		if(i==0){
			mytezheng->lenth1++;
		}
		if(i>=13){
			AfxMessageBox("�ڴ�������Ǻ�",NULL,NULL);
			return;
		}
		
		//�ж��������ڵ�ľ���
		p=(mypoint[j+1].x-mypoint[j].x)*(mypoint[j+1].x-mypoint[j].x);
		q=(mypoint[j+1].y-mypoint[j].y)*(mypoint[j+1].y-mypoint[j].y);
		//�������8���ӣ���Ϊ���ѵ������д��̫��
		if((p>1)||(q>1)){
			mytezheng->decon=1;
			j++;
			i++;
			if(j+1>mytime-1){
				AfxMessageBox("������д��̫���ˣ��Ǻ�",NULL,NULL);
				return;
			}
			if(mypoint[j+1].x>mypoint[j].x)
				mytezheng->VHDerection[i]=1;
			else if(mypoint[j+1].y>mypoint[j].y)
				mytezheng->VHDerection[i]=2;
			else if(mypoint[j+1].x<mypoint[j].x)
				mytezheng->VHDerection[i]=3;
			else
				mytezheng->VHDerection[i]=4;
				
			mytezheng->lenth=1;	
		}

		//��������Ŀǰ�ķ���
		else{
			if(j==0){
				if(mypoint[1].x>mypoint[0].x)
					mytezheng->VHDerection[0]=1;
				else if(mypoint[1].y>mypoint[0].y)
					mytezheng->VHDerection[0]=2;
				else if(mypoint[1].x<mypoint[0].x)
					mytezheng->VHDerection[0]=3;
				else
					mytezheng->VHDerection[0]=4;
				
				mytezheng->lenth=1;
			}//end if
			else{
				switch(mytezheng->VHDerection[i]){
				case 1:
					if(mypoint[j+1].x<=mypoint[j].x){
						i++;
						mytezheng->lenth=1;
						if(mypoint[j+1].y>mypoint[j].y)
							mytezheng->VHDerection[i]=2;
						else if(mypoint[j+1].y<mypoint[j].y)
							mytezheng->VHDerection[i]=4;
						else
							mytezheng->VHDerection[i]=3;
					}
					else
						mytezheng->lenth++;
					break;
				case 2:
					if(mypoint[j+1].y<=mypoint[j].y){
						i++;
						mytezheng->lenth=1;
						if(mypoint[j+1].x<mypoint[j].x)
							mytezheng->VHDerection[i]=3;
						else if(mypoint[j+1].x>mypoint[j].x)
							mytezheng->VHDerection[i]=1;
						else
							mytezheng->VHDerection[i]=4;
					}
					else
						mytezheng->lenth++;
					break;
				case 3:
					if(mypoint[j+1].x>=mypoint[j].x){
						i++;
						mytezheng->lenth=1;
						if(mypoint[j+1].y<mypoint[j].y)
							mytezheng->VHDerection[i]=4;
						else if(mypoint[j+1].y>mypoint[j].y)
							mytezheng->VHDerection[i]=2;
						else
							mytezheng->VHDerection[i]=1;
					}
					else
						mytezheng->lenth++;
					break;
				case 4:
					if(mypoint[j+1].y>=mypoint[j].y){
						i++;
						mytezheng->lenth=1;
						if(mypoint[j+1].x>mypoint[j].x)
							mytezheng->VHDerection[i]=1;
						else if(mypoint[j+1].x<mypoint[j].x)
							mytezheng->VHDerection[i]=3;
						else
							mytezheng->VHDerection[i]=2;
					}
					else
						mytezheng->lenth++;
					break;
				default:
					break;
				}//end switch
			}//end else
		}//end else
	}//end for
	for(p=0;p<4;p++){
		for(q=p+1;q<mytime;q++){
			if(mypoint[p]==mypoint[q])
				break;
		}
		if(q<mytime)
			break;
	}
	if(p>=4)
		mytezheng->lenfirst=2;
	else
		mytezheng->lenfirst=1;

	for(p=mytime-1;p>mytime-6;p--){
		for(q=p-1;q>=0;q--){
			if(mypoint[p]==mypoint[q])
				break;
		}
		if(q>=0)
			break;
	}
	if(p<=mytime-6)
		mytezheng->lenend=2;
	else
		mytezheng->lenend=1;

	if((mytezheng->lenth)>0&&(mytezheng->lenth)<=4)
		mytezheng->lenth=1;
	else
		mytezheng->lenth=2;

	if(mytezheng->lenth1>=4)
		mytezheng->lenth1=2;
	else
		mytezheng->lenth1=1;
}//end fuction GetTeZheng()


/////////////////////////////////////////////////////////////////////////////
// CPatternView message handlers
//ģ�ⰴť�¼�
//ͨ���ж������������¼��������ĸ��������жϸô����ĸ�����
void CPatternView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	mouseDown=1;
	
	if((point.x>=220)&&(point.x<270)&&(point.y>=20)&&(point.y<40)){
		OnStudy();
	}

	if((point.x>=220)&&(point.x<270)&&(point.y>=60)&&(point.y<80)){
		OnRecognize();
	}

	if((point.x>=220)&&(point.x<270)&&(point.y>=100)&&(point.y<120)){
		OnClear();
	}

	if((point.x>=220)&&(point.x<270)&&(point.y>=140)&&(point.y<160)){
		OnMyHelp();
	}

	CView::OnLButtonDown(nFlags, point);
}

//����ƶ��¼���ģ����д������
void CPatternView::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	CDC *pDC=GetDC();
	CRgn Rgn;

	//��������������ķ�Χ��
	Rgn.CreateRectRgn(startX,startY,startX+stepX*16-1,startY+stepY*16-1);
	pDC->SelectClipRgn(&Rgn);
	if((point.x>=startX)&&(point.x<startX+stepX*16)&&(point.y>=startY)&&(point.y<startY+stepY*16)){
		HCURSOR m_HCross;
		m_HCross=AfxGetApp()->LoadStandardCursor(IDC_CROSS);
		::SetCursor(m_HCross);
	}
	int i=(point.x-startX)/stepX;
	int j=(point.y-startY)/stepY;
	if((mouseDown==1)&&(point.x>=startX)&&(point.x<startX+stepX*16)&&(point.y>=startY)&&(point.y<startY+stepY*16)){
		CBrush Brush (RGB (0, 0 , 0) );
		// Select the brush into the device context .
		CBrush* pOldBrush = pDC->SelectObject (&Brush);
		pDC->Ellipse(point.x-6,point.y-6,point.x+6,point.y+6);
		pDC->SelectObject (pOldBrush );
		//��������
	
		if(mytime>=100){
			AfxMessageBox("�ڴ����(��ͼʱ)",NULL,NULL);
			OnClear();
		}

		if(mytime==0){
			mypoint[mytime].x=i;
			mypoint[mytime].y=j;
			oldpoint=mypoint[mytime];
			mytime++;
		}
		//����������ж�̬��ȥ��ֱ�ǵ�
		else{
			if((i!=oldpoint.x)||(j!=oldpoint.y)){
				int k,n;
				if(mytime<2){
					k=0;
					n=0;
				}
				else{
					k=(i-mypoint[mytime-2].x)*(i-mypoint[mytime-2].x);
					n=(j-mypoint[mytime-2].y)*(j-mypoint[mytime-2].y);
				}
				if((k==1)&&(n==1)){
					mypoint[mytime-1].x=i;
					mypoint[mytime-1].y=j;
					oldpoint=mypoint[mytime-1];
				}
				//disable=1;
				else{
					mypoint[mytime].x=i;
					mypoint[mytime].y=j;
					oldpoint=mypoint[mytime];
					mytime++;
				}
			}
		}
		bitgraph[i][j]=1;
	}

	CView::OnMouseMove(nFlags, point);
}

//������̧��
void CPatternView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	//����mouseDownΪfalse
	mouseDown=0;
	CView::OnLButtonUp(nFlags, point);
}
