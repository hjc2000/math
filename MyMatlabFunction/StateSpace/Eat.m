%求解状态转移矩阵
function eat=Eat(A)
    syms s
    SIA=s*eye(length(A))-A;
    SIAn=inv(SIA);
    eat=ilaplace(SIAn);
end