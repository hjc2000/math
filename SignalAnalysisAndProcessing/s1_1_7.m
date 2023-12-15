clc;
clear;
syms X t w
X=-j*2*w/(16+w^2);
x=ifourier(X,w,t);
ezplot(x,[-5,5]);