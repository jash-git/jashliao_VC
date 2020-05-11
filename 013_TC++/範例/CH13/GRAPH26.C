/* program graph26.c */

#include <conio.h>
main()
{
	int x1,x2,y1,y2;
	char s[255]="BBBBBBBBBBBBBBBBBBBB";
	clrscr();
	printf("\nKey in x1,x2,y1,y2 : ");
	scanf("%d %d %d %d",&x1,&x2,&y1,&y2);
	window(x1,y1,x2,y2);
	printf("%s\n",s);
	window(1,1,80,25);
}

