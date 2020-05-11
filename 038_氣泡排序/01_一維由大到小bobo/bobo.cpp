#include <iostream.h>
#include <stdio.h>
void main()
{
	int i,j,temp,n,k,key;
	i=0;
	j=0;
	n=0;
	temp=0;
	key=0;
	int Data[10]={10,78,45,89,01,05,23,54,20,32};
	for(i=0;i<10;i++)
		cout <<Data[i]<<"\t";
	cout <<"\n"<<"/////////////////////////////////////////////////////////////////"<<"\n";
	n=i;
	for(i=0;i<10;i++)
	{
		key=0;
		for(j=0;j<n-i-1;j++)
		{
			if(Data[j]<Data[j+1])
			{
				temp=Data[j];
				Data[j]=Data[j+1];
				Data[j+1]=temp;
				key=1;
			}
		}
		if(key==0)
			break;
		for(k=0;k<10;k++)
			cout <<Data[k]<<"\t";
		cout <<"\n";
	}

}
