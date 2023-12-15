clc;
clear;

A=[-0.3,0.1,-0.05; 1,0.1,0; -1.5,-8.9,-0.05];
B=[2,0,4]';
C=[1,2,3];
P=repelem(-1,length(A));
rQc=rank(ctrb(A,B));%求出能控矩阵的秩
rQo=rank(obsv(A,C));%求出能观矩阵的秩
K=myplace(A,B,P)

PG=[-4,-5,-6];      %状态观测器的极点
G=myplace(A',C',PG)'  %使用我的函数配置极点
G1=place(A',C',PG)'   %使用maltab的函数验证我的函数的正确性