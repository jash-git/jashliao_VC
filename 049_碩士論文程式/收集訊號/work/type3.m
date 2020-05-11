num1=[1 2 3];den1=[1 2 3 4];
t=[0:0.01:40];
y=step(num1,den1,t);
plot(t,y)