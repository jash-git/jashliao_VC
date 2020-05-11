// Engrave32.cpp : 定義 DLL 的初始化常式。
//

#include "stdafx.h"
#include "Engrave32.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//
//TODO: 如果這個 DLL 是動態地對 MFC DLL 連結，
//		那麼從這個 DLL 匯出的任何會呼叫
//		MFC 內部的函式，都必須在函式一開頭加上 AFX_MANAGE_STATE
//		巨集。
//
//		例如:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// 此處為正常函式主體
//		}
//
//		這個巨集一定要出現在每一個
//		函式中，才能夠呼叫 MFC 的內部。這意味著
//		它必須是函式內的第一個陳述式
//		，甚至必須在任何物件變數宣告前面
//		，因為它們的建構函式可能會產生對 MFC
//		DLL 內部的呼叫。
//
//		請參閱 MFC 技術提示 33 和 58 中的
//		詳細資料。
//


// CEngrave32App

BEGIN_MESSAGE_MAP(CEngrave32App, CWinApp)
END_MESSAGE_MAP()


// CEngrave32App 建構
long EXPORTED_DLL_FUNCTION EngInitial(long lngBlockAmount,double tolerance,long Direction)//取得Block總數，並動態配置記憶體已用來存放每個Block的Entity數量
{
	long i;
	lngBlockNumber=lngBlockAmount;
	lngDirection=Direction;//0->順；1->逆
	if(lngBlockNumber<1)
		return 0;
	if(tolerance<=0)
		return 0;
	else
	{
		error=fopen("error.txt","w");
		data=fopen("data.txt","w");
		lngBlockData=new long[lngBlockNumber];
		for(i=0;i<lngBlockNumber;i++)
			lngBlockData[i]=-1;
		dblTolerance=tolerance;
		return 1;
	}
}
long EXPORTED_DLL_FUNCTION EngGetValue(EngarveElement *p,long lngBlock,long lngAmount)
//資料陣列指標；資料陣列屬於第幾個lngBlock；陣列大小
{
	long i,n;
	long lngtype,lngblock;
	long return1;
	n=lngAmount;
	lngblock=lngBlock;
	try
	{
		if(lngBlock<0)
			throw 0;
		if(lngAmount<=0)
			throw 1;
	}
	catch(int err)
	{
		if(err==0)
			fprintf(error,"資料沒有分群組\n");
		else
			fprintf(error,"陣列中沒有任何資料\n");
		return 0;
	}
	lngBlockData[lngblock]=n;
	gEE=p;
	Point3DCross=new CPoint3D[n]; 
	for(i=0;i<n;i++)
	{
		lngtype=(gEE+i)->Type;
		gInputData.Reset();
		if(lngtype==1)//Line
		{
			gInputData.m_lngBlock=lngblock;//用來儲存屬於哪個Block
			gInputData.m_lngEntity=i;//用來儲存屬於哪個Entity
			gInputData.m_lngLineArc=0;//用來儲存型態0->Line；1->Arc
			gInputData.CCW=(gEE+i)->CCW;//紀錄方向，0->右；1->左
			gInputData.Direction=lngDirection;//紀錄順逆，0->順；1->逆
			gInputData.m_Line.SetData((gEE+i)->X1,(gEE+i)->Y1,(gEE+i)->Z1,(gEE+i)->X2,(gEE+i)->Y2,(gEE+i)->Z2);
			Point3DCross[i]=gInputData.m_Line.m_EndPoint;
			fprintf(data,"第 %d block 第 %d 筆 : 為線資料，其相關資料為\t%f\t%f\t%f\t%f\t%f\t%f\n",lngblock,i,gInputData.m_Line.m_StartPoint.m_x,gInputData.m_Line.m_StartPoint.m_y,gInputData.m_Line.m_StartPoint.m_z,
				gInputData.m_Line.m_EndPoint.m_x,gInputData.m_Line.m_EndPoint.m_y,gInputData.m_Line.m_EndPoint.m_z);  
		}
		else if(lngtype==2)//Arc
		{
			gInputData.m_lngBlock=lngblock;//用來儲存屬於哪個Block
			gInputData.m_lngEntity=i;//用來儲存屬於哪個Entity
			gInputData.m_lngLineArc=1;//用來儲存型態0->Line；1->Arc
			gInputData.CCW=(gEE+i)->CCW;//紀錄方向，0->右；1->左
			gInputData.Direction=lngDirection;//紀錄順逆，0->順；1->逆
			CPoint3D P3DCenter((gEE+i)->X1,(gEE+i)->Y1,(gEE+i)->Z1); 
			gInputData.m_Arc.SetData(P3DCenter,(gEE+i)->X2,(gEE+i)->Y2,(gEE+i)->Z2);
			Point3DCross[i].m_x=P3DCenter.m_x+gInputData.m_Arc.m_fltR*cos(gInputData.m_Arc.m_fltEndAngle);   
			Point3DCross[i].m_y=P3DCenter.m_y+gInputData.m_Arc.m_fltR*sin(gInputData.m_Arc.m_fltEndAngle); 
			Point3DCross[i].m_z=P3DCenter.m_z+gInputData.m_Arc.m_fltR*0; 
			fprintf(data,"第 %d block 第 %d 筆 : 為弧資料，其相關資料為\t%f\t%f\t%f\t%f\t%f\t%f\n",lngblock,i,gInputData.m_Arc.m_Point3DCenter.m_x,gInputData.m_Arc.m_Point3DCenter.m_y,gInputData.m_Arc.m_Point3DCenter.m_z,
				gInputData.m_Arc.m_fltR,gInputData.m_Arc.m_fltStartAngle,gInputData.m_Arc.m_fltEndAngle);  
		}
		gArray.Add(gInputData);
	}
	return1=(long)gArray.GetSize(); 
	return return1;
}
long EXPORTED_DLL_FUNCTION EngLineLineSolve(const CInputData &BaseInputData,const CInputData &RipInputData,const CPoint3D &RipPoint3D,CCircle *AnsCircle)
{
	double ang1,ang2;
	long data1,data2;
	CCircleRightLeft CRL1,CRL2;
	CPoint3D p2;
	CCircle CC1,CC2;
	CLine Line;
	CPoint3D Point3D1,Point3D2; 
	CVector VectorBase,VectorRip;
	CLine BaseLine,RipLine;
	CPoint3D Point3DRip;
	BaseLine=BaseInputData.m_Line;
	RipLine=RipInputData.m_Line; 
	VectorBase.SetData(BaseLine.m_StartPoint,BaseLine.m_EndPoint);
	VectorRip.SetData(RipLine.m_StartPoint,RipLine.m_EndPoint);
	Point3DRip=RipPoint3D;
	CPointLine PL(VectorBase,Point3DRip,VectorRip);
	CC1.SetData(PL.GetCenter(0),PL.GetR(0));
	CC2.SetData(PL.GetCenter(1),PL.GetR(1));
	Line.SetData(BaseLine.m_StartPoint,BaseLine.m_EndPoint); 
	//data=CC1.CircleLine(Line,&ang1,&ang2,&Point3D1,&Point3D2);
	//if((data!=0) && (data!=3))
	data1=0;
	data2=0;
	if(CC1.CheckExcircle(Line)) 
	{
		data1=1;
	}
	if(CC2.CheckExcircle(Line))
	{
		data2=1;
	}
	/////////////////////////
	if((data1==1) && (data2==0))
	{
		AnsCircle->m_Point3DCenter=PL.GetCenter(0);
		AnsCircle->m_fltR=PL.GetR(0);
		return 1;
	}
	else if((data1==0) && (data2==1))
	{
		AnsCircle->m_Point3DCenter=PL.GetCenter(1);
		AnsCircle->m_fltR=PL.GetR(1);
		return 1;
	}
	else if((data1==1) && (data2==1))
	{
		CRL1.SetData(BaseInputData,CC1);
		CRL2.SetData(RipInputData,CC1);
		if(CRL1.Check() && CRL2.Check())
		{
			AnsCircle->m_Point3DCenter=PL.GetCenter(0);
			AnsCircle->m_fltR=PL.GetR(0);
			return 1;
		}
		else
		{
			CRL1.SetData(BaseInputData,CC2);
			CRL2.SetData(RipInputData,CC2);
			if(CRL1.Check() && CRL2.Check())
			{
				AnsCircle->m_Point3DCenter=PL.GetCenter(1);
				AnsCircle->m_fltR=PL.GetR(1);
				return 1;
			}
		}
	}
	else
	{
		/*
		Line.SetData(RipLine.m_StartPoint,RipLine.m_EndPoint);
		if(CC1.CheckExcircle(Line)) 
		{
			data1=1;
		}
		if(CC2.CheckExcircle(Line))
		{
			data2=1;
		}
		if((data1==1) && (data2==0))
		{
			AnsCircle->m_Point3DCenter=PL.GetCenter(0);
			AnsCircle->m_fltR=PL.GetR(0);
			return 1;
		}
		else if((data1==0) && (data2==1))
		{
			AnsCircle->m_Point3DCenter=PL.GetCenter(1);
			AnsCircle->m_fltR=PL.GetR(1);
			return 1;
		}
		*/
	}
	return 0;
}
long EXPORTED_DLL_FUNCTION EngLineArcSolve(const CArc &BaseArc,const CLine &RipLine,const CPoint3D &RipPoint3D,CCircle *AnsCircle)
{

	bool bolCircle=false;
	CArc ArcBase;
	CLine LineRip;
	CPoint3D Point3DRip;
	CCircle CircleBuf[2];
	ArcBase=BaseArc;
	LineRip=RipLine;
	Point3DRip=RipPoint3D;
	CPointArc PointArc(ArcBase,LineRip,Point3DRip);
	bolCircle=PointArc.GetCircle(CircleBuf);
	int a11=ArcBase.ArcCircle(CircleBuf[0]);
	int a12=ArcBase.ArcCircle(CircleBuf[1]);

	if((a11==1) && (a12==1))
	{
		if((CircleBuf[0].m_fltR>0)&&(CircleBuf[1].m_fltR>0))
		{
			if(CircleBuf[0].m_fltR>CircleBuf[1].m_fltR)
			{
				AnsCircle->m_fltR=CircleBuf[1].m_fltR;
				AnsCircle->m_Point3DCenter=CircleBuf[1].m_Point3DCenter; 
				return 1;
			}
			else
			{
				AnsCircle->m_fltR=CircleBuf[0].m_fltR;
				AnsCircle->m_Point3DCenter=CircleBuf[0].m_Point3DCenter;
				return 1;
			}
		}
		else if(CircleBuf[0].m_fltR>0)
		{
				AnsCircle->m_fltR=CircleBuf[0].m_fltR;
				AnsCircle->m_Point3DCenter=CircleBuf[0].m_Point3DCenter;
				return 1;
		}
		else if(CircleBuf[1].m_fltR>0)
		{
				AnsCircle->m_fltR=CircleBuf[1].m_fltR;
				AnsCircle->m_Point3DCenter=CircleBuf[1].m_Point3DCenter; 
				return 1;
		}
		else
		{
			return 0;
		}
	}
	else if(a11==1)
	{
			AnsCircle->m_fltR=CircleBuf[0].m_fltR;
			AnsCircle->m_Point3DCenter=CircleBuf[0].m_Point3DCenter;
			return 1;
	}
	else if(a12==1)
	{
			AnsCircle->m_fltR=CircleBuf[1].m_fltR;
			AnsCircle->m_Point3DCenter=CircleBuf[1].m_Point3DCenter; 
			return 1;
	}
	return 0;
}
long EXPORTED_DLL_FUNCTION EngArcLineSolve(const CLine &BaseLine,CArc &RipArc,const CPoint3D &RipPoint3D,CCircle *AnsCircle)
{
	bool bolcheck1=false;
	CCircle CircleBuf;
	CRipArcCircle RAP(BaseLine,RipArc,RipPoint3D);
	bolcheck1=RAP.GetCircle(&CircleBuf);
	if(bolcheck1==true)
	{
		int a11=RipArc.ArcCircle(CircleBuf);
		if(a11==1)
		{
			if(CircleBuf.m_fltR >0)
			{
				AnsCircle->m_fltR=CircleBuf.m_fltR;
				AnsCircle->m_Point3DCenter=CircleBuf.m_Point3DCenter; 				
				return 1;
			}
			else
			{
				return 0;
			}
		}
		else
		{
			return 0;
		}
	}
	else
	{
		return 0;
	}
}
long EXPORTED_DLL_FUNCTION EngArcArcSolve(const CArc &BaseArc,const CArc &RipArc,const CPoint3D &RipPoint3D,CCircle *AnsCircle)
{
	bool bolCircle=false;
	CArc ArcBase;
	CArc ArcRip;
	CPoint3D Point3DRip;
	CCircle CircleBuf[2];
	ArcBase=BaseArc;
	ArcRip=RipArc;
	Point3DRip=RipPoint3D;
	CPointArc PointArc(ArcBase,ArcRip,Point3DRip);
	bolCircle=PointArc.GetCircle(CircleBuf);
	int a11=ArcBase.ArcCircle(CircleBuf[0]);
	int a12=ArcBase.ArcCircle(CircleBuf[1]);
	if((a11==1) && (a12==1))
	{
		if((CircleBuf[0].m_fltR>0)&&(CircleBuf[1].m_fltR>0))
		{
			if(CircleBuf[0].m_fltR>CircleBuf[1].m_fltR)
			{
				AnsCircle->m_fltR=CircleBuf[1].m_fltR;
				AnsCircle->m_Point3DCenter=CircleBuf[1].m_Point3DCenter; 
				return 1;
			}
			else
			{
				AnsCircle->m_fltR=CircleBuf[0].m_fltR;
				AnsCircle->m_Point3DCenter=CircleBuf[0].m_Point3DCenter;
				return 1;
			}
		}
		else if(CircleBuf[0].m_fltR>0)
		{
				AnsCircle->m_fltR=CircleBuf[0].m_fltR;
				AnsCircle->m_Point3DCenter=CircleBuf[0].m_Point3DCenter;
				return 1;
		}
		else if(CircleBuf[1].m_fltR>0)
		{
				AnsCircle->m_fltR=CircleBuf[1].m_fltR;
				AnsCircle->m_Point3DCenter=CircleBuf[1].m_Point3DCenter; 
				return 1;
		}
		else
		{
			return 0;
		}
	}
	else if(a11==1)
	{
			AnsCircle->m_fltR=CircleBuf[0].m_fltR;
			AnsCircle->m_Point3DCenter=CircleBuf[0].m_Point3DCenter;
			return 1;
	}
	else if(a12==1)
	{
			AnsCircle->m_fltR=CircleBuf[1].m_fltR;
			AnsCircle->m_Point3DCenter=CircleBuf[1].m_Point3DCenter; 
			return 1;
	}
	return 0;
}
long EXPORTED_DLL_FUNCTION ArcParagraph(CArc &data,const double tolerance)
{
	long i,number;
	double L,R;
	double StartAngle,EndAngle,UnitAngle;
	CPoint3D Center;
	Center=data.m_Point3DCenter;
	StartAngle=data.m_fltStartAngle;
	EndAngle=data.m_fltEndAngle;
	R=data.m_fltR; 
	L=sqrt(pow((2.0*PI*R*(EndAngle-StartAngle)/(2.0*PI)),2));
	//L=2.0*PI*R*(EndAngle-StartAngle)/(2.0*PI);
	number=(long)(L/(tolerance*10))+1;
	if(number<=1)
		return 0;
	Point3DAns=new CPoint3D[number];
	UnitAngle=(EndAngle-StartAngle)*(tolerance*10)/L;
	for(i=0;i<number;i++)
	{
		Point3DAns[i].m_x=Center.m_x+R*cos((StartAngle+i*UnitAngle)); 
		Point3DAns[i].m_y=Center.m_y+R*sin((StartAngle+i*UnitAngle)); 
		Point3DAns[i].m_z=Center.m_z+R*0;		
		
		//Point3DAns[i].m_x=Center.m_x+R*cos(i*UnitAngle); 
		//Point3DAns[i].m_y=Center.m_y+R*sin(i*UnitAngle); 
		//Point3DAns[i].m_z=Center.m_z+R*0;
		
	}
	return number;
}
long EXPORTED_DLL_FUNCTION LineParagraph(CLine &data,const double tolerance)
{
	double L;
	long i,number;
	CVector Vector1;
	CPoint3D UnitVector1; 
	L=data.GetDistance();
	Vector1.SetData(data.m_StartPoint,data.m_EndPoint);
	UnitVector1=Vector1.GetUnitVector(); 
	number=(long)(L/(tolerance*20))+1;
	if(number<=1)
		return 0;
	Point3DAns=new CPoint3D[number];
	for(i=0;i<number;i++)
	{
		Point3DAns[i].m_x=data.m_StartPoint.m_x+i*(tolerance*20)*UnitVector1.m_x;
		Point3DAns[i].m_y=data.m_StartPoint.m_y+i*(tolerance*20)*UnitVector1.m_y;
		Point3DAns[i].m_z=data.m_StartPoint.m_z+i*(tolerance*20)*UnitVector1.m_z;
	}
	return number;
}
long EXPORTED_DLL_FUNCTION EngCalculate()
{
	long lngEntityNumber=0;//存放元件數量
	long lngParagraphNumber=0;//存放分段點的數量
	long i=0,j=0,k=0;//三層迴圈的旗標變數
	long lngAnsNumber=0;//求到刀具路徑定點的數量
	long lngCheck=0;//q042j04g.
	lngEntityNumber=(long)gArray.GetSize(); //取得元件數量
	CPoint3D Point3DBuffer;//分段點暫存器
	CInputData InputDataBuffer;//輸入物件暫存器
	CCircle CircleBuffer;//暫存求出來的圓形
	double **DynamicArrayR;//動態配置二維記憶體，用來儲存一個分段點所有的切圓半徑
	long l=0;//動態配置二維記憶體迴圈的旗標變數
	long m=0;//動態配置二維記憶體紀錄維度變數
	long n=0;//氣排法的回傳值，和取得排序完的結果
	CCircleRightLeft CRLBuf;//用來運算切圓是否在entity正確方向
	bool blnCRL=false;//用來儲存CRLBuf運算結果
	long lngcount=0;//用來儲存切圓與entity相交次數
	CNoSolution NSBuf;
	for(i=0;i<lngEntityNumber;i++)//(1)
	{
		gInputData.Reset();//先把暫存器資料清空
		gInputData=gArray[i];//依序取出每個entity
		if(gInputData.m_lngLineArc==0)//用來儲存型態0->Line；1->Arc)
		{
			lngParagraphNumber=LineParagraph(gInputData.m_Line,dblTolerance);//線求分段點
		}
		else
		{
			lngParagraphNumber=ArcParagraph(gInputData.m_Arc,dblTolerance);//圓弧求分段點
		}
		///////////////////////////////////////////////////////////////////
		for(j=0;j<lngParagraphNumber;j++)//把每個分段點依序求切圓//(2)
		{
			gArrayBuffer.RemoveAll();//先把暫存一個分段點與所有entity切圓CArray清空
			Point3DBuffer=Point3DAns[j];//依序把分段點取出 
			for(k=0;k<lngEntityNumber;k++)//依序和其他的entity作運算//(3)
			{
				if(i==k)
					continue;//同一個Entity不用算
				InputDataBuffer.Reset();//清空暫存器 
				InputDataBuffer=gArray[k];//取出相對的entity
				switch((gInputData.m_lngLineArc+InputDataBuffer.m_lngLineArc))//判萬要使用哪一個函數運算
				{
					case 0://0+0
						lngCheck=EngLineLineSolve(InputDataBuffer,gInputData,Point3DBuffer,&CircleBuffer);
						break;
					case 1://1+0,0+1
						if((gInputData.m_lngLineArc==0) && (InputDataBuffer.m_lngLineArc==1))//線與圓弧，且分段點是從線求出
						{
							lngCheck=EngLineArcSolve(InputDataBuffer.m_Arc,gInputData.m_Line,Point3DBuffer,&CircleBuffer);
						}
						else//線與圓弧，且分段點是從圓弧求出
						{
							lngCheck=EngArcLineSolve(InputDataBuffer.m_Line,gInputData.m_Arc,Point3DBuffer,&CircleBuffer);
						}
						break;
					case 2://1+1
						lngCheck=EngArcArcSolve(InputDataBuffer.m_Arc,gInputData.m_Arc,Point3DBuffer,&CircleBuffer);
						break;
				}
				if(lngCheck!=0)//確認且圓不和其他entity相交
				{
					for(long q=0;q<lngEntityNumber;q++)
					{
						if((q!=k) && (q!=i))
						{
								InputDataBuffer.Reset();//清空暫存器 
								InputDataBuffer=gArray[q];//取出相對的entity
								if(InputDataBuffer.m_lngLineArc==0)//用來儲存型態0->Line；1->Arc)
								{//0->Line
									double angle1,angle2;
									CPoint3D P3D1,P3D2;
									int Ansnumber;
									Ansnumber=CircleBuffer.CircleLine(InputDataBuffer.m_Line,&angle1,&angle2,&P3D1,&P3D2);
									/*
									if(Ansnumber!=0)
									{
										lngCheck=0;
										break;
									}
									//*/
									///*
									if(Ansnumber==3)//線段在圓內
									{//
										lngCheck=0;
										lngcount=0;
										break;
									}
									else if(Ansnumber==2)//有兩個交點
									{
										CLine Line2d;
										Line2d.SetData(P3D1,P3D2); 
										if(Line2d.GetDistance()>0.1)//判斷兩個交點是否為同一個
										{
											lngCheck=0;
											lngcount=0;
											break;
										}
										else//兩交點為同一個
										{
											lngcount++;
											if(CircleBuffer.CheckExcircle(InputDataBuffer.m_Line)==false)
											{
												lngCheck=0;
												lngcount=0;
												break;
											}
											if(lngcount>1)
											{
												lngCheck=0;
												lngcount=0;
												break;
											}
										}
									}
									else if(Ansnumber==1)
									{
										lngcount++;
										if(CircleBuffer.CheckExcircle(InputDataBuffer.m_Line)==false)
										{
											lngCheck=0;
											lngcount=0;
											break;
										}
										if(lngcount>1)
										{
											lngCheck=0;
											lngcount=0;
											break;
										}
									}
									//*/
								}
								else
								{//1->Arc
									int Ansnumber;
									CCircle Arc2Circle;
									double angbuf1,angbuf2;
									Arc2Circle.SetData(InputDataBuffer.m_Arc.m_Point3DCenter,InputDataBuffer.m_Arc.m_fltR);   
									Ansnumber=Arc2Circle.CircleCircle(CircleBuffer,&angbuf1,&angbuf2); 
									if(Ansnumber==10 )
									{
										lngCheck=0;
										break;
									}
									else if(Ansnumber==2)
									{
										double m_fltStartAngle,m_fltEndAngle;
										bool checkang1=false,checkang2=false;
										if(angbuf1<0)
											angbuf1=angbuf1+PI*2.0;
										if(angbuf2<0)
											angbuf2=angbuf2+PI*2.0;
										m_fltStartAngle=InputDataBuffer.m_Arc.m_fltStartAngle; 
										m_fltEndAngle=InputDataBuffer.m_Arc.m_fltEndAngle; 
										if((m_fltStartAngle<m_fltEndAngle && angbuf1<=m_fltEndAngle && angbuf1>=m_fltStartAngle)
											||(m_fltStartAngle>m_fltEndAngle && angbuf1<=m_fltStartAngle && angbuf1>=m_fltEndAngle))
											checkang1=true;
										if((m_fltStartAngle<m_fltEndAngle && angbuf2<=m_fltEndAngle && angbuf2>=m_fltStartAngle)
											||(m_fltStartAngle>m_fltEndAngle && angbuf2<=m_fltStartAngle && angbuf2>=m_fltEndAngle))
											checkang2=true;
										if(checkang2==true || checkang1==true)
										{
											lngCheck=0;
											break;
										}
									}
									Ansnumber=InputDataBuffer.m_Arc.ArcCircle(CircleBuffer);
									if(Ansnumber!=0)
									{
										lngCheck=0;
										break;
									}								
								}
						}
						else
						{
								int Ansnumber;
								InputDataBuffer.Reset();//清空暫存器 
								InputDataBuffer=gArray[q];//取出相對的entity
								if(InputDataBuffer.m_lngLineArc==1)
								{
									CCircle Arc2Circle;
									double angbuf1,angbuf2;
									Arc2Circle.SetData(InputDataBuffer.m_Arc.m_Point3DCenter,InputDataBuffer.m_Arc.m_fltR);
									Ansnumber=CircleBuffer.CircleCircle(Arc2Circle,&angbuf1,&angbuf2);
									if(Ansnumber==20||Ansnumber==21)
									{
										lngCheck=0;
										break;
									}
									else if((Ansnumber==10||Ansnumber==11)&& (fabs(CircleBuffer.m_fltR-Arc2Circle.m_fltR)<0.001))
									{
										lngCheck=0;
										break;
									}
								}
								else
								{
									bool CheckEx=false;
									CheckEx=CircleBuffer.CheckExcircle(InputDataBuffer.m_Line);
									if(CheckEx==false)
									{
										lngCheck=0;
										break;
									}
								}
						}
					}
				}
				///*
				if(lngCheck!=0)
				{
					InputDataBuffer.Reset();//清空暫存器 
					InputDataBuffer=gArray[i];//取出相對的entity
					blnCRL=false;//清除上一次運算結果
					CRLBuf.SetData(InputDataBuffer,CircleBuffer);
					blnCRL=CRLBuf.Check();
					if(blnCRL==false)
					{
						lngCheck=0;
					}
					else
					{
						InputDataBuffer.Reset();//清空暫存器 
						InputDataBuffer=gArray[k];//取出相對的entity
						blnCRL=false;//清除上一次運算結果
						CRLBuf.SetData(InputDataBuffer,CircleBuffer);
						blnCRL=CRLBuf.Check();
						if(blnCRL==false)
						{
							lngCheck=0;
						}
					}
				}
				//*/
				if(lngCheck!=0)//如果沒有切圓，則不用紀錄
					gArrayBuffer.Add(CircleBuffer);
				long debug1=(long)(gArrayAns.GetSize());
			}//(3)
			m=(long)(gArrayBuffer.GetSize());//抓出一個分段點有幾切圓
			if(m<=0)
			{
				InputDataBuffer.Reset();//清空暫存器 
				InputDataBuffer=gArray[i];//取出相對的entity
				NSBuf.SetData(InputDataBuffer,i,Point3DBuffer,Point3DCross,lngEntityNumber);
				if(NSBuf.GetAns(&CircleBuffer)) 
					gArrayBuffer.Add(CircleBuffer);
			}
			m=(long)(gArrayBuffer.GetSize());//抓出一個分段點有幾切圓
			if(m>0)
			{
				DynamicArrayR=new double *[m];//動態配置記憶體
				for(l=0;l<m;l++)
					DynamicArrayR[l]=new double [2];
				for(l=0;l<m;l++)//設定動態配置記憶體的值
				{
					DynamicArrayR[l][0]=l;
					CircleBuffer=gArrayBuffer[l];
					DynamicArrayR[l][1]=CircleBuffer.m_fltR; 
				}
				n=BubbleSort(DynamicArrayR,m);//氣泡排序
				n=(long)(DynamicArrayR[0][0]);//取出最小半徑的旗標
				CircleBuffer=gArrayBuffer[n];//取出最小半徑的切圓
				gArrayAns.Add(CircleBuffer);//儲存最小半徑的切圓 
				for(l=0;l<m;l++)//釋放動態二維記憶體
					delete [] DynamicArrayR[l];
				delete [] DynamicArrayR;
			}
		}//(2)
		delete [] Point3DAns;//釋放動態一維記憶體
	}//(1)
	lngAnsNumber=gArrayAns.GetSize(); 
	delete [] Point3DCross;
	return lngAnsNumber;
}
long EXPORTED_DLL_FUNCTION BubbleSort(double **p,long n)
{
	long i,j,key;
	double temp,temp1;
	if(n<=0)
		return 0;
	for(i=0;i<n;i++)
	{
		key=0;
		for(j=0;j<(n-i-1);j++)
		{
			if(p[j][1]>p[j+1][1])
			{
				temp1=p[j][1];
				p[j][1]=p[j+1][1];
				p[j+1][1]=temp1;
				///////////////////////////////
				temp=p[j][0];
				p[j][0]=p[j+1][0];
				p[j+1][0]=temp;
				key=1;
			}
		}
		if(key==0)
			break;
	}	
	return 1;
}
CEngrave32App::CEngrave32App()
{
	// TODO: 在此加入建構程式碼，
	// 將所有重要的初始設定加入 InitInstance 中
}


// 僅有的一個 CEngrave32App 物件

CEngrave32App theApp;


// CEngrave32App 初始設定

BOOL CEngrave32App::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}
