%求解内模的函数，phis 为输入信号和干扰信号的不稳定特征根组合起来构成的
%特征多项式的系数向量
function [Ac,Bc]=InternalModel(phis)
    [Ac,Bc,~,~]=tf2ss(1,phis);
    [Ac,Bc,~,~]=ChangeABCD(Ac,Bc,[],[]);
end