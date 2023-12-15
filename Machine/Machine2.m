clc;
close all;
syms t w amp
% A,B,C 三相绕组磁场
phiA=amp*sin(w*t);
phiB=amp*sin(w*t-2*pi/3);
phiC=amp*sin(w*t+2*pi/3);
% 变换到 x,y 坐标轴上
phix=phiA+phiB*cos(2*pi/3)+phiC*cos(2*pi/3);
phiy=phiB*sin(2*pi/3)-phiC*sin(2*pi/3);
% 得到磁场的幅值与相角，使用 simplify 函数化简计算结果
magPhi=(phix^2+phiy^2)^0.5;
magPhi=simplify(magPhi)
angPhi=atan(phiy/phix);
angPhi=simplify(angPhi)