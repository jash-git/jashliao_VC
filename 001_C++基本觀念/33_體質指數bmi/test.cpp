#include <iostream>
using namespace std;
void main()
{
	float fltKG,fltCM,yourbmi;
	cout<<"計算BMI請輸入體重(kg)"<<"\t";
	cin>>fltKG;
	cout<<"計算BMI請輸入身高(cm)"<<"\t";
	cin>>fltCM;
	yourbmi=fltKG/((fltCM/100)*(fltCM/100));
	if(yourbmi >50)//->"胖到死"
	{
		cout<<"胖到死";
	}
	else if(yourbmi >=30) //->"Ⅱ度肥胖"
	{
		cout<<"Ⅱ度肥胖";
	}
	else if(yourbmi >24.99 && yourbmi <=29.9) //->"Ⅰ度肥胖"
	{
		cout<<"Ⅰ度肥胖";
	}
	else if(yourbmi >=18.5 && yourbmi <=22.9) //->"正常"
	{
		cout<<"正常";
	}
	else if(yourbmi >=17.0 && yourbmi <18.5) //->"輕度消瘦"
	{
		cout<<"輕度消瘦";
	}
	else if(yourbmi >=16 && yourbmi <16.9) //->"中度消瘦"
	{
		cout<<"中度消瘦";
	}
	else if(yourbmi <16) //->"重度消瘦"
	{
		cout<<"重度消瘦";
	}
	else if(yourbmi <5) //->"羽化成仙"
	{
		cout<<"羽化成仙";
	}
}