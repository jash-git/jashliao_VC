t(1)=0.0;
tf=12.0;
%
%	Set the initial condition
%
x(1)=10.0;
%
%	Loop through the times, numerically evaluating the integral
%
for i=2:tf/dt+1,
	
	xd=-1/4*x(i-1)+1;
	x(i)=x(i-1)+xd*dt;
	xd2=-1/4*x(i)+1;
    x(i)=x(i-1)+(xd+xd2)/2*dt;
    t(i)=t(i-1)+dt;
	er(i)=abs(x(i)-(6*exp(-t(i)/4)+4));

end;
