clc;
clear;
hang=2;
lie=2;
count=1;
%====================================
N=100;
n=0:1:N-1;
xn=sin(0.5*pi.*n);
XK=fft(xn,N);
XK=abs(XK);
stem(n,XK);
 