clc
clear
stream2 = fopen('R¥¼Âoªi.txt');
data2 = fscanf( stream2 , '%f' );
t2=1:1:length(data2);
plot(t2,data2(t2),'r');
fclose(stream2);