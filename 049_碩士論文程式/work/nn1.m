time=0:0.025:5;T=sin(time*4*pi);Q=length(T);P=zeros(5,Q)
P(1,2:Q)=T(1,1:(Q-1));P(2,3:Q)=T(1,1:(Q-2));P(3,4:Q)=T(1,1:(Q-3));
P(4,5:Q)=T(1,1:(Q-4));P(5,6:Q)=T(1,1:(Q-5));
net=newlind(P,T);a=sim(net,P);
plot(time,a,time,T,'+');