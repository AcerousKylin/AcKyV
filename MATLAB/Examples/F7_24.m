% F7_24.m

close all
clear
clc

%原始图像
fxy=imread('lena.bmp');
subplot(2,2,1),imshow(fxy),xlabel('(a) 原始图像');
% imwrite(fxy,'.\F7_24a.bmp');

%傅里叶幅度谱的对数图像显示
fxy=double(fxy);
Fuv=fft2(fxy);        %二维傅里叶变换
ShiftFuv=fftshift(Fuv);
ABSShiftFuv=abs(ShiftFuv);      %傅里叶幅度谱
LogABSShiftFuv=log(ABSShiftFuv);     %傅里叶幅度谱的可视化
subplot(2,2,2),imshow(LogABSShiftFuv,[]),xlabel('(b) 傅里叶幅度谱对数图像'),colormap(gray),colorbar;

%截止频率D1=1,D0=10时的滤波效果
[N1,N2]=size(ShiftFuv);
D1=1;
D0=10;
n1=fix(N1/2);
n2=fix(N2/2);
for i=1:N1
    for j=1:N2
        d=sqrt((i-n1)^2+(j-n2)^2);
        if d>D0
            G(i,j)=ShiftFuv(i,j);
        else
            if d<D1
                G(i,j)=0;
            else
                Huv=(d-D1)/(D0-D1);
                G(i,j)=Huv*ShiftFuv(i,j);
            end
        end
    end
end
G=ifftshift(G);
g=ifft2(G);
g=uint8(real(g));
subplot(2,2,3),imshow(g),xlabel('(c) 滤波图像(D0=10,D1=1)');
% imwrite(g,'.\F7_24c.bmp');

%截止频率D1=10,D0=20时的滤波效果
[N1,N2]=size(ShiftFuv);
D1=10;
D0=20;
n1=fix(N1/2);
n2=fix(N2/2);
for i=1:N1
    for j=1:N2
        d=sqrt((i-n1)^2+(j-n2)^2);
        if d>D0
            G(i,j)=ShiftFuv(i,j);
        else
            if d<D1
                G(i,j)=0;
            else
                Huv=(d-D1)/(D0-D1);
                G(i,j)=Huv*ShiftFuv(i,j);
            end
        end
    end
end
G=ifftshift(G);
g=ifft2(G);
g=uint8(real(g));
subplot(2,2,4),imshow(g),xlabel('(d) 滤波图像(D0=20,D1=10)');
% imwrite(g,'.\F7_24d.bmp');
