% F4_48.m

close all
clear
clc

I=imread('rice.png');
subplot(3,3,1),imshow(I),ylabel('原图像');
subplot(3,3,2),imhist(I);

%对数变换
c=255/log(1+255);
x=0:1:255;
y=c*log(1+x);
subplot(3,3,6),plot(x,y),axis tight,xlabel('f'),ylabel('g');
%绘制变换曲线
[m,n]=size(I);
K=double(I);

g=c*log(K+1);
%{
%等价的循环语句实现
for i=1:m
    for j=1:n
        g(i,j)=0;
        g(i,j)=c*log(K(i,j)+1);
    end
end
%}

subplot(3,3,4),imshow(uint8(g)),ylabel('对数变换');
subplot(3,3,5),imhist(uint8(g));

%###系统函数调用###
J=imadjust(I,[],[],0.216);
subplot(3,3,7),imshow(J),ylabel('对数变换(系统调用)');
subplot(3,3,8),imhist(J);
