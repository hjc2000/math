clc;
close all;
%==================================================
%控制器初始化
kp=1;
ki=0;
kd=0;

yi=0;

%==================================================
%被控对象及史密斯预估器参数
K1=1;
T1=2;
delay1=2;

K2=1.5;
T2=2.5;
delay2=2.5;
out=sim('smith_pre');
%==================================================
%超调计算
out_max=max(out.simout);
chaotiao=(out_max-1)*100
%==================================================
%画图
hf=figure(1);
plot(out.tout,out.simout);
grid on;
hold on;
%==================================================
%格式化图形
hf.OuterPosition=get(0,'screensize');%最大化图窗
hl=findobj('Type','Line');
len=length(hl);
for i=1:len
   hl(i).LineWidth=1.5; 
end
