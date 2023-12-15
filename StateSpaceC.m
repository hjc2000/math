clc;
clear;

num=1;
den=[1,5,1];
[A,B,C,D]=tf2ss(num,den);
sys=ss(A,B,C,D);
poA=poly(A);
roA=roots(poA);

wn=1000;
xi=0.707;
tao=1/1;
kp=wn^2;
ki=kp/tao;
P=[-1/tao,-2*xi*wn];
K=place(A,B,P);
PG=4.*P;
G=place(A',C',PG)';

out=sim('StateSpace');
hf=figure(1);
plot(out.tout,out.y);
myPlotFormat([],0,hf,[],1);