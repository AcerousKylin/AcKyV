% F7_9.m

close all
clear
clc

%原始图像
fxy=imread('lena.bmp');
subplot(2,2,1),imshow(fxy),xlabel('(a) 原始图像');
% imwrite(uint8(fxy),'.\F7_9a.bmp');

%傅里叶变换
fxy=double(fxy);
Fuv=fft2(fxy);        %二维傅里叶变换
ShiftFuv=fftshift(Fuv);
[N1,N2]=size(ShiftFuv);

% %截止频率D0=30时的理想低通滤波器的滤波效果
% D0=30;
% n1=fix(N1/2);
% n2=fix(N2/2);
% for i=1:N1
%     for j=1:N2
%         d=sqrt((i-n1)^2+(j-n2)^2);
%         if (d<=D0)
%             G(i,j)=ShiftFuv(i,j);
%         else
%             G(i,j)=0;
%         end
%     end
% end
% G=ifftshift(G);
% g=ifft2(G);
% g=uint8(real(g));
% subplot(1,3,2),imshow(g),xlabel('(b)理想低通滤波器的滤波图像(D0=30)');

% 阶数n=1，截止频率D0=30时的巴特沃斯低通滤波器的滤波效果
n=1;
D0=30;
n1=fix(N1/2);
n2=fix(N2/2);
for i=1:N1
    for j=1:N2
        d=sqrt((i-n1)^2+(j-n2)^2);
        H=1/(1+(sqrt(2)-1)*(d/D0)^(2*n));
        G(i,j)=H*ShiftFuv(i,j);
    end
end
G=ifftshift(G);
g=ifft2(G);
g=uint8(real(g));
subplot(2,2,2),imshow(g),xlabel('(b) 滤波图像(n=1,D0=30)');
% imwrite(uint8(g),'.\F7_9b.bmp');

% 阶数n=10，截止频率D0=30时的巴特沃斯低通滤波器的滤波效果
n=10;
D0=30;
n1=fix(N1/2);
n2=fix(N2/2);
for i=1:N1
    for j=1:N2
        d=sqrt((i-n1)^2+(j-n2)^2);
        H=1/(1+(sqrt(2)-1)*(d/D0)^(2*n));
        G(i,j)=H*ShiftFuv(i,j);
    end
end
G=ifftshift(G);
g=ifft2(G);
g=uint8(real(g));
subplot(2,2,3),imshow(g),xlabel('(c) 滤波图像(n=10,D0=30)');
% imwrite(uint8(g),'.\F7_9c.bmp');

% 阶数n=20，截止频率D0=30时的巴特沃斯低通滤波器的滤波效果
n=20;
D0=30;
n1=fix(N1/2);
n2=fix(N2/2);
for i=1:N1
    for j=1:N2
        d=sqrt((i-n1)^2+(j-n2)^2);
        H=1/(1+(sqrt(2)-1)*(d/D0)^(2*n));
        G(i,j)=H*ShiftFuv(i,j);
    end
end
G=ifftshift(G);
g=ifft2(G);
g=uint8(real(g));
subplot(2,2,4),imshow(g),xlabel('(d) 滤波图像(n=20,D0=30)');
% imwrite(uint8(g),'.\F7_9d.bmp');
