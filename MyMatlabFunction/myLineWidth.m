function myLineWidth(LineWidth)
    hl=findobj('Type','Line');
    len=length(hl);
    for i=1:len
       hl(i).LineWidth=LineWidth; 
    end
end