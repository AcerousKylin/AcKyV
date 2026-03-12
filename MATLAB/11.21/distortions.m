close all
clear
clc

I = imread("SS8.jpg");
I = rgb2gray(I);    % 先将彩色图像变为灰度图像
subplot(2, 3, 1), imshow(I), xlabel("(a) 原始图像");

times = 4;
f = imresize(I, 1/times);
subplot(2, 3, 2), imshow(f), xlabel("(b) 失真图像");

% 方法一
g1 = interp2(double(f), "nearest");
% g1 = im2uint8(mat2gray(g1));
subplot(2, 3, 3), imshow(uint8(g1)), xlabel("(c) 最近邻近插值法");

% 方法2
g2 = interp2(double(f), "linear");
% g2 = im2uint8(mat2gray(g2));
subplot(2, 3, 4), imshow(uint8(g2)), xlabel("(d) 双线性插值");

% 方法3
g3 = interp2(double(f), "cubic");
% g3 = im2uint8(mat2gray(g3));
subplot(2, 3, 5), imshow(uint8(g3)), xlabel("(e) 双三次线性插值");