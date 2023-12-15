clc;
clear;
close all;

P=[1,1,1,0; 1,1,0,1; 1,0,1,1; 0,1,1,1];
syms y
Y=repelem(y,4,1);
X=sym('x',[4,1]);
B=Y-X;
A=P\B;
A=subs(A,X,[3,2,1,3]');
A=subs(A,y,3);

for i=1:4
    if(A(i)<0)
       A(i)=A(i)+3; 
    end
end
A