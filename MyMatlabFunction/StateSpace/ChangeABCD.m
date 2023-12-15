%因为 Matlab 的 ss 函数创建的状态空间模型的状态变量是我们学习的那种方式的列翻转
%所以使用此函数把 A,B,C,D 变换一下，变成我们学的那种。
%详见：https://www.yuque.com/qiaodangyi/idxf9y/qza941
function [Ac,Bc,Cc,Dc]=ChangeABCD(A,B,C,D)
    Ac=[];
    Bc=[];
    Cc=[];
    Dc=[];
    if(~isempty(A)) % A不为空，才有转换的可能，否则直接返回空矩阵。
        P=flip(eye(length(A)),1);
        Ac=P*A/P;
        if(~isempty(B))
            Bc=P*B;
        end
        if(~isempty(C))
            Cc=C/P; 
        end
        if(~isempty(D))
            Dc=D;
        end
    end
end