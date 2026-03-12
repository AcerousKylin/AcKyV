% F7_5.m

close all
clear
clc

%原始图像
fxy=imread('lena.bmp');
subplot(2,3,1),imshow(fxy),xlabel('(a) 原始图像');

%傅里叶幅度谱的对数图像显示
fxy=double(fxy);
Fuv=fft2(fxy);        %二维傅里叶变换
ShiftFuv=fftshift(Fuv);
ABSShiftFuv=abs(ShiftFuv);      %傅里叶幅度谱
LogABSShiftFuv=log(ABSShiftFuv);     %傅里叶幅度谱的可视化
subplot(2,3,2),imshow(LogABSShiftFuv,[]),xlabel('(b) 傅里叶幅度谱对数图像');

%截止频率D0=5时的滤波效果
[N1,N2]=size(ShiftFuv);
D0=5;
energy=0;
n1=fix(N1/2);
n2=fix(N2/2);
for i=1:N1
    for j=1:N2
        d=sqrt((i-n1)^2+(j-n2)^2);
        if (d<=D0)
            G(i,j)=ShiftFuv(i,j);
            energy=energy+ABSShiftFuv(i,j);
        else
            G(i,j)=0;
        end
    end
end
G=ifftshift(G);
g=ifft2(G);
g=uint8(real(g));
subplot(2,3,3),imshow(g),xlabel('(c) 滤波图像(\itD0=5)');
energy/sum(ABSShiftFuv(:))

%截止频率D0=11时的滤波效果
[N1,N2]=size(ShiftFuv);
D0=12;
energy=0;
n1=fix(N1/2);
n2=fix(N2/2);
for i=1:N1
    for j=1:N2
        d=sqrt((i-n1)^2+(j-n2)^2);
        if (d<=D0)
            G(i,j)=ShiftFuv(i,j);
            energy=energy+ABSShiftFuv(i,j);
        else
            G(i,j)=0;
        end
    end
end
G=ifftshift(G);
g=ifft2(G);
g=uint8(real(g));
subplot(2,3,4),imshow(g),xlabel('(d) 滤波图像(\itD0=12)');
energy/sum(ABSShiftFuv(:))

%截止频率D0=45时的滤波效果
[N1,N2]=size(ShiftFuv);
D0=44;
energy=0;
n1=fix(N1/2);
n2=fix(N2/2);
for i=1:N1
    for j=1:N2
        d=sqrt((i-n1)^2+(j-n2)^2);
        if (d<=D0)
            G(i,j)=ShiftFuv(i,j);
            energy=energy+ABSShiftFuv(i,j);
        else
            G(i,j)=0;
        end
    end
end
G=ifftshift(G);
g=ifft2(G);
g=uint8(real(g));
subplot(2,3,5),imshow(g),xlabel('(e) 滤波图像(\itD0=44)');
energy/sum(ABSShiftFuv(:))

%截止频率D0=68时的滤波效果
[N1,N2]=size(ShiftFuv);
D0=72;
energy=0;
n1=fix(N1/2);
n2=fix(N2/2);
for i=1:N1
    for j=1:N2
        d=sqrt((i-n1)^2+(j-n2)^2);
        if (d<=D0)
            G(i,j)=ShiftFuv(i,j);
            energy=energy+ABSShiftFuv(i,j);
        else
            G(i,j)=0;
        end
    end
end
G=ifftshift(G);
g=ifft2(G);
g=uint8(real(g));
subplot(2,3,6),imshow(g),xlabel('(f) 滤波图像(\itD0=72)');
energy/sum(ABSShiftFuv(:))
