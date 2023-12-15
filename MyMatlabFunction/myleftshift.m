function re=myleftshift(X,n)
    len=length(X);
    X=flip(X);
    X=[X,repelem(0,n)];
    X=circshift(X,n);
    X=X(1:len);
    re=flip(X);
end