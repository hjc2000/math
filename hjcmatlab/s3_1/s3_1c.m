clc;
clear;
kp=1;
ki=1;
kd=0;
st=1
sm=2
while true
   if(kd>sm)
       break;       
   end
   out=sim('s3_1');
   t=out.tout;
   y=out.simout;
   plot(t,y,'linewidth',2);
   hold on
   [om,n]=max(out.simout);
   hte=text(out.tout(n),out.simout(n),['kd=',num2str(kd)]);
   hte.FontSize=16;
   kd=kd+st;
end
ht=title('hjc');
ht.FontSize=16;