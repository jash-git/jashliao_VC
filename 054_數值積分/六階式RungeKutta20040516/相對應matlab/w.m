%讀取資料1
stream1 = fopen('sin.txt');
data1 = fscanf( stream1 , '%f' );
fclose(stream1);
x2=1:1:length(data1);
%x3=length(data3);
%繪圖
%subplot(2,1,1);
%x2=1:1:3000;
plot(x2,data1(x2),'b');
ylabel('q =>Blue');


