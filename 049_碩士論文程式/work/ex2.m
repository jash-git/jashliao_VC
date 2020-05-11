dt=1.0;
clear t x;
%eulmath;
Rung;
%Imprung;
t1=t;
x1=x;

dt=0.25;
clear t x;
%eulmath;
%Imprung;
Rung;
t2=t;
x2=x;

for kk=1:121
    t3(kk)=(kk-1)*0.1;
    x3(kk)=6*exp(-t3(kk)/4)+4;
end

plot(t1,x1,'r-o',t2,x2,'b-^',t3,x3,'k-');
title('Example 1');
xlabel('Time (s)');
ylabel('Acceleration (m/s^2)');
legend('h=1','h=0.25','Exact');