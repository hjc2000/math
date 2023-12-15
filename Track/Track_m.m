clc;
close all;
tm=5;
syms s
w=1;
phis=s*(s^2+w^2);
phis=sym2poly(phis);
[Ac,Bc]=InternalModel(phis);
A=[0,1; 1,1];
B=[0;1];
C=[1,0];
D=0;
is=IsCombSysCtrb(phis,A,B,C,D);
% P=[-1,-0.5+1j,-0.5-1j,-2+1j,-2-1j];
P1=[-1+1j,-1-1j];
P2=[-10,-11,-12].*10;
P=[P1,P2];
[K,Kc]=TrackerPlace(Ac,Bc,A,B,C,D,P)
out=sim('Track');
hf=figure(1);
plot(out.tout,out.y);
myPlotFormat(hf,1,[],[],[],1);
