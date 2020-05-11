// Fuzzy.cpp: implementation of the CFuzzy class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MemsGroServer.h"
#include "Fuzzy.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CFuzzy::CFuzzy()
{
	int i;
	for(i=0;i<5;i++)
	{
		SwInputMem[i]=0.0f;//由實際輸入值變成歸屬度的存放記憶體 LN SN Z SP LP
	}
	InputMem=0.0f;//實際輸入值變成歸屬度的實際輸出
	Input=0.0f;//輸入值
	In_out=100;
	out_rule=100;
	for(i=0;i<21;i++)
	{
		outdata[0][i]=float(i-10);
		outdata[1][i]=0.0f;
	}
	for(i=0;i<8;i++)
	{
		data[0][i]=0.0f;
		data[1][i]=0.0f;
	}

}

CFuzzy::~CFuzzy()
{

}
void CFuzzy::max3()
{
//SwInputMem[3];//由實際輸入值變成歸屬度的存放記憶體 Z P N
	if(SwInputMem[0]>=SwInputMem[1])
	{
		InputMem=SwInputMem[0];
		In_out=0;
	}
	else
	{
		InputMem=SwInputMem[1];
		In_out=1;
	}
	if(InputMem<SwInputMem[2])
	{
		InputMem=SwInputMem[2];
		In_out=2;
	}

}
void CFuzzy::InputZ()
{
	//SwInputMem[5];//由實際輸入值變成歸屬度的存放記憶體 LN SN Z SP LP
	float Z_a,Z_a1,Z_b,Z_b1;
	Z_a=-0.5f*2.0f;
	Z_a1=-2.0f*2.0f;
	Z_b=0.5f*2.0f;
	Z_b1=2.0f*2.0f;
	if(Z_a1>Input)//Input小於Z_a1
	{
		SwInputMem[2]=0.0f;
	}
	else if(Z_a1<=Input && Input< Z_a)//Input大於Z_a1 && Input小於Z_a
	{
		SwInputMem[2]=(Input-Z_a1)/(Z_a-Z_a1);
	}
	else if(Z_a<=Input && Input<=Z_b)//Input小於Z_b && Input大於Z_a
	{
		SwInputMem[2]=1.0f;
	}
	else if(Z_b<Input &&Input<=Z_b1 )//Input大於Z_b && Input小於Z_b
	{
		SwInputMem[2]=(Z_b1-Input)/(Z_b1-Z_b);
	}
	else if(Input>Z_b1)
	{
		SwInputMem[2]=0.0f;
	}
	else
	{
		SwInputMem[2]=0.0f;
	}

}
void CFuzzy::InputSP()
{
	//SwInputMem[5];//由實際輸入值變成歸屬度的存放記憶體 LN SN Z SP LP
	float SP_a,SP_a1,SP_b1;
	SP_a=2.0f*2.0f;
	SP_a1=0.0f*2.0f;
	//SP_b=0.5f;
	SP_b1=4.0f*2.0f;
	if(SP_a1>Input)
	{
		SwInputMem[3]=0.0f;
	}
	else if(SP_a1<=Input && Input< SP_a)
	{
		SwInputMem[3]=(Input-SP_a1)/(SP_a-SP_a1);
	}
	else if(Input>=SP_a)
	{
		SwInputMem[3]=1.0f;
	}
	/*
	else if(Input==SP_a)
	{
		SwInputMem[3]=1.0f;
	}
	else if(SP_a<Input && Input<= SP_b1)
	{
		SwInputMem[3]=(SP_b1-Input)/(SP_b1-SP_a);
	}
	else if(SP_b1<Input)
	{
		SwInputMem[3]=0.0f;
	}
	else
	{
		SwInputMem[3]=0.0f;
	}
	*/
}
void CFuzzy::InputLP()
{
		//SwInputMem[5];//由實際輸入值變成歸屬度的存放記憶體 LN SN Z SP LP
	float LP_a,LP_a1,LP_b;
	LP_a1=2.0f;
	LP_a=4.0f;
	LP_b=6.0f;
	if(LP_a1>Input)
	{
		SwInputMem[4]=0.0f;
	}
	else if(LP_a1<=Input && Input <LP_a)
	{
		SwInputMem[4]=(Input-LP_a1)/(LP_a-LP_a1);
	}
	else if(Input>=LP_a)
	{
		SwInputMem[4]=1.0f;
	}

}
void CFuzzy::InputSN()
{
	//SwInputMem[5];//由實際輸入值變成歸屬度的存放記憶體 LN SN Z SP LP
	float SN_a,SN_a1,SN_b1;
	SN_a=-2.0f*2.0f;
	SN_a1=-4.0f*2.0f;
	SN_b1=0.0f*2.0f;
	if(SN_b1<Input)
	{
		SwInputMem[1]=0.0f;
	}
	else if(SN_b1>=Input && Input > SN_a)
	{
		SwInputMem[1]=(SN_b1-Input)/(SN_b1-SN_a);
	}
	else if(Input<=SN_a)
	{
		SwInputMem[1]=1.0f;
	}
	/*
	else if(Input==SN_a)
	{
		SwInputMem[1]=1.0f;
	}
	else if(SN_a<Input && Input<= SN_b1)
	{
		SwInputMem[1]=(SN_b1-Input)/(SN_b1-SN_a);
	}
	else if(SN_b1<Input)
	{
		SwInputMem[1]=0.0f;
	}
	else
	{
		SwInputMem[1]=0.0f;
	}
	*/
}
void CFuzzy::InputLN()
{
		//SwInputMem[5];//由實際輸入值變成歸屬度的存放記憶體 LN SN Z SP LP
	float LN_a,LN_b1,LN_b;
	LN_b1=-2.0f;
	LN_a=-6.0f;
	LN_b=-4.0f;
	if(LN_b>=Input)
	{
		SwInputMem[0]=1.0f;
	}
	else if(LN_b<Input && Input <LN_b1)
	{
		SwInputMem[0]=(Input-LN_b)/(LN_b1-LN_b);
	}
	else if(Input>LN_b1)
	{
		SwInputMem[0]=0.0f;
	}

}
void CFuzzy::InputFun(float Input1)//把輸入的數字模糊化,他也是CFuzzy類別進入點
{
	//float out;
	Input=Input1;
	///////////////////////分別針對Input分類，個別做模糊化
	InputZ();
	InputSP();
	InputSN();
	//InputLP();
	//InputLN();
	/////////////////////

}
float CFuzzy::FuzzyOutPut(float *out,float *x,float *y)//把已模糊化的輸入，透過模糊規則，解模糊化，得到輸出,他也是CFuzzy類別進入點之一
{
	int i,j;
	float InArray1[5],InArray2[5];
	////////////////////////////////
	for(i=0;i<21;i++)
	{
		outdata[0][i]=float(i-10);
		outdata[1][i]=0.0f;
	}
	//////////////////////////////////
	for(i=0;i<5;i++)
	{
		InArray1[i]=*(x+i);//e(k+1)
		InArray2[i]=*(y+i);//e(k)
	}

	for(i=1;i<4;i++)
	{
		for(j=1;j<4;j++)
		{
			if(InArray1[i]!=0 && InArray2[j]!=0)
			{
				in1=InArray1[i];//e(k+1)
				in2=InArray2[j];//e(k)
				/////////////////////
				min2();
				//(*out)=fOut1;
				/////////////////////
				out_rule_switch(i,j);//依照輸入參數的不同，選擇適合的Rule
				comput_rule_out(out_rule,fOut1);//利用重心法解模糊化
			}
		}
	}
	comput_out();
	(*out)=fOut1;
	return fOut2;
}
void CFuzzy::min2()
{
	if(in1>in2)
		fOut1=in2;
	else
		fOut1=in1;

}
void CFuzzy::out_rule_switch(int a,int b)//依照輸入參數的不同，選擇適合的Rule
{
	//a=e(k+1)
	//b=e(k)
	//SN Z SP
	switch(b)//e(k)
	{
	case 1://小負
		if(a==1)//小負
		{
			out_rule=2;
		}
		else if(a==2)//Z
		{
			out_rule=1;
		}
		else if(a==3)//小正
		{
			out_rule=4;
		}
		break;
	case 2://Z
		if(a==1)//小負
		{
			out_rule=3;
		}
		else if(a==2)//Z
		{
			out_rule=0;
		}
		else if(a==3)//小正
		{
			out_rule=3;
		}
		break;
	case 3://小正
		if(a==1)//小負
		{
			out_rule=4;
		}
		else if(a==2)//Z
		{
			out_rule=1;
		}
		else if(a==3)//小正
		{
			out_rule=2;
		}
		break;
	}
}
void CFuzzy::comput_rule_out(int a,float b)//依照所產生的Rule，再配輸入，產生該輸出段落內，所相對應的歸屬度。
{
	//重心法
	//LN SN Z SP LP
	float LN_a,LN_b,LN_b1;
	float SN_a,SN_a1,SN_b1;
	float Z_a,Z_a1,Z_b1;
	float SP_a1,SP_a,SP_b1;
	float LP_a1,LP_a,LP_b;
	///////////////////////////
	sum1=0.0;
	sum2=0.0;
	int i,j;
	int number=0;
	float y=0.0;
	for(i=0;i<8;i++)
	{
		data[0][i]=0.0f;
		data[1][i]=0.0f;
	}
	switch(a)
	{
	case 0://LN
		j=0;
		/////////////////////////////
		LN_a=-9.9f;
		LN_b=-5.0f;
		LN_b1=-3.0f;
		for(i=int(LN_a);i<=LN_b1;i++)
		{
			if(i<LN_b)
			{
				y=1.0f;
			}
			else if( LN_b<i && i<=LN_b1 )
			{
				y=(i-LN_b)/(LN_b1-LN_b);
			}
			else if(i>LN_b1)
			{
				y=0.0f;
			}
			else
			{
				y=0.0f;
			}
			if(y>b)
			{
				y=b;
			}
			data[0][j]=float(i);
			data[1][j]=y;
			j++;
		}
		break;
	case 1://SN
		j=0;
		/////////////////////////////
		SN_a=-3.0f;
		SN_a1=-5.0f;
		SN_b1=0.0f;
		for(i=int(SN_a1);i<=SN_b1;i++)
		{
			if(SN_a1<=i && i<SN_a)
			{
				y=(i-SN_a1)/(SN_a-SN_a1);
			}
			else if(i==SN_a)
			{
				y=1.0f;
			}
			else if(SN_a<i && i<=SN_b1)
			{
				y=float((SN_b1-i)/(0.0-SN_a));
			}
			else if(i>SN_b1)
			{
				y=1.0f;
			}
			if(y>b)
			{
				y=b;
			}
			data[0][j]=float(i);
			data[1][j]=y;
			j++;
		}
		break;
	case 2://Z
		j=0;
		/////////////////////////////
		Z_a=0.0f;
		Z_a1=-1.0f;
		Z_b1=1.0f;
		for(i=int(Z_a1);i<=Z_b1;i++)
		{
			if( i<Z_a1 )
			{
				y=0.0;
			}
			else if(Z_a1<=i && i<Z_a)
			{
				y=(i-Z_a1)/(Z_a-Z_a1);
			}
			else if(i==Z_a)
			{
				y=1.0f;
			}
			else if(Z_a<i && i<=Z_b1)
			{
				y=(Z_b1-i)/(Z_b1-Z_a);
			}
			else if(i>Z_b1)
			{
				y=0.0f;
			}	
			if(y>b)
			{
				y=b;
			}
			data[0][j]=float(i);
			data[1][j]=y;
			j++;
		}
		break;
	case 3://SP
		j=0;
		////////////////////////////
		SP_a1=0.0f;
		SP_a=3.0f;
		SP_b1=5.0f;
		for(i=int(SP_a1);i<=SP_b1;i++)
		{
			if( i<SP_a1)
			{
				y=0.0;
			}
			else if(SP_a1<=i && i<SP_a)
			{
				y=(i-SP_a1)/(SP_a-SP_a1);
			}
			else if(i==SP_a)
			{
				y=1.0;
			}
			else if(SP_a<i && i<=SP_b1)
			{
				y=(SP_b1-i)/(SP_b1-SP_a);
			}
			else if(i>SP_b1)
			{
				y=0.0f;
			}	
			if(y>b)
			{
				y=b;
			}
			data[0][j]=float(i);
			data[1][j]=y;
			j++;
		}
		break;
	case 4://LP
		j=0;
		////////////////////////////
		LP_a1=3.0f;
		LP_a=5.0f;
		LP_b=9.9f;
		for(i=int(LP_a1);i<=LP_b;i++)
		{
			if(i<LP_a1)
			{
				y=0.0f;
			}
			else if(LP_a1<=i && i<LP_a)
			{
				y=(i-LP_a1)/(LP_a-LP_a1);
			}
			else if(i>LP_a)
			{
				y=1.0f;
			}
			if(y>b)
			{
				y=b;
			}
			data[0][j]=float(i);
			data[1][j]=y;
			j++;
		}
		break;
	}

	for(i=0;i<8;i++)
	{
		number=int(data[0][i]);
		number=number-(-11);
		if(outdata[1][number]<data[1][i])
		{
			outdata[1][number]=data[1][i];
		}		
	}


}
void CFuzzy::comput_out()//利用重心法解模糊化
{
	float NormalizeFactor;
	NormalizeFactor=0.1f;
	sum1=0.0f;
	sum2=0.0f;
	int i=0;
	for(i=0;i<21;i++)
	{
	sum1+=(outdata[0][i]*outdata[1][i]);
	sum2+=outdata[1][i];
	}
	if(sum2==0)
	{
		fOut2=0.0f;
	}
	else
	{
		fOut2=((sum1/sum2)*NormalizeFactor);
	}
}