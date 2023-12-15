clc;
clear;

A=[0,1,0,0; 0,5,0,0; 0,0,-7,0; 0,0,0,-8];
B=[1,1,3,4]';
C=[0,5,0,8];
r=rank(ctrb(A,B));
syms s
sA=s*eye(4)-A;
detsA=det(sA);
detsA=collect(detsA);
roor1=double(root(detsA,s)) %求出原始系统的极点

P=[-2,0,-7,-8];
k=place(A,B,P);
AP=A-B*k;
sAP=s*eye(4)-AP;
detsAP=det(sAP);
detsAP=collect(detsAP);
root2=double(root(detsAP,s))    %求出状态反馈系统的极点