%渐进跟踪与干扰抑制中配置组合系统的闭环极点
function [K,Kc]=TrackerPlace(Ac,Bc,A,B,C,D,P)
    syms s
    LenKc=length(Ac);
    LenK=length(A);
    Kc=sym('kc',[1,LenKc]);
    K=sym('k',[1,LenK]);
    Az=[A-B*K,B*Kc; -Bc*C+Bc*D*K,Ac-Bc*D*Kc];%组合系统状态方程
    LenAz=length(Az);
    detKKc=det(s*eye(LenAz)-Az);
    detKKc=coeffs(detKKc,s);
    detKKc=flip(detKKc);    %实际的组合系统特征多项式
    detKKcx=poly(P);    %期望的组合系统特征多项式
    soKKc=solve(detKKc==detKKcx,[K,Kc]);
    soK=zeros(1,LenK);
    soKc=zeros(1,LenKc);
    for i=1:LenK
       soK(i)=soKKc.(['k',num2str(i)]);
    end
    for i=1:LenKc
       soKc(i)=soKKc.(['kc',num2str(i)]); 
    end
    K=soK;
    Kc=soKc;
end