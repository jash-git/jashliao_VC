#include <stdio.h>
/*
假設以下是程式馬
int a;
while(1)
{
   scanf("%d",&a);
}
然後呢
應該是無限迴圈 ~ 之後在每次回圈應該都可輸入一次數字!
好~是這樣沒錯 !
但是為什麼輸入英文字時~他不會再呼叫   scanf  會直接無窮迴圈下去 !!

然後我問一下 , 在 int  %d 裡打英文 , 不是那個數字會變成0嗎??

如果要判斷你輸入的自是不是正確的
可以這樣嗎
//////////////////////////////////////////////////////////////
解答
輸入英文後，因為那個英文還是沒有被讀進來，所以會殘存著，下次scanf還是因為是英文所以傳回0
可以判斷如果輸入錯誤就再 scanf 一次，但這次是接收 %s，不是%d，這樣就可以把那個英文接收，
int a;
char b[256];
while(1)
{
  if(scanf("%d", &a)==0)
    scanf("%s", b);
} 
*/
void main()
{
	int a=0;
	char b[256];
	while(1)
	{
		printf("key in a int value\t");

		if(scanf("%d", &a)==0)
		{
			scanf("%s", b);
			printf("you input the data %s\n",b);
		}
		printf("you input the data %d\n",a);
	}
}