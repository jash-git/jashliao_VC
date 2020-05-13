#include <stdio.h>
#include <math.h>
#include <sys\timeb.h>
double pi=57.3;
#include"RungeKutta.h"
void main(void)
{
	FILE *s,*c;
	struct timeb t1,t2;
	float u=0;
	//RungeKutta_SixOder RungeKutta1(1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0,10.0,11.0,12.0,13.0,0.01);
	RungeKutta_SixOder RungeKutta1(1,2,3,4,1,0.55,2,0,0,0,0,0,2,0.01);
	c=fopen("cos.txt","w");
	s=fopen("sin.txt","w");
	for(int i=0;i<=2000;i++)
	{
		u=1.0;
		//u=10*sin(i/pi);
		fprintf(s,"%f\n",u);
		if (i==1)
			ftime(&t1);
		RungeKutta1.RungeKutta_SixOder_compute(u,0.0,0.0,0.0,0.0,0.0);
		if (i==1)
			ftime(&t2);
		fprintf(c,"%f\n",RungeKutta1.Y);
		fprintf(s,"%f\n",RungeKutta1.Yp5);
		
	}
	printf("start	time=%ds\t%dms\n",t1.time,t1.millitm);
	printf("end	time=%ds\t%dms\n",t2.time,t2.millitm);
	printf("%d th's=%f\n",i,RungeKutta1.Y);
	fclose(c);
	fclose(s);

}
