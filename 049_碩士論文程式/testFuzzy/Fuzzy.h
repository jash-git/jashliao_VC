// Fuzzy.h: interface for the CFuzzy class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FUZZY_H__56037543_7D7C_4D6C_8B48_3C6811DE349C__INCLUDED_)
#define AFX_FUZZY_H__56037543_7D7C_4D6C_8B48_3C6811DE349C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CFuzzy  
{
public:
	CFuzzy();
///////////////////////////////////////////////////////////////////////////
	//Input
	float SwInputMem[5];//由實際輸入值變成歸屬度的存放記憶體 Z P N
	float InputMem;//實際輸入值變成歸屬度的實際輸出
	int In_out;////(Z=0,P=1,N=2)
	float Input;//輸入值
	void InputFun(float Input1);//把輸入的數字模糊化,他也是CFuzzy類別進入點之一
////////////////////////////////////////////////////////////////////////////
	//out
	float in1,in2;//(Z=0,P=1,N=2)
	int out_rule;
	float fOut1;//輸出out的最大歸屬度
	float fOut2;//輸出out的實際值
	float FuzzyOutPut(float *out,float *x,float *y);//把已模糊化的輸入，透過模糊規則，解模糊化，得到輸出,他也是CFuzzy類別進入點之一
/////////////////////////////////////////////////////////////////////////////
	virtual ~CFuzzy();
private:
/////////////////////////////////////////////////////////////////////////
	//Input
	void InputZ();
	void InputSP();
	void InputSN();
	void InputLP();
	void InputLN();
	void max3();
///////////////////////////////////////////////////////////////////////
	void min2();
	void out_rule_switch(int a,int b);//依照輸入參數的不同，選擇適合的Rule。
	void comput_rule_out(int a,float b);//依照所產生的Rule，再配輸入，產生該輸出段落內，所相對應的歸屬度。
	void comput_out();//利用重心法解模糊化
	float data[2][8];//存放單一規則所運算出來每一個X所相對應的歸屬度。
	float outdata[2][21];// 21代表X有二十一個離散點
	float sum1,sum2;
//////////////////////////////////////////////////////////////////////
	
};

#endif // !defined(AFX_FUZZY_H__56037543_7D7C_4D6C_8B48_3C6811DE349C__INCLUDED_)
