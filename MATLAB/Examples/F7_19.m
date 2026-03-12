% F7_19.m

close all
clear
clc

%原始图像
fxy=imread('lena.bmp');
subplot(2,2,1),imshow(fxy),xlabel('(a) 原始图像');
% imwrite(fxy,'.\F7_19a.bmp');

%傅里叶幅度谱的对数图像显示
fxy=double(fxy);
Fuv=fft2(fxy);        %二维傅里叶变换
FftShift=fftshift(Fuv);
AbsFftShift=abs(FftShift);      %傅里叶幅度谱
LogAbsFftShift=log(AbsFftShift);     %傅里叶幅度谱的可视化
subplot(2,2,2),imshow(LogAbsFftShift,[]),xlabel('(b) 傅里叶幅度谱对数图像'),colormap(gray),colorbar;

[N1,N2]=size(FftShift);
% 滤波效果1
D0=10;
n=1;
n1=fix(N1/2);
n2=fix(N2/2);
for i=1:N1
    for j=1:N2
        d=sqrt((i-n1)^2+(j-n2)^2);
        Huv=1./(1+(D0./d).^(2*n));
        G(i,j)=FftShift(i,j)*Huv;
    end
end
G=ifftshift(G);
g=ifft2(G);
g=uint8(real(g));
subplot(2,2,3),imshow(g),xlabel('(c) 滤波图像(n=1,D0=10)');
% imwrite(g,'.\F7_19c.bmp');

% 滤波效果2
D0=20;
n=1;
n1=fix(N1/2);
n2=fix(N2/2);
for i=1:N1
    for j=1:N2
        d=sqrt((i-n1)^2+(j-n2)^2);
        Huv=1./(1+(D0./d).^(2*n));
        G(i,j)=FftShift(i,j)*Huv;
    end
end
G=ifftshift(G);
g=ifft2(G);
g=uint8(real(g));
subplot(2,2,4),imshow(g),xlabel('(d) 滤波图像(n=1,D0=20)');
% imwrite(g,'.\F7_19d.bmp');
