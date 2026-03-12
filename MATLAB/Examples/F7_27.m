% F7_27.m

close all
clear
clc

%原始图像
fxy=imread('lena.bmp');
subplot(2,2,1),imshow(fxy),xlabel('(a) 原始图像');
% imwrite(fxy,'.\F7_27a.bmp');

%傅里叶幅度谱的对数图像显示
fxy=double(fxy);
Fuv=fft2(fxy);        %二维傅里叶变换
ShiftFuv=fftshift(Fuv);
ABSShiftFuv=abs(ShiftFuv);      %傅里叶幅度谱
LogABSShiftFuv=log(ABSShiftFuv);     %傅里叶幅度谱的可视化
%subplot(2,4,2),imshow(LogABSShiftFuv,[]),xlabel('(a-2)傅里叶幅度谱的对数图像显示');

%截止频率D0=10时的滤波效果
[N1,N2]=size(ShiftFuv);
D0=10;
n1=fix(N1/2);
n2=fix(N2/2);
for i=1:N1
    for j=1:N2
        d=sqrt((i-n1)^2+(j-n2)^2);
        Huv=1-exp(-d^2/(2*D0^2));
        G(i,j)=ShiftFuv(i,j)*Huv;
    end
end
G=ifftshift(G);
g=ifft2(G);
g=uint8(real(g));
subplot(2,2,2),imshow(g),xlabel('(b) GHPF滤波(D0=10)');
% imwrite(g,'.\F7_27b.bmp');

%截止频率D0=10,k=1,c=0.6时的GHPF滤波效果
[N1,N2]=size(ShiftFuv);
D0=10;
k=1;
c=0.6;
n1=fix(N1/2);
n2=fix(N2/2);
for i=1:N1
    for j=1:N2
        d=sqrt((i-n1)^2+(j-n2)^2);
        Huv=1-exp(-d^2/(2*D0^2));
        Huv=k*Huv+c;   %--------%
        G(i,j)=ShiftFuv(i,j)*Huv;
    end
end
G=ifftshift(G);
g=ifft2(G);
g=uint8(real(g));
subplot(2,2,3),imshow(g),xlabel('(c) GHPF增强滤波(D0=10,k=1,c=0.6)');
% imwrite(g,'.\F7_27c.bmp');

%截止频率D0=10,k=3,c=0.6时的GHPF滤波效果
[N1,N2]=size(ShiftFuv);
D0=10;
k=3;
c=0.6;
n1=fix(N1/2);
n2=fix(N2/2);
for i=1:N1
    for j=1:N2
        d=sqrt((i-n1)^2+(j-n2)^2);
        Huv=1-exp(-d^2/(2*D0^2));
        Huv=k*Huv+c;
        G(i,j)=ShiftFuv(i,j)*Huv;
    end
end
G=ifftshift(G);
g=ifft2(G);
g=uint8(real(g));
subplot(2,2,4),imshow(g),xlabel('(d) GHPF增强滤波(D0=10,k=3,c=0.6)');
% imwrite(g,'.\F7_27d.bmp');
