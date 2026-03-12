% F5_26.m

close all
clear
clc

I=imread('lena.bmp');
subplot(3,3,1),imshow(I),xlabel('(a) 原始图像');
% imwrite(I,'.\F5_26a.bmp');

mask1=fspecial('laplacian',0)
LB1=filter2(mask1,I);
subplot(3,3,2),imshow(uint8(LB1)),text(-14,285,'(b) 负中心系数的水平垂直模板滤波图像');
% imwrite(uint8(LB1),'.\F5_26b.bmp.bmp');
subplot(3,3,3),imshow(uint8(double(I)-LB1)),xlabel('(c) 负中心系数的水平垂直模板减法叠加图像');
% imwrite(uint8(double(I)-LB1),'.\F5_26c.bmp');

mask2=-mask1
LB2=filter2(mask2,I);
subplot(3,3,4),imshow(uint8(LB2)),text(-14,285,'(d) 正中心系数的水平垂直模板滤波图像');
% imwrite(uint8(LB2),'.\F5_26d.bmp.bmp');
subplot(3,3,5),imshow(uint8(double(I)+LB2)),xlabel('(e) 正中心系数的水平垂直模板加法叠加图像');
% imwrite(uint8(double(I)+LB2),'.\F5_26e.bmp');

mask3=[1  1   1
       1  -8  1
       1  1   1]
LB3=filter2(mask3,I);
subplot(3,3,6),imshow(uint8(LB3)),text(-28,285,'(f) 负中心系数的水平垂直对角模板滤波图像');
% imwrite(uint8(LB3),'.\F5_26f.bmp');
subplot(3,3,7),imshow(uint8(double(I)-LB3)),xlabel('(g) 负中心系数的水平垂直对角模板减法叠加图像');
% imwrite(uint8(double(I)-LB3),'.\F5_26g.bmp');

mask4=-mask3
LB4=filter2(mask4,I);
subplot(3,3,8),imshow(uint8(LB4)),text(-28,285,'(h) 正中心系数的水平垂直对角模板滤波图像');
% imwrite(uint8(LB4),'.\F5_26h.bmp');
subplot(3,3,9),imshow(uint8(double(I)+LB4)),xlabel('(i) 正中心系数的水平垂直对角模板加法叠加图像');
% imwrite(uint8(double(I)+LB4),'.\F5_26i.bmp');
