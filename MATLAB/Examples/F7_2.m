% F7_2.m

close all
clear
clc

f1xy=imread('eight.tif');
subplot(2,3,1),imshow(f1xy),xlabel('(a) 原始图像');
% imwrite(f1xy,'.\F7_2a.bmp');

f2xy=imnoise(f1xy,'salt & pepper',0.01);
subplot(2,3,2),imshow(f2xy),xlabel('(b) 噪声图像');
% imwrite(f2xy,'.\F7_2b.bmp');

fxy=double(f2xy);
Fuv=fft2(fxy);
FftShift=fftshift(Fuv);
AbsFftShift=abs(FftShift);
LogAbsFftShift=log(AbsFftShift);
subplot(2,3,3),imshow(LogAbsFftShift,[]),xlabel('(c) 噪声图像的傅里叶幅度谱对数图像'),colormap(gray),colorbar;

[N1,N2]=size(FftShift);
%截止频率D0=50时的滤波效果
D0=50;
n1=fix(N1/2);
n2=fix(N2/2);
for i=1:N1
    for j=1:N2
        d=sqrt((i-n1)^2+(j-n2)^2);
        if (d<=D0)
            G(i,j)=FftShift(i,j);
        else
            G(i,j)=0;
        end
    end
end
G=ifftshift(G);
g=ifft2(G);
g=uint8(real(g));
subplot(2,3,4),imshow(g),xlabel('(d) 滤波图像(\itD0=50)');
% imwrite(g,'.\F7_2d.bmp');

%截止频率D0=80时的滤波效果
D0=80;
n1=fix(N1/2);
n2=fix(N2/2);
for i=1:N1
    for j=1:N2
        d=sqrt((i-n1)^2+(j-n2)^2);
        if (d<=D0)
            G(i,j)=FftShift(i,j);
        else
            G(i,j)=0;
        end
    end
end
G=ifftshift(G);
g=ifft2(G);
g=uint8(real(g));
subplot(2,3,6),imshow(g),xlabel('(e) 滤波图像(\itD0=80)');
% imwrite(g,'.\F7_2e.bmp');
