%Order是缝合顺序，等于1时按照函数入口参数列表的顺序进行缝合，否则逆序
function txt=SewCharNum(Char,NumVar,Order)
    [~,lie]=size(NumVar);    %得出Num数组的行列数
    if(lie~=1)  %如果Num不是列向量
        NumVar=NumVar.';  %转置
        NumVar=NumVar(:,1);%只取出第一列,防一手，毕竟用户输入的
        %NumVar可能不按要求来，输入的不是向量，而是矩阵
    end
    NumVar=num2str(NumVar);
    [hang,~]=size(NumVar);
    if(Order)
        txt=[repelem(Char,hang,1),NumVar];
    else
        txt=[NumVar,repelem(Char,hang,1)];
    end
end