sysc=tf(1,[1 2]);
sysd=c2d(sysc,0.02,'tustin');
den=sysd.den{1}
num=sysd.num{1}
figure;
step(sysc,'*',sysd,'r');
figure;
bode(sysc,'*',sysd,'r');