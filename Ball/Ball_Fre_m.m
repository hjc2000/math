clc;
close all
%==================================
%频域设计
%==================================
numf=1.853;
denf=[1,0,0];
Gs=tf(numf,denf);
hf=figure(1);
bode(Gs);
myPlotFormat([],[],hf,[],1);
%==================================
out=sim('Ball_Fre');
hf=figure(2);
plot(out.tout,out.y);
myPlotFormat([],[],hf,[],1);
%==================================