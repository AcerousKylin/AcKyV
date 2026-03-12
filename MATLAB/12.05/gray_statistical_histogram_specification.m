% Which is F4_34

close all
clear
clc

I = imread("tire.tif");
subplot(2, 3, 1), imshow(I), xlabel("(a) 原始图像");
subplot(2, 3, 2), imshow(I), xlabel(["(b) 原始图像的", "灰度统计直方图"]);

% 规定化为只有2个灰度级
J = histeq(I, 2);
subplot(2, 3, 3), imshow(J), xlabel("(c) 规定化为2个灰度级");
subplot(2, 3, 4), imshow(J), xlabel(["(d) 5个灰度级图像的", "灰度统计直方图"]);

% 规定化为只有10个灰度级
K = histeq(I, 10);
subplot(2, 3, 5), imshow(K), xlabel("(e) 规定化为10个灰度级");
subplot(2, 3, 6), imshow(K), xlabel(["(f) 10个灰度级图像的", "灰度统计直方图"]);