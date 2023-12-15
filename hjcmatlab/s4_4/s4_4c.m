clc;
clear;
A=[0,1,0,0; 13.475,0,0,0; 0,0,0,1; -0.98,0,0,0];
B=[0;-0.25;0;0.2];
C=[1,0,0,0; 0,0,1,0];
rQc=rank(ctrb(A,B));
rQo=rank(obsv(A,C));
P=[-5,-5.2,-5.6,-6];
PG=[-20,-21,-22,-23];
K=place(A,B,P)
G=place(A',C',PG)' 
out=sim('s4_4');

subplot(2,1,1)
plot(out.tout,out.y,'linewidth',2);
grid on
[ym,n]=max(out.y);
hte=text(out.tout(n),ym,['y(1)';'y(2)']);
for i=1:length(hte)
   hte(i).FontSize=20; 
end
ht=title('hjc');
ht.FontSize=20;

subplot(2,1,2)
plot(out.tout,out.y1,'linewidth',2);
grid on
[ym,n]=max(out.y);
hte=text(out.tout(n),ym,['y1(1)';'y1(2)']);
for i=1:length(hte)
   hte(i).FontSize=20; 
end
ht=title('hjc');
ht.FontSize=20;