% hte:  标注文字的句柄，由text函数返回
% Size:  标注文字的大小
% hf:  figure函数返回的句柄
% Title: 想要在图窗加入的标题
function myPlotFormat(hf,LineWidth,htxt,Size,Title,Hold)
    if(Hold)
        hold on
    else
        hold off
    end
    grid on
    
    len=length(htxt);
    for i=1:len
       htxt(i).FontSize=Size; 
    end
     
for hl=findobj('Type','Line')
   hl.LineWidth=LineWidth; 
end
    
    ht=title(Title);
    ht.FontSize=20;
    hf.OuterPosition=get(0,'screensize');   %把图窗最大化
end