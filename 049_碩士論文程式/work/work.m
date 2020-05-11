clear
n1=-0.012:0.0001:0.018;
n2=-0.01:0.002:0.015;
y1=cos(2*pi*83*n1);
y2=cos(2*pi*83*n2);
y3=cos(2*pi*83*abs(n2));
subplot(6,1,1);plot(n1,y1,'k');hold on;title('f_0=83Hz,f_s=500Hz');stem(n2,y2,'k','fill');hold off
subplot(6,1,2); stairs(n2,y3,'r'); hold on; title('f_0=83Hz,f_s=500Hz'); stem(n2,y3,'k','fill');hold on;plot(n1,y1,'k');hold off 
subplot(6,1,3);plot(n1,y1,'k');hold on;title('f_0=83Hz,f_s=500Hz');stem(n2,y2,'k','fill');hold off
subplot(6,1,4); plot(n2,y3,'r'); hold on; title('f_0=83Hz,f_s=500Hz'); stem(n2,y3,'k','fill');hold on;plot(n1,y1,'k');hold off 
subplot(6,1,5);plot(n1,y1,'k');hold on;title('f_0=83Hz,f_s=500Hz');stem(n2,y2,'k','fill');hold off
subplot(6,1,6); interp1(n2,y3,'cubic'); hold on; title('f_0=83Hz,f_s=500Hz'); stem(n2,y3,'k','fill');hold on;plot(n1,y1,'k');hold off 
