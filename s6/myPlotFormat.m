% hte:  标注文字的句柄，由text函数返回
% Size:  标注文字的大小
% hf:  figure函数返回的句柄
% Title: 想要在图窗加入的标题
function myPlotFormat(hte,Size,hf,Title)
    len=length(hte);
    for i=1:len
       hte(i).FontSize=Size; 
    end
    grid on
    hl=findobj('Type','Line');
    len=length(hl);
    for i=1:len
       hl(i).LineWidth=2; 
    end
    ht=title(['hjc',Title]);
    ht.FontSize=20;
    hf.OuterPosition=get(0,'screensize');
end