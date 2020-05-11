/* program stdlib07.c  */
/* demo rand() application, guess number */

#include <stdlib.h>
#include <time.h>
main()
{
	int num, guess, count=0;
	randomize();
	num = random(80)+1;
	do
	{
		printf(" Enter your guess ( 1-80 ) :");
		scanf("%d",&guess);
		count++;
		if ( guess > num )
			printf(" Too high ...\n");
		else  if ( guess < num )
						printf(" Too low ... \n");
					else
						printf(" Bingo ! \n");
	}
	while (( guess != num ) && ( count < 5 ));
	if ( guess != num )
		printf(" Too bad, the number is %d\n",num);
	else
		printf(" You are lucky  !\n");
}