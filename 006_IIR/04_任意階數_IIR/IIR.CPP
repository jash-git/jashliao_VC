#include <stdio.h>
float *fInputFactor,*fOutputFactor;
float *fInputData,*fOutputData;
int number_Out,number_In;
void Shift_Arry(int n,float *data);
void CalculateOutput();
FILE *f;
void main()
{
	int i,j;
	//////////////////////////
	f=fopen("data.txt","w");
	printf("輸入分母大小:\t");
	scanf("%d",&number_Out);
	fOutputData=new float[number_Out];
	fOutputFactor=new float[number_Out];
	for(i=0;i<number_Out;i++)
	{
		printf("輸入第%d個係數\t",i);
		scanf("%f",(fOutputFactor+i));
		*(fOutputData+i)=0.0f;
	}
	//////////////////////////
	printf("輸入分子大小:\t");
	scanf("%d",&number_In);
	fInputFactor=new float[number_In];
	fInputData=new float[number_In];
	for(i=0;i<number_In;i++)
	{
		printf("輸入第%d個係數\t",i);
		scanf("%f",(fInputFactor+i));
		*(fInputData+i)=0.0f;
	}
	////////////////////////////////
	for(j=0;j<1000;j++)
		CalculateOutput();
	printf("運算完成\n");

}
void CalculateOutput()
{
	int i;
	*(fOutputData+0)=0.0f;
	*(fInputData+0)=1.0f;
	for(i=0;i<number_Out;i++)
	{
		*(fOutputData+0)+=(*(fOutputData+i)**(fOutputFactor+i)*-1.0f);
	}
	for(i=0;i<number_In;i++)
	{
		*(fOutputData+0)+=(*(fInputData+i)**(fInputFactor+i)*1.0f);
	}
	fprintf(f,"%f\n",*(fOutputData+0));
	Shift_Arry(number_Out,fOutputData);
	Shift_Arry(number_In,fInputData);
}
void Shift_Arry(int n,float *data)
{
	int i;
	for(i=(n-1);i>=0;i--)
	{
		*(data+i)=*(data+(i-1));
	}
		data[0]=0;


}