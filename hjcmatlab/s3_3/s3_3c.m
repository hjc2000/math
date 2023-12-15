clc;
clear;

kp=4.4156;
kd=0.067;
kis=[20,120,300];
for i=1:length(kis)
    ki=kis(i);
    out=sim('s3_3');
    plot(out.tout,out.simout,'linewidth',2);
    hold on
    ht=title('黄锦灿');
    ht.FontSize=16;
    hte=text(out.tout(26),out.simout(26),['ki=',num2str(ki)]);
    hte.FontSize=16;
end
