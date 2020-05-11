sysc=tf(3943.84,[1 87.92 3943.84]);
sysd=c2d(sysc,0.001,'tustin');
den=sysd.den{1}
num=sysd.num{1}
figure;
step(sysc,'--',sysd,'r');
figure;
bode(sysc,'*',sysd,'r');
