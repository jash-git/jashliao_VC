/* program str09.c */
/* demo string deletion */

#include <string.h>
main()
{
	void delete(char **,int,int);
	char *s = "abxyzcde";
	printf("\ns  = %s\n",s);
	delete(&s,3,3);
	printf("after deletion : \n");
	printf("s = %s\n",s);
}
void delete(char **s,int index,int length)
{
	char *t1 = "\0";
	char *t2 = "\0";
	strncpy(t1,*s,index-1);
	t2 = strchr(*s,*(*s+index-1+length));
	strcat(t1,t2);
	*s = t1;
}
