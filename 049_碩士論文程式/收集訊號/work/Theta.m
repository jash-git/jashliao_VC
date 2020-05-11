clc
clear
stream0 = fopen('Theta.txt');
data0 = fscanf( stream0 , '%f' );
t0=1:1:length(data0);
plot(t0,data0(t0),'r');
fclose(stream0);