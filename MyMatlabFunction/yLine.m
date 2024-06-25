function yLine(UpLimit,DownLimit,Xpos,LineWidth,txtPos,txt)
    len=length(Xpos);
    for i=1:len
        plot([Xpos(i),Xpos(i)],[UpLimit,DownLimit],'LineWidth',LineWidth,'LineStyle','--'); 
    end
    text(txtPos(1,:),txtPos(2,:),txt,'FontSize',16);
end