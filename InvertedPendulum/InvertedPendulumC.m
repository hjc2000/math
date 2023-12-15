clc;
clear;
close all
%====================================
%系统参数
M=1.096;    %小车质量
m=0.109;    %摆杆质量
b=0.1;      %阻尼系数
l=0.25;     %杆质心到轴的距离
I=0.0034;   %杆的转动惯量
g=9.8;      %重力加速度
a1=-b/(M+m);
a2=-m*l*b/(M+m)/I;
a3=m*l*g/I;
b1=1/(M+m);
b2=m*l/I/(M+m);
A=[0,1,0,0; 0,a1,0,0; 0,0,0,1; 0,a2,a3,0];
B=[0,b1,0,b2]';
C=[1,0,0,0; 0,0,1,0];
D=0;
%====================================
% 求传递函数矩阵
syms s
SIA=s*eye(4)-A;
Gs=C/SIA*B;
Gs=collect(Gs,s);
[num,den]=numden(Gs);   %分离分子、分母
num1=sym2poly(num(1));
num2=sym2poly(num(2));
den1=sym2poly(den(1));
den2=sym2poly(den(2));
Gs1=tf(num1,den1);
Gs2=tf(num2,den2);
hf=figure(1);
rlocus(Gs1);
myPlotFormat([],[],hf,[],1);
hf=figure(2);
rlocus(Gs2);
myPlotFormat([],[],hf,[],1);
%====================================
polyA=poly(A);
rootA=roots(polyA);
P=[-20,-21,-22,-23];
K=place(A,B,P);
%====================================
rQc=rank(ctrb(A,B));
rQo=rank(obsv(A,C));
%仿真结束时间
tm=2
out=sim('InvertedPendulum');
hf=figure(3);
plot(out.tout,out.sy);
[ym,n]=max(out.sy,[],1);
hte=text(out.tout(n),ym,{'位移','角度'});
myPlotFormat(hte,16,hf,'输出',1);