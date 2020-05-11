
/********************************************************************************************
	*  Copyright(c) tcpipstack
	*	File Name				:	RSA.c
	*	Abstract Description	:	RSA加解密演算法的簡單演示
	*	Create Date				:	2010/08/17
	*	Author					:	tcpipstack
	*-------------------------Revision History--------------------------------------------------
	*	No	Version		Date		Revised By			Item			Description
	*	 1		1.0		10/08/17
	*
	********************************************************************************************/
//https://github.com/longluo/RSA/blob/master/main.c
	#include <stdio.h>
	#include <math.h>

	/* RSA演算法中加密方公佈的金鑰是N和E，解密方使用N和D解密 */
	#define P	5	/* P和Q必須為素數，在實際運用中通常為很大的數 */
	#define	Q	7

	#define N	(P*Q)	/* add the (), or will cause the mistake */
	#define Z	((P - 1)*(Q - 1))

	#define E	5		/* 加密方選擇E，E必須和Z只有一個公約數 */
	#define D	5		/* (E * D - 1)必須能夠被Z整除 */
	/* 由於long int無法表示過大的數字，所以D取5 */


	int main(void)
	{
		int i;
		int TrsMsg[4] = {12, 15, 22, 5};
		long en[4], de[4];
		int SecCode[4], DeMsg[4];

		printf("下面是一個RSA加解密演算法的簡單演示:\n");
		printf("\t Copyright(C) Long.Luo.\n\n");
		printf("報文\t加密\t   加密後密文\n");

		for (i=0; i<4; i++)
		{
			/* s = m(E) mod N */
			en[i] = (int)pow(TrsMsg[i], E);
			SecCode[i] = en[i] % N;

			printf("%d\t%d\t\t%d\n", TrsMsg[i], en[i], SecCode[i]);
		}

		printf("\n原始報文\t密文\t加密\t\t解密報文\n");
		for (i=0; i<4; i++)
		{
			/* d = s(D) mod N */
			de[i] = pow(SecCode[i], D);
			DeMsg[i] = de[i] % N;

			printf("%d\t\t%d\t%d\t\t%d\n", TrsMsg[i], SecCode[i], de[i], DeMsg[i]);
		}

		getchar();

	  return 0;
	}


