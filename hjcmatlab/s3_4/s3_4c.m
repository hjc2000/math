clc;
clear;
kp=1.8;
Ti=20;
Td=5;
ki=1/Ti;
kd=Td;
out=sim('s3_4');
plot(out.tout,out.simout,'linewidth',2);
grid on
ht=title('黄锦灿');
ht.FontSize=16;
