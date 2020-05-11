/* program str08.c */
/* demo string insertion */

#include <string.h>
main()
{
	void insert(char *,char **,int);
	char *s1 = "abcde";
	char *s2 = "xyz";
	printf("s1 = %s\n",s1);
	printf("s2 = %s\n",s2);
	insert(s2,&s1,3);
	printf("After insertion : \n");
	printf("s1 = %s\n",s1);
}
void insert(char *x,char **y,int n)
{
	char *t1 = "\0";
	char *t2 = "\0";
	strncpy(t1,*y,n-1);
	t2 = strchr(*y,*(*y+n-1));
	strcat(t1,x);
	strcat(t1,t2);
	*y = t1;
}
