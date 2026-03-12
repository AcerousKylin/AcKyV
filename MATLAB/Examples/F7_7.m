% F7_7.m

close all
clear
clc

f1xy=imread('eight.tif');
subplot(2,3,1),imshow(f1xy),xlabel('(a) 原始图像');
% imwrite(f1xy,'.\F7_7a.bmp');

f2xy=imnoise(f1xy,'salt & pepper',0.05);
subplot(2,3,2),imshow(f2xy),xlabel('(b) 噪声图像');
% imwrite(f2xy,'.\F7_7b.bmp');

fxy=double(f2xy);
Fuv=fft2(fxy);
FftShift=fftshift(Fuv);
AbsFftShift=abs(FftShift);
LogAbsFftShift=log(AbsFftShift);
subplot(2,3,3),imshow(LogAbsFftShift,[]),xlabel('(c) 噪声图像的傅里叶幅度谱对数图像'),colormap(gray),colorbar;

[N1,N2]=size(FftShift);

%阶数n=2，截止频率D0=40时的滤波效果
n=2;
D0=40;
n1=fix(N1/2);
n2=fix(N2/2);
for i=1:N1
    for j=1:N2
        d=sqrt((i-n1)^2+(j-n2)^2);
        H=1/(1+(sqrt(2)-1)*(d/D0)^(2*n));
        G(i,j)=H*FftShift(i,j);
    end
end
G=ifftshift(G);
g=ifft2(G);
g=uint8(real(g));
subplot(2,3,4),imshow(g),xlabel('(d) 滤波图像({\itn}=2,{\itD}0=40)');
% imwrite(g,'.\F7_7d.bmp');

%阶数n=2，截止频率D0=60时的滤波效果
n=2;
D0=60;
n1=fix(N1/2);
n2=fix(N2/2);
for i=1:N1
    for j=1:N2
        d=sqrt((i-n1)^2+(j-n2)^2);
        H=1/(1+(sqrt(2)-1)*(d/D0)^(2*n));
        G(i,j)=H*FftShift(i,j);
    end
end
G=ifftshift(G);
g=ifft2(G);
g=uint8(real(g));
subplot(2,3,6),imshow(g),xlabel('(e) 滤波图像(n=2,D0=60)');
% imwrite(g,'.\F7_7e.bmp');
