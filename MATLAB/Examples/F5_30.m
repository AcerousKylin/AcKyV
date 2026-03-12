% F5_30.m

close all
clear
clc

I=imread('lena.bmp');
subplot(2,3,1),imshow(I),xlabel('(a) 原始图像');
% imwrite(I,'.\F5_30a.bmp');

I=double(I);
[Gx,Gy]=gradient(I);
 G=sqrt(Gx.*Gx+Gy.*Gy);

J1=G;
subplot(2,3,2),imshow(uint8(J1)),xlabel('(b) 梯度法滤波图像');
% % imwrite(uint8(J1),'.\F5_30b.bmp');
% 
J2=I;
K=find(G>=7);
J2(K)=G(K);
subplot(2,3,3),imshow(uint8(J2)),xlabel('(c) 第一种情况滤波图像');
% % imwrite(uint8(J2),'.\F5_30c.bmp');
% 
J3=I;
K=find(G>=7);
J3(K)=255;
subplot(2,3,4),imshow(uint8(J3)),xlabel('(d) 第二种情况滤波图像');
% % imwrite(uint8(J3),'.\F5_30d.bmp');
% 
J4=G;
K=find(G<=7);
J4(K)=255;
subplot(2,3,5),imshow(uint8(J4)),xlabel('(e) 第三种情况滤波图像');
% % imwrite(uint8(J4),'.\F5_30e.bmp');
% 
J5=I;
K=find(G<=7);
J5(K)=0;
Q=find(G>=7);
J5(Q)=255;
subplot(2,3,6),imshow(uint8(J5)),xlabel('(f) 第四种情况滤波图像');
% % imwrite(uint8(J5),'.\F5_30f.bmp');
