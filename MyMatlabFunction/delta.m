%单位抽样函数，n不能是矩阵，必须是一个数。可以使用如下方式调用这个函数
% t=0:0.01:5;
% f=@(t) delta(t)+delta(t-1)+2*delta(t-2);
% a=arrayfun(f,t);
% stem(t,a)
function re=delta(n)
    if(n==0)
       re=1; 
    else
       re=0;
    end
end