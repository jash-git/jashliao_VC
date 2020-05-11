
clear;
dt=1.0;
t(1) = 0.0;
tf   = 12.0;
%
%	Set the initial condition
%
x(1)=10.0;
%
%
%	Loop through the times, numerically evaluating the integral
%
for i=2:tf/dt+1,
	
	%k1=-1/4*x(i-1)+1;
	k1=f(x(i-1),t(i-1));
    %xhat1=x(i-1)+k1*dt/2;
	k2=f(x(i-1)+k1*dt/2,t(i-1)+dt/2);
    %k2=-1/4*xhat1+1;
	%xhat2=x(i-1)+k2*dt/2;
	k3=f(x(i-1)+k2*dt/2,t(i-1)+dt/2);
    %k3=-1/4*xhat2+1;
	%xhat3=x(i-1)+k3*dt;
    %k4=-1/4*xhat3+1;
    k4=f(x(i-1)+k3*dt,t(i-1)+dt);
        
	x(i)=x(i-1)+dt/6*(k1+2*k2+2*k3+k4);
	t(i)=t(i-1)+dt;
end;

for n=2:tf/dt+1,
	
	w1=-1/4*x(n-1)+1;
    xhat1=x(n-1)+w1*dt/2;

    w2=-1/4*xhat1+1;
	xhat2=x(n-1)+w2*dt/2;
	
    w3=-1/4*xhat2+1;
	xhat3=x(n-1)+w3*dt;
    w4=-1/4*xhat3+1;
    
    x1(1)=10.0;
    x1(n)=x(n-1)+dt/6*(w1+2*w2+2*w3+w4);
	t1(n)=t(n-1)+dt;
    
end;

plot(x,t,'r',x1,t1,'y--');