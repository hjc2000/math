clc;
clear;
close all;

syms t
w=50*2*pi;
f=w/(2*pi);
T=1/f;

ua=@(t)sin(w*t);
ub=@(t)sin(w*t-2*pi/3);
uc=@(t)sin(w*t+2*pi/3);

phiA=int(ua(t),t,0,t);
phiB=int(ub(t),t,0,t);
phiC=int(uc(t),t,0,t);

mA=int(phiA,t,0,T)/T
mB=int(phiB,t,0,T)/T
mC=int(phiC,t,0,T)/T

fphiA=matlabFunction(phiA);
fphiB=matlabFunction(phiB);
fphiC=matlabFunction(phiC);

phix=phiA-phiB*cosd(60)-phiC*cosd(60);
phiy=phiC*sind(60)-phiB*sind(60);
fphix=matlabFunction(phix);
fphiy=matlabFunction(phiy);

t=0:T/50:T*5;
figure(1);
plot(fphix(t),fphiy(t));
axis square
figure(2);
subplot(2,2,1)
plot(t,fphiA(t));
title('\fontsize{16}phiA');
subplot(2,2,2)
plot(t,fphiB(t));
title('\fontsize{16}phiB');
subplot(2,2,3)
plot(t,fphiC(t));
title('\fontsize{16}phiC');

m1=mean(fphiA(t))
m2=mean(fphiB(t))
m3=mean(fphiC(t))