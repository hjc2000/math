clc;
clear;
lie=2;
hang=4;
%==============================
f1=15;
f2=18;
fs=50;
N=16;
t=0:1/fs:(N-1)*1/fs;
xt=sin(2*pi*f1.*t)+2.*sin(2*pi*f2.*t);
XK=fft(xt,N);
n=0:1:N-1;
magXK=abs(XK);
phaXK=angle(XK);
subplot(hang,lie,1);
stem(n,magXK);
title('magXK fs=50 N=16')
subplot(hang,lie,2);
stem(n,phaXK);
title('phaXK fs=50 N=16')
%==============================
fs=36;
N=16;
t=0:1/fs:(N-1)*1/fs;
xt=sin(2*pi*f1.*t)+2.*sin(2*pi*f2.*t);
XK=fft(xt,N);
n=0:1:N-1;
magXK=abs(XK);
phaXK=angle(XK);
subplot(hang,lie,3);
stem(n,magXK);
title('magX1K fs=36 N=16')
subplot(hang,lie,4);
stem(n,phaXK);
title('phaX1K fs=36 N=16')
%==============================
fs=50;
N=32;
t=0:1/fs:(N-1)*1/fs;
xt=sin(2*pi*f1.*t)+2.*sin(2*pi*f2.*t);
XK=fft(xt,N);
n=0:1:N-1;
magXK=abs(XK);
phaXK=angle(XK);
subplot(hang,lie,5);
stem(n,magXK);
title('magX2K fs=50 N=32')
subplot(hang,lie,6);
stem(n,phaXK);
title('phaX2K fs=50 N=32')
%==============================
fs=300;
N=64;
t=0:1/fs:(N-1)*1/fs;
xt=sin(2*pi*f1.*t)+2.*sin(2*pi*f2.*t);
XK=fft(xt,N);
n=0:1:N-1;
magXK=abs(XK);
phaXK=angle(XK);
subplot(hang,lie,7);
stem(n,magXK);
title('magX3K fs=300 N=64')
subplot(hang,lie,8);
stem(n,phaXK);
title('phaX3K fs=300 N=64')