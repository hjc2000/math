function xLine(LeftLimit,RightLimit,Ypos,LineWidth,txtPos,txt)
    len=length(Ypos);
    for i=1:len
        plot([RightLimit,LeftLimit],[Ypos(i),Ypos(i)],'LineWidth',LineWidth,'LineStyle','--'); 
    end
    text(txtPos(1,:),txtPos(2,:),txt,'FontSize',16);
end