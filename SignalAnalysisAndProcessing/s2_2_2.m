clc;
clear;

N=128*2e4;
Ts=0.125;
t=0:Ts:(N-1)*Ts;
xt=sinc(t./pi);
n=0:1:N-1;
XK=fft(xt,N);
magXK=abs(XK);
phaXK=angle(XK);
subplot(1,2,1)
stem(n,magXK);
subplot(1,2,2)
stem(n,phaXK);
