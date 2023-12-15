clc;
clear;
t=-10:0.001:10;
x1=delta(t);
x2=step(t);
x3=sin(t);

subplot(2,2,1);
plot(t,x1);
grid on

subplot(2,2,2);
plot(t,x2);
axis([-1,2,-0.1,1.1]);
grid on

subplot(2,2,3);
plot(t,x3);
grid on
