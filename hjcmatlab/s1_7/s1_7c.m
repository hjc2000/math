clc;
clear;
den=[1,3,3,4,5];
num=[1];
[a,b,c,d]=tf2ss(num,den);
y0=[1,0.5,0.5,0.2];