/* program ptr0a.c */
/* demo pointer using */

main()
{
   int *p,*q,a=1,b;
   float *r,f=1.234;
   p=&a;
   printf("Enter one integer value :");
   scanf("%d",&b);
   q=&b;
   r=&f;
   printf("%d %d %6.3f\n",*p,*q,*r);
}