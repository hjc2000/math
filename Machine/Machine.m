% syms t
clc;
close all;
theta=2*pi/3;
t=0:1/50/100:1/50*5;
phiA=@(t)sin(2*pi*50*t);
phiB=@(t)sin(2*pi*50*t+2*pi/3);
phiC=@(t)sin(2*pi*50*t-2*pi/3);
% hold on
% plot(t,phiA(t));
% plot(t,phiB(t));
% plot(t,phiC(t));
phix=phiA(t)+phiB(t)*cos(theta)+phiC(t)*cos(theta);
phiy=phiB(t)*sin(theta)-phiC(t)*sin(theta);
theta2=atan(phiy./phix);
phi=(phix.^2+phiy.^2).^0.5;
figure(1)
subplot(2,2,1)
plot(t,phi);
htitle=title('磁场的大小随时间变化');
htitle.FontSize=20;
hlabel=ylabel('|\phi|');
hlabel.FontSize=20;
hlabel=xlabel('t');
hlabel.FontSize=20;

subplot(2,2,2)
plot(t,theta2);
htitle=title('磁场的相角随时间变化');
htitle.FontSize=20;
hlabel=ylabel('\theta');
hlabel.FontSize=20;
hlabel=xlabel('t');
hlabel.FontSize=20;
subplot(2,2,3)
plot(phix,phiy);
htitle=title('磁场矢量随时间变化画出的轨迹');
htitle.FontSize=20;
hlabel=ylabel('\phi x');
hlabel.FontSize=20;
hlabel=xlabel('\phi y');
hlabel.FontSize=20;
axis square
figure(2)
plot3(phix,phiy,t);
axis square
hlabel=xlabel('\phi x');
hlabel.FontSize=20;
hlabel=ylabel('\phi y');
hlabel.FontSize=20;
hlabel=zlabel('t');
hlabel.FontSize=20;