clc;
close all
%=================================
% kp=10;
% ki=0;
% kd=0;;
% while(kd<10);
%     out=sim('Ball_PID');
%     hf=figure(1);
%     plot(out.tout,out.y);
%     [ym,n]=max(out.y);
%     hte=text(out.tout(n),ym,['kd=',num2str(kd)]);
%     myPlotFormat(hte,16,hf,'输出',1);
%     kd=kd+2;
% end

%==================================
% kp=10;
% ki=0;
% kd=10;
% while(ki<10);
%     out=sim('Ball_PID');
%     hf=figure(1);
%     plot(out.tout,out.y);
%     [ym,n]=max(out.y);
%     hte=text(out.tout(n),ym,['ki=',num2str(ki)]);
%     myPlotFormat(hte,16,hf,'输出',1);
%     ki=ki+2;
% end

%==================================
% kp=10;
% ki=0;
% kd=10;;
% while(kp<20);
%     out=sim('Ball_PID');
%     hf=figure(1);
%     plot(out.tout,out.y);
%     [ym,n]=max(out.y);
%     hte=text(out.tout(n),ym,['kp=',num2str(kp)]);
%     myPlotFormat(hte,16,hf,'输出',1);
%     kp=kp+4;
% end