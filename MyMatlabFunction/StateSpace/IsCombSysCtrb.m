% 判断组合系统是否能控
function re=IsCombSysCtrb(phis,A,B,C,D)
    n=length(A);
    [m,~]=size(C);
    rootPhis=roots(phis);
    lenr=length(rootPhis);
    Rank=zeros(1,lenr);
    for i=1:lenr
       Ctrb=[rootPhis(i).*eye(n)-A,B; -C,D];
       Rank(i)=rank(Ctrb);
    end
    re=1;
    for i=1:lenr
       if(Rank(i)~=n+min([m,n]))
           re=0;
       end
    end
end