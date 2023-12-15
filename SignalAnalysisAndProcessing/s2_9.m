clc;
clear;
%=========================================
wp=0.2*pi;
ws=0.5*pi;
fs=1/1e-6;
rs=30;
rp=3;
[n,wn]=buttord(wp/pi,ws/pi,rp,rs)
[Bz,Az]=butter(n,wp/pi)
[h,w]=freqz(Bz,Az,512,fs);
subplot(1,2,1)
plot(w,abs(h));
grid on
subplot(1,2,2)
plot(w,angle(h));
grid on