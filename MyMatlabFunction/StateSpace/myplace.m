function K=myplace(A,B,P)
    polyA=poly(A);%求出A的特征多项式
    polyP=poly(P);%求出极点向量P的特征多项式
    fpA=flip(polyA);
    fpP=flip(polyP);
    Kb=fpP(1:end-1)-fpA(1:end-1);
    cutKb=fpA(2:end-1);
    len=length(cutKb);
    a1=[cutKb,1];
    temp=zeros(len+1,len+1);
    for n=1:len+1
        temp(n,:)=myleftshift(a1,n-1);%调用myleftshift函数实现a1向量的左移，
        %移出的位置用0补
    end
    Q=ctrb(A,B)*temp;
    K=Kb/Q;
end