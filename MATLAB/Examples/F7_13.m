% F7_13.m

close all
clear
clc

f1xy=imread('eight.tif');
subplot(2,3,1),imshow(f1xy),xlabel('(a) 原始图像');
% imwrite(f1xy,'.\F7_13a.bmp');

f2xy=imnoise(f1xy,'salt & pepper');
subplot(2,3,2),imshow(f2xy),xlabel('(b) 噪声图像');
% imwrite(f2xy,'.\F7_13b.bmp');

fxy=double(f2xy);
Fuv=fft2(fxy);
FftShift=fftshift(Fuv);
AbsFftShift=abs(FftShift);
LogAbsFftShift=log(AbsFftShift);
subplot(2,3,3),imshow(LogAbsFftShift,[]),xlabel('(c) 噪声图像的傅里叶幅度谱对数图像'),colormap(gray),colorbar;

[N1,N2]=size(FftShift);

%截止频率D0=20,D1=40时的滤波效果
D0=20;
D1=40;
n1=fix(N1/2);
n2=fix(N2/2);
for i=1:N1
    for j=1:N2
        d=sqrt((i-n1)^2+(j-n2)^2);
        if d<D0
            G(i,j)=FftShift(i,j);
        else
            if d>D1
                G(i,j)=0;
            else
                H=(d-D1)/(D0-D1);
                G(i,j)=H*FftShift(i,j);
            end
        end
    end
end
G=ifftshift(G);
g=ifft2(G);
g=uint8(real(g));
subplot(2,3,4),imshow(g),xlabel('(d) 滤波图像(D0=20,D1=40)');
% imwrite(g,'.\F7_13d.bmp');

%截止频率D0=40,D1=80时的滤波效果
D0=40;
D1=80;
n1=fix(N1/2);
n2=fix(N2/2);
for i=1:N1
    for j=1:N2
        d=sqrt((i-n1)^2+(j-n2)^2);
        if d<D0
            G(i,j)=FftShift(i,j);
        else
            if d>D1
                G(i,j)=0;
            else
                H=(d-D1)/(D0-D1);
                G(i,j)=H*FftShift(i,j);
            end
        end
    end
end
G=ifftshift(G);
g=ifft2(G);
g=uint8(real(g));
subplot(2,3,6),imshow(g),xlabel('(e) 滤波图像(D0=40,D1=80)');
% imwrite(g,'.\F7_13e.bmp');
