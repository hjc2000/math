clc;
clear;
syms s t
L=1e-3;
R=1;
C=100e-6;
Gs=1/(L*C*s^2+L/R*s+1);
Uis=1/s;
Gt=ilaplace(Uis*Gs,s,t);
