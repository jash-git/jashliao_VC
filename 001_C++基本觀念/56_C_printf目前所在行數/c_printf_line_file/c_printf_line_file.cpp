#include <stdio.h>
#include <stdlib.h>
#define BRIGHT 1
#define RED 31
#define BG_BLACK 40
void print_info_line(char *data)
{
	printf("%s---%d\t%s\n",__FILE__, __LINE__,data);
}
int main(void)
{
	char *data="jash test";
	print_info_line(data);
	system("pause");
	return 0;
}