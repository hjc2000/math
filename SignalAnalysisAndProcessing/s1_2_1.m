clc;
clear;
t=-10:0.01:10;
x1=exp(-1.5*t);
subplot(3,2,1);
plot(t,x1);
axis([0,10,0,1.2]);
grid on
subplot(3,2,2);
x2=3.*sin(0.5*pi*t);
plot(t,x2);
grid on
x3=0.5+0.5.*sign(t);
subplot(3,2,3);
plot(t,x3);
axis([-10,10,-0.1,1.1]);
grid on
x4=step(t)+step(t-1)-2.*step(t-2);
subplot(3,2,4);
plot(t,x4);
axis([-0.2,5,-0.2,2.2]);
grid on
x5=t./2.*(step(t)-step(t-4));
subplot(3,2,5);
plot(t,x5);
grid on