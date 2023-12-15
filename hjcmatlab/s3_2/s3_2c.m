clc;
clear;

num=1;
den=[0.0067,0.1,0];
Gs=tf(num,den);
kp=20;
ki=5;
kd=2;
out=sim('s3_2');
plot(out.tout,out.simout,'linewidth',2);
hte=text(out.tout(end),out.simout(end),['ki=',num2str(ki)]);
hte.FontSize=16;
ht=title('黄锦灿');
ht.FontSize=16;