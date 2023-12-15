clc;
clear;
syms t w x
x=2/3*exp(-2*t)*sym('heaviside(t)');
X=fourier(x);
ezplot(abs(X),[-8*pi,8*pi]);