#include<stdio.h>
#include<math.h>
#include <windows.h>
////////////////////////////////////////////////
#define pi 3.141592654
#define delt 0.000218//ㄏノぇい琿繵瞯﹚竡ぇ  5ms
////////////////////////////////////////////////////
float K1X1p_secorder1=0.0f,K2X1p_secorder1=0.0f,K3X1p_secorder1=0.0f,K4X1p_secorder1=0.0f;
float K1X2p_secorder1=0.0f,K2X2p_secorder1=0.0f,K3X2p_secorder1=0.0f,K4X2p_secorder1=0.0f;
float XX1p_secorder1=0.0f,Y_secorder1=0.0f;
float XX2p_secorder1=0.0f;
////////////////
float K1X1p_secorder2=0.0f,K2X1p_secorder2=0.0f,K3X1p_secorder2=0.0f,K4X1p_secorder2=0.0;
float K1X2p_secorder2=0.0f,K2X2p_secorder2=0.0f,K3X2p_secorder2=0.0f,K4X2p_secorder2=0.0;
float XX1p_secorder2=0.0f,Y_secorder2=0.0f;
float XX2p_secorder2=0.0f;
////////////////
float K1X1p_secorder3=0.0f,K2X1p_secorder3=0.0f,K3X1p_secorder3=0.0f,K4X1p_secorder3=0.0;
float K1X2p_secorder3=0.0f,K2X2p_secorder3=0.0f,K3X2p_secorder3=0.0f,K4X2p_secorder3=0.0;
float XX1p_secorder3=0.0f,Y_secorder3=0.0f;
float XX2p_secorder3=0.0f;
//////////////////////////////////////////////////////////////
float K1X1p_1=0.0f,K2X1p_1=0.0f,K3X1p_1=0.0f,K4X1p_1=0.0f;
float XX1p_1=0.0f,Y_1=0.0f;
////////////////
float K1X1p_2=0.0f,K2X1p_2=0.0f,K3X1p_2=0.0f,K4X1p_2=0.0f;
float XX1p_2=0.0f,Y_2=0.0f;
////////////////
float K1X1p_3=0.0f,K2X1p_3=0.0f,K3X1p_3=0.0f,K4X1p_3=0.0f;
float XX1p_3=0.0f,Y_3=0.0f;
////////////////////////////////////////////////
struct lowpassfilter{

	float fa,fb,fc,fd;

	float dut,ut,x1;

}filter1,filter2,filter3;
struct lowpass_secorder{

	float fa,fb,fc,fd,fe;

	float dut,ut,x1,x2;

}secorder1,secorder2,secorder3;
/////////////////////////////////////////////////
float SecOrderLowPass1(float u)

{

	//////////////////////////////////////////////////

	//runge-kuta 把计
	float delT=0.001f;
	secorder1.ut=u;
	// K1=Tf(x,t);
	K1X1p_secorder1 = secorder1.x2;
	K1X2p_secorder1 = -(secorder1.fc/secorder1.fa)*secorder1.x1 - (secorder1.fb/secorder1.fa)*secorder1.x2 + (secorder1.fd/secorder1.fa)*secorder1.dut+(secorder1.fe/secorder1.fa)*secorder1.ut;
	// K2=Tf(x+b1k1 , t+a1T);
	XX1p_secorder1 = secorder1.x1 +delT/2.0f * K1X1p_secorder1;
	XX2p_secorder1 = secorder1.x2 +delT/2.0f * K1X2p_secorder1;
	K2X1p_secorder1=XX2p_secorder1;
	K2X2p_secorder1 = -(secorder1.fc/secorder1.fa)*XX1p_secorder1 - (secorder1.fb/secorder1.fa)*XX2p_secorder1 + (secorder1.fd/secorder1.fa)*secorder1.dut+(secorder1.fe/secorder1.fa)*secorder1.ut;
	// K3=Tf(x+b2K1+b3K2 , t+a2T);
	XX1p_secorder1 = secorder1.x1 + delT/2.0f * K2X1p_secorder1;
	XX2p_secorder1 = secorder1.x2 + delT/2.0f * K2X2p_secorder1;
	K3X1p_secorder1=XX2p_secorder1;
	K3X2p_secorder1 = -(secorder1.fc/secorder1.fa)*XX1p_secorder1 - (secorder1.fb/secorder1.fa)*XX2p_secorder1 + (secorder1.fd/secorder1.fa)*secorder1.dut+ (secorder1.fe/secorder1.fa)*secorder1.ut;
	// K4=Tf(x+b4k1+b5K2+b6K3 , t+a3T);
	XX1p_secorder1 = secorder1.x1 + delT * K3X1p_secorder1;
	XX2p_secorder1 = secorder1.x2 + delT * K3X2p_secorder1;
	K4X1p_secorder1=XX2p_secorder1;
	K4X2p_secorder1 = -(secorder1.fc/secorder1.fa)*XX1p_secorder1 - (secorder1.fb/secorder1.fa)*XX2p_secorder1 + (secorder1.fd/secorder1.fa)*secorder1.dut+ (secorder1.fe/secorder1.fa)*secorder1.ut;
	secorder1.x1=secorder1.x1+delT*(K1X1p_secorder1+2.0f*(K2X1p_secorder1+K3X1p_secorder1)+K4X1p_secorder1)/6.0f;
	secorder1.x2=secorder1.x2+delT*(K1X2p_secorder1+2.0f*(K2X2p_secorder1+K3X2p_secorder1)+K4X2p_secorder1)/6.0f;
	return secorder1.x1;

}
////////////////////////////////////////////////
float SecOrderLowPass2(float u)

{

	//////////////////////////////////////////////////

	//runge-kuta 把计
	float delT=0.001f;
	secorder2.ut=u;
	// K1=Tf(x,t);
	K1X1p_secorder2 = secorder2.x2;
	K1X2p_secorder2 = -(secorder2.fc/secorder2.fa)*secorder2.x1 - (secorder2.fb/secorder2.fa)*secorder2.x2 + (secorder2.fd/secorder2.fa)*secorder2.dut+(secorder2.fe/secorder2.fa)*secorder2.ut;
	// K2=Tf(x+b1k1 , t+a1T);
	XX1p_secorder2 = secorder2.x1 +delT/2.0f * K1X1p_secorder2;
	XX2p_secorder2 = secorder2.x2 +delT/2.0f * K1X2p_secorder2;
	K2X1p_secorder2=XX2p_secorder2;
	K2X2p_secorder2 = -(secorder2.fc/secorder2.fa)*XX1p_secorder2 - (secorder2.fb/secorder2.fa)*XX2p_secorder2 + (secorder2.fd/secorder2.fa)*secorder2.dut+(secorder2.fe/secorder2.fa)*secorder2.ut;
	// K3=Tf(x+b2K1+b3K2 , t+a2T);
	XX1p_secorder2 = secorder2.x1 + delT/2.0f * K2X1p_secorder2;
	XX2p_secorder2 = secorder2.x2 + delT/2.0f * K2X2p_secorder2;
	K3X1p_secorder2=XX2p_secorder2;
	K3X2p_secorder2 = -(secorder2.fc/secorder2.fa)*XX1p_secorder2 - (secorder2.fb/secorder2.fa)*XX2p_secorder2 + (secorder2.fd/secorder2.fa)*secorder2.dut+ (secorder2.fe/secorder2.fa)*secorder2.ut;
	// K4=Tf(x+b4k1+b5K2+b6K3 , t+a3T);
	XX1p_secorder2 = secorder2.x1 + delT * K3X1p_secorder2;
	XX2p_secorder2 = secorder2.x2 + delT * K3X2p_secorder2;
	K4X1p_secorder2=XX2p_secorder2;
	K4X2p_secorder2 = -(secorder2.fc/secorder2.fa)*XX1p_secorder2 - (secorder2.fb/secorder2.fa)*XX2p_secorder2 + (secorder2.fd/secorder2.fa)*secorder2.dut+ (secorder2.fe/secorder2.fa)*secorder2.ut;
	secorder2.x1=secorder2.x1+delT*(K1X1p_secorder2+2.0f*(K2X1p_secorder2+K3X1p_secorder2)+K4X1p_secorder2)/6.0f;
	secorder2.x2=secorder2.x2+delT*(K1X2p_secorder2+2.0f*(K2X2p_secorder2+K3X2p_secorder2)+K4X2p_secorder2)/6.0f;
	return secorder2.x1;

}
////////////////////////////////////////////////
float SecOrderLowPass3(float u)

{

	//////////////////////////////////////////////////

	//runge-kuta 把计
	float delT=0.001f;
	secorder3.ut=u;
	// K1=Tf(x,t);
	K1X1p_secorder3 = secorder3.x2;
	K1X2p_secorder3 = -(secorder3.fc/secorder3.fa)*secorder3.x1 - (secorder3.fb/secorder3.fa)*secorder3.x2 + (secorder3.fd/secorder3.fa)*secorder3.dut+(secorder3.fe/secorder3.fa)*secorder3.ut;
	// K2=Tf(x+b1k1 , t+a1T);
	XX1p_secorder3 = secorder3.x1 +delT/2.0f * K1X1p_secorder3;
	XX2p_secorder3 = secorder3.x2 +delT/2.0f * K1X2p_secorder3;
	K2X1p_secorder3=XX2p_secorder3;
	K2X2p_secorder3 = -(secorder3.fc/secorder3.fa)*XX1p_secorder3 - (secorder3.fb/secorder3.fa)*XX2p_secorder3 + (secorder3.fd/secorder3.fa)*secorder3.dut+(secorder3.fe/secorder3.fa)*secorder3.ut;
	// K3=Tf(x+b2K1+b3K2 , t+a2T);
	XX1p_secorder3 = secorder3.x1 + delT/2.0f * K2X1p_secorder3;
	XX2p_secorder3 = secorder3.x2 + delT/2.0f * K2X2p_secorder3;
	K3X1p_secorder3=XX2p_secorder3;
	K3X2p_secorder3 = -(secorder3.fc/secorder3.fa)*XX1p_secorder3 - (secorder3.fb/secorder3.fa)*XX2p_secorder3 + (secorder3.fd/secorder3.fa)*secorder3.dut+ (secorder3.fe/secorder3.fa)*secorder3.ut;
	// K4=Tf(x+b4k1+b5K2+b6K3 , t+a3T);
	XX1p_secorder3 = secorder3.x1 + delT * K3X1p_secorder3;
	XX2p_secorder3 = secorder3.x2 + delT * K3X2p_secorder3;
	K4X1p_secorder3=XX2p_secorder3;
	K4X2p_secorder3 = -(secorder3.fc/secorder3.fa)*XX1p_secorder3 - (secorder3.fb/secorder3.fa)*XX2p_secorder3 + (secorder3.fd/secorder3.fa)*secorder3.dut+ (secorder3.fe/secorder3.fa)*secorder3.ut;
	secorder3.x1=secorder3.x1+delT*(K1X1p_secorder3+2.0f*(K2X1p_secorder3+K3X1p_secorder3)+K4X1p_secorder3)/6.0f;
	secorder3.x2=secorder3.x2+delT*(K1X2p_secorder3+2.0f*(K2X2p_secorder3+K3X2p_secorder3)+K4X2p_secorder3)/6.0f;
	return secorder3.x1;

}
////////////////////////////////////////////////
float LowPassFilterFunction1(float u)

{

	//////////////////////////////////////////////////

	//runge-kuta 把计
	float delT=0.001f;
	filter1.ut=u;
	// K1=Tf(x,t);
	K1X1p_1 = -(filter1.fb/filter1.fa)*filter1.x1 + (filter1.fc/filter1.fa)*filter1.dut + (filter1.fd/filter1.fa)*filter1.ut;
	// K2=Tf(x+b1k1 , t+a1T);
	XX1p_1 = filter1.x1 +delT/2.0f * K1X1p_1;
	K2X1p_1 = -(filter1.fb/filter1.fa)*XX1p_1 + (filter1.fc/filter1.fa)*filter1.dut + (filter1.fd/filter1.fa)*filter1.ut;
	// K3=Tf(x+b2K1+b3K2 , t+a2T);
	XX1p_1 = filter1.x1 + delT/2.0f * K2X1p_1;
	K3X1p_1 = -(filter1.fb/filter1.fa)*XX1p_1 + (filter1.fc/filter1.fa)*filter1.dut + (filter1.fd/filter1.fa)*filter1.ut;
	// K4=Tf(x+b4k1+b5K2+b6K3 , t+a3T);
	XX1p_1 = filter1.x1 + delT * K3X1p_1;
	K4X1p_1 = -(filter1.fb/filter1.fa)*XX1p_1 + (filter1.fc/filter1.fa)*filter1.dut + (filter1.fd/filter1.fa)*filter1.ut;
	filter1.x1 = filter1.x1 + delT * (K1X1p_1 + 2.0f*(K2X1p_1 + K3X1p_1) + K4X1p_1)/6.0f;
	return filter1.x1;

}
float LowPassFilterFunction2(float u)

{

	//////////////////////////////////////////////////

	//runge-kuta 把计
	float delT=0.001f;
	filter2.ut=u;
	// K1=Tf(x,t);
	K1X1p_2 = -(filter2.fb/filter2.fa)*filter2.x1 + (filter2.fc/filter2.fa)*filter2.dut + (filter2.fd/filter2.fa)*filter2.ut;
	// K2=Tf(x+b1k1 , t+a1T);
	XX1p_2 = filter2.x1 +delT/2.0f * K1X1p_2;
	K2X1p_2 = -(filter2.fb/filter2.fa)*XX1p_2 + (filter2.fc/filter2.fa)*filter2.dut + (filter2.fd/filter2.fa)*filter2.ut;
	// K3=Tf(x+b2K1+b3K2 , t+a2T);
	XX1p_2 = filter2.x1 + delT/2.0f * K2X1p_2;
	K3X1p_2 = -(filter2.fb/filter2.fa)*XX1p_2 + (filter2.fc/filter2.fa)*filter2.dut + (filter2.fd/filter2.fa)*filter2.ut;
	// K4=Tf(x+b4k1+b5K2+b6K3 , t+a3T);
	XX1p_2 = filter2.x1 + delT * K3X1p_2;
	K4X1p_2 = -(filter2.fb/filter2.fa)*XX1p_2 + (filter2.fc/filter2.fa)*filter2.dut + (filter2.fd/filter2.fa)*filter2.ut;
	filter2.x1 = filter2.x1 + delT * (K1X1p_2 + 2.0f*(K2X1p_2 + K3X1p_2) + K4X1p_2)/6.0f;
	return filter2.x1;

}
float LowPassFilterFunction3(float u)

{

	//////////////////////////////////////////////////

	//runge-kuta 把计
	float delT=0.001f;
	filter3.ut=u;
	// K1=Tf(x,t);
	K1X1p_3 = -(filter3.fb/filter3.fa)*filter3.x1 + (filter3.fc/filter3.fa)*filter3.dut + (filter3.fd/filter3.fa)*filter3.ut;
	// K2=Tf(x+b1k1 , t+a1T);
	XX1p_3 = filter3.x1 +delT/2.0f * K1X1p_3;
	K2X1p_3 = -(filter3.fb/filter3.fa)*XX1p_3 + (filter3.fc/filter3.fa)*filter3.dut + (filter3.fd/filter3.fa)*filter3.ut;
	// K3=Tf(x+b2K1+b3K2 , t+a2T);
	XX1p_3 = filter3.x1 + delT/2.0f * K2X1p_3;
	K3X1p_3 = -(filter3.fb/filter3.fa)*XX1p_3 + (filter3.fc/filter3.fa)*filter3.dut + (filter3.fd/filter3.fa)*filter3.ut;
	// K4=Tf(x+b4k1+b5K2+b6K3 , t+a3T);
	XX1p_3 = filter3.x1 + delT * K3X1p_3;
	K4X1p_3 = -(filter3.fb/filter3.fa)*XX1p_3 + (filter3.fc/filter3.fa)*filter3.dut + (filter3.fd/filter3.fa)*filter3.ut;
	filter3.x1 = filter3.x1 + delT * (K1X1p_3 + 2.0f*(K2X1p_3 + K3X1p_3) + K4X1p_3)/6.0f;
	return filter3.x1;

}
////////////////////////////////////////////////
void main(void)
{
		float u ,v ,w;//x,y,z硉
        float p ,q ,r;//x,y,zà硉
		float test;
        int i=0;
        float theta= 0, phi=0, psi=0 ;
        float s11=0,s22=0,s33=0,c11=0,c22=0,c33=0;
        float e0=0,e1=0,e2=0,e3=0;
        float epsilon=0;
        float e0d=0,e1d=0,e2d=0,e3d=0;
        float l1=0,l2=0,l3=0,m3=0,n3=0,ll3=0;
        float phasenow=0,invphi=0,invpsi=0;
		FILE *qt,*th,*rt,*psit,*pt,*phit,*qt1,*pt1,*rt1;
		bool k;
		k=false;
		float e_q=0.0f,e_p=0.0f,e_r=0.0f;
		//////////////////////////////////
		secorder1.dut=0.0f;
		secorder1.fa=1.0f;
		secorder1.fb=2.8f; 
		secorder1.fc=4.0f; 
		secorder1.fd=0.0f; 
		secorder1.fe=4.0f;
		secorder1.ut=0.0f;
		secorder1.x1=0.0f;
		secorder1.x2=0.0f;
		///////////////////////
		secorder2.dut=0.0f;
		secorder2.fa=1.0f;
		secorder2.fb=2.8f; 
		secorder2.fc=4.0f; 
		secorder2.fd=0.0f; 
		secorder2.fe=4.0f;
		secorder2.ut=0.0f;
		secorder2.x1=0.0f;
		secorder2.x2=0.0f;
		////////////////////////
		secorder3.dut=0.0f;
		secorder3.fa=1.0f;
		secorder3.fb=2.8f; 
		secorder3.fc=4.0f; 
		secorder3.fd=0.0f; 
		secorder3.fe=4.0f;
		secorder3.ut=0.0f;
		secorder3.x1=0.0f;
		secorder3.x2=0.0f;
		//////////////////////////////////
		//p
		filter1.dut=0.0f;
		filter1.fa=1.0f;
		filter1.fb=2.1f;
		filter1.fc=0.0f;
		filter1.fd=2.1f;
		filter1.ut=0.0f;
		filter1.x1=0.0f;
		/////////////////////////////////
		//q
		filter2.dut=0.0f;
		filter2.fa=1.0f;
		filter2.fb=2.1f;//7.5
		filter2.fc=0.0f;
		filter2.fd=2.1f;
		filter2.ut=0.0f;
		filter2.x1=0.0f;
		///////////////////////////////
		//r
		filter3.dut=0.0f;
		filter3.fa=1.0f;
		filter3.fb=2.1f;
		filter3.fc=0.0f;
		filter3.fd=2.1f;
		filter3.ut=0.0f;
		filter3.x1=0.0f;
		//////////////////////////////

		//filter1.ut=u;
		/////////////////////////////////
		qt=fopen("q.txt","r");
		rt=fopen("r.txt","r");
		pt=fopen("p.txt","r");
		//////////////////////
		qt1=fopen("q1.txt","w");
		rt1=fopen("r1.txt","w");
		pt1=fopen("p1.txt","w");
		///////////////////////
		psit=fopen("psi.txt","w");
		th=fopen("theta.txt","w");
		phit=fopen("phi.txt","w");
		/////////////////////////////////
		while(fscanf(qt,"%f",&q)!=EOF)
		{

			fscanf(rt,"%f",&r);
			fscanf(pt,"%f",&p);


			//////////////////////////
			/*
			p=LowPassFilterFunction1(p);
			q=LowPassFilterFunction2(q);
			r=LowPassFilterFunction3(r);
			*/
			///////////////////////////
			
			p=SecOrderLowPass1(p);
			q=SecOrderLowPass2(q);
			r=SecOrderLowPass3(r);
			
			if(q<-4.6||k==true)
			{
				i+=1;
				k=true;
				if(i <= 11500)
				{
					e_q+=q;
					e_p+=p;
					e_r+=r;
				printf("i=%d\t",i);
				
				}
				else
				{
					if(i==11501)
					{
					printf("1 e_p=%f\t",e_p);
					printf("2 e_q=%f\t",e_q);
					printf("3 e_r=%f\n",e_r);	
					e_q/=11500;
					e_r/=11500;
					e_p/=11500;
					}

				}

			}
			if(i>11501 && i<80000)
			{
				q-=e_q;
				p-=e_p;
				r-=e_r;
				q=q/3.0;
				p/=3.0;
				r/=3.0;
				fprintf(qt1,"%f\n",q);
				fprintf(pt1,"%f\n",p);
				fprintf(rt1,"%f\n",r);
/////////////////////////////////////////////////
			s11=sin(theta/2.0); s22=sin(phi/2.0); s33=sin(psi/2.0);
			c11=cos(theta/2.0); c22=cos(phi/2.0); c33=cos(psi/2.0);
			e0 =  c11*c22*c33 + s11*s22*s33;
			e1 =  c11*s22*c33 - s11*c22*s33;
			e2 =  s11*c22*c33 + c11*s22*s33;
			e3 = -s11*s22*c33 + c11*c22*s33;
			epsilon = 1.0 - e0*e0 - e1*e1 - e2*e2 - e3*e3;
			/*
			e0=e0*(1+0.5*epsilon);
			e1=e1*(1+0.5*epsilon);
			e2=e2*(1+0.5*epsilon);
			e3=e3*(1+0.5*epsilon);
			e0d = -0.5 * (e1*p + e2*q + e3*r) ;
			e1d =  0.5 * (e0*p - e3*q + e2*r) ;
			e2d =  0.5 * (e3*p + e0*q - e1*r) ;
			e3d =  0.5 * (-e2*p + e1*q + e0*r);
			*/
			
			e0d = -0.5 * (e1*p + e2*q + e3*r) + epsilon * e0;
			e1d =  0.5 * (e0*p - e3*q + e2*r) + epsilon * e1;
			e2d =  0.5 * (e3*p + e0*q - e1*r) + epsilon * e2;
			e3d =  0.5 * (-e2*p + e1*q + e0*r) + epsilon * e3;
			
			e0 += e0d * delt;
			e1 += e1d * delt;
			e2 += e2d * delt;
			e3 += e3d * delt;
			l1 = e0*e0+e1*e1-e2*e2-e3*e3;
			l2 = 2.0 * (e1*e2 + e0*e3);
			l3 = 2.0 * (e1*e3 - e0*e2);
			m3 = 2.0 * (e2*e3 + e0*e1);
			n3 = e0*e0-e1*e1-e2*e2+e3*e3;
			theta=asin(-l3);
			phi=atan(m3/n3);
			psi=atan(l2/l1);
			

	//////////////////////////////////////
		fprintf(th,"%f\n",(theta*180/pi));
		fprintf(psit,"%f\n",(psi*180/pi));
		fprintf(phit,"%f\n",(phi*180/pi));
	}//(i>1201 && i<80000)
	}//while
		fclose(qt);
		fclose(th);
		fclose(rt);
		fclose(psit);
		fclose(pt);
		fclose(phit);
		fclose(qt1);
		fclose(pt1);
		fclose(rt1);
		printf("e_p=%f\t",e_p);
		printf("e_q=%f\t",e_q);
		printf("e_r=%f\t",e_r);	
}