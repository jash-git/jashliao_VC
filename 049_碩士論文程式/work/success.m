clc
clear
stream0 = fopen('book.txt');
data0 = fscanf( stream0 , '%f' );
fclose(stream0);
alpha=0.1;
[hat0,ci0]=mle('norm',data0,alpha)
mu=hat0(1,1);
sigma=hat0(1,2);
x=0:0.1:100;
Px=normpdf(x,mu,sigma);
plot(x,Px,'+')

