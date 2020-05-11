clc
clear
stream0 = fopen('Theta.txt');
stream1 = fopen('Psi.txt');
stream2 = fopen('Phi.txt');
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
data0 = fscanf( stream0 , '%f' );
data1 = fscanf( stream1 , '%f' );
data2 = fscanf( stream2 , '%f' );
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
t0=1:1:length(data0);
t1=1:1:length(data1);
t2=1:1:length(data2);
plot(t0,data0(t0),'r--',t1,data1(t1),'g',t2,data2(t2),'b--');
xlabel('dashed(--) is Y axis; line is Z axis; square is X axis'),grid,