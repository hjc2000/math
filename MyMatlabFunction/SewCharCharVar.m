%Order是缝合顺序，等于1时按照函数入口参数列表的顺序进行缝合，否则逆序

%字符串向量其实是一个矩阵，矩阵的每一行是一个字符串，所以他其实不能叫做向量
%matlab使用矩阵存放char类型的变量是，矩阵中的每一个元素都是一个char类型的字符，
%一整行的字符组成一个字符串。字符串按行储存。
function txt=SewCharCharVar(Char,CharVar,Order)
    [hang,~]=size(CharVar);    %得出字符数组的行数，即字符串的个数
    if(Order)
        txt=[repelem(Char,hang,1),CharVar];
    else
        txt=[CharVar,repelem(Char,hang,1)];
    end
end