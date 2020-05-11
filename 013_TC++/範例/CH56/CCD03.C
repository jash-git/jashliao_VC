/* program  ccd03.c */

#define XT 8088
#define AT 8086
#undef  AT
#define SX 80386
#define AT 80286
main()
{
	printf("The PC-XT cpu is %d\n",XT);
	printf("The PC-AT cpu is %ld\n",AT);
	printf("The PC 386/SX cpu is %ld\n",SX);
}
