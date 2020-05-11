clc
clear
n=-6:1:9;
u=-12:1:18;
u1=-300:1:449;
Ts1=0.005;
Ts2=0.0025;
Ts3=0.0001;
n1=n*Ts1;
n2=u*Ts2;
n3=u1*Ts3;
cn1=20*cos(2*pi*40*n1-0.4*pi);
cn2=20*cos(2*pi*40*n2-0.4*pi);
cn3=20*cos(2*pi*40*n3-0.4*pi);
 
SUBPLOT(3,1,1), stem(n1,cn1,'r'),hold on,plot(n1,cn1,'k'),hold off
SUBPLOT(3,1,2), stem(n2,cn2,'r'),hold on,plot(n2,cn2,'k'),hold off
SUBPLOT(3,1,3), stem(n3,cn3,'r'),hold on,plot(n3,cn3,'k'),hold off
