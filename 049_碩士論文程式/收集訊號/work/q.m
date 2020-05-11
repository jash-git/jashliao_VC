clc
clear
stream1 = fopen('Q.txt');
data1 = fscanf( stream1 , '%f' );
t1=1:1:length(data1);
plot(t1,data1(t1),'g');
fclose(stream1);