clc;
clear;
%电机参数
%==========================================
R=6.58;
Tm=0.25;
Ce=0.131;
UN=220;     %额定电压
IN=13.6;    %额定电流
nN=1480;    %额定转速
Tl=0.018;
Ks=76;      %整流装置放大倍数
Ts=0.0167;  %整流装置失效时间
beta=0.4;
alpha=0.00337;
%==========================================
%计算电流环
%==========================================
kp=Tl*R/(2*Ts*Ks*beta);
P=kp;
I=kp/Ts;
K=1/(2*Ts);
%==========================================
%计算转速环
%==========================================
syms s
num=K;
den=s*(Ts*s+1)+K;
den=collect(den,s);
den=sym2poly(den);
den=den(2:end);
den=den./num;
T1=den(1);
tau1=5*T1;
K1=1/tau1*0.5*(1/tau1+1/T1);
kp1=Ce*Tm*Tl*K1/(alpha*R);
P1=kp1;
I1=kp1/tau1;
%==========================================
%仿真
out=sim('s5_1');
plot(out.tout,out.I,'linewidth',2);
grid on
ht=title('黄锦灿');
ht.FontSize=20;
ki=1/beta;  %电流稳态值/给定大小
hold on
hte=text(out.tout(end),out.I(end),'I');
hte.FontSize=20;

plot(out.tout,out.n,'linewidth',2);
hold on
hte=text(out.tout(end),out.n(end),'n');
hte.FontSize=20;
%==========================================