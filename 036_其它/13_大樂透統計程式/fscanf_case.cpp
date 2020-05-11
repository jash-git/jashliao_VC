#include <stdio.h>
#include <iostream.h>
#include <stdlib.h>
#include <time.h>
void main()
{
	FILE *p;
	int a[7];//每一期號碼
	int i,k,j,temp[2],key;//氣排法變數
	int number[50];//存放每一個號碼出現次數
	int sol[50][2];//氣泡排序的結果。0為數字。1為次數
	int sum[50][2];//統計機率資料
	int intSwitch;//選取各數
	int SwitchNumber[7];
	for(i=0;i<50;i++)
		number[i]=0;
/////////////////////////////////
	p=fopen("開獎號碼.txt","r");//讀取開獎號碼
	while(fscanf(p,"%d%d%d%d%d%d%d",(a+0),(a+1),(a+2),(a+3),(a+4),(a+5),(a+6))!=EOF)
	{
		for(i=0;i<7;i++)
		{
			k=a[i];
			number[k]+=1;
		}
	}
///////////////////////////////
	for(i=0;i<50;i++)//初始排序前的資料
	{
		sol[i][0]=i;
		sol[i][1]=number[i];
	}
//////////////////////////////
	for(i=0;i<50;i++)//氣泡排序主體
	{
		key=0;
		for(j=0;j<50-i-1;j++)
		{
			if(sol[j][1]<sol[j+1][1])
			{
				temp[1]=sol[j][1];
				sol[j][1]=sol[j+1][1];
				sol[j+1][1]=temp[1];
				////////////////////////
				temp[0]=sol[j][0];
				sol[j][0]=sol[j+1][0];
				sol[j+1][0]=temp[0];
				key=1;
			}
		}
		if(key==0)
			break;
	}
//////////////////////////////
		for(k=0;k<50;k++)//顯示排序結果
			cout <<sol[k][0]<<"\t";
		cout <<"\n";
		for(k=0;k<50;k++)
			cout <<sol[k][1]<<"\t";
		cout <<"\n";
/////////////////////////////////
		for(k=0;k<50;k++)//統計機率資料初始化
		{
			sum[k][0]=0;//旗標
			sum[k][1]=0;//次數

		}
/////////////////////////////
		key=0;
int count=0;
		int index=0;
		int index1=0;
		for(k=0;k<50;k++)//統計機率主體
		{
			if(key!=sol[k][1])//次數不同
			{
				sum[index][0]=k;
				sum[index][1]+=1;
				key=sol[k][1];
				index++;
				count=0;
			}
			else
			{
				if(count==0)
				{
					index1=index;
					index1--;
					count++;
				}
				sum[index1][1]+=1;
			}
		}
//////////////////////////////////////////////
		for(k=0;k<50;k++)//顯示統計資料
			cout <<sum[k][0]<<"\t";
		cout <<"\n";
		for(k=0;k<50;k++)
			cout <<sum[k][1]<<"\t";
		cout <<"\n";
//////////////////////////////////////////
///*
intSwitch=7;//大樂透7個號碼
k=0;//讀取機率index
i=0;//讀取數字index
j=0;//填資料index
int Getnumber1,Getnumber2;//1為機率次數值，2為實際數字
int buffer1;
//SwitchNumber[6]
do
{
	Getnumber1=sum[k][1];
	
	if(intSwitch>=Getnumber1)
	{
		intSwitch-=Getnumber1;
		for(i=0;i<Getnumber1;i++)
		{
			buffer1=(i+sum[k][0]);
			Getnumber2=sol[buffer1][0];
			SwitchNumber[j]=Getnumber2;
			j++;
		}
	}
	else
	{
		int intRand;
		int *intRandBuffer;
		////////////////
		int l,y,m;
		intRandBuffer=new int[Getnumber1];
		for(l=0;l<Getnumber1;l++)
			*(intRandBuffer+l)=-1;
		m=0;//動態記憶體index
		////////////////
		do
		{
			srand((unsigned)time(NULL));//亂數種子初始化
			intRand=(rand()%(Getnumber1));//取出0到(Getnumber1-1)的亂數
			y=0;//判斷是否相同旗標
			for(l=0;l<Getnumber1;l++)
			{
				if(intRand!=*(intRandBuffer+l))
				{
					y=1;
				}
				else
				{
					y=0;
					break;
				}
			}
			if(y==1)
			{
				*(intRandBuffer+m)=intRand;
				m++;
				buffer1=(intRand+sum[k][0]);
				Getnumber2=sol[buffer1][0];
				SwitchNumber[j]=Getnumber2;
				j++;
				intSwitch--;
			}
		}while(intSwitch>0);
	}
	k++;	
}
while(intSwitch>0);
printf("OUTPut:%d\t%d\t%d\t%d\t%d\t%d\t%d\n",SwitchNumber[0],SwitchNumber[1],SwitchNumber[2],SwitchNumber[3],SwitchNumber[4],SwitchNumber[5],SwitchNumber[6]);
//*/
////////////////////////////////////////////
	fclose(p);
}