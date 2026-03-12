% Which is F4_5.m

close all
clear
clc

I = imread("lena.bmp");
subplot(2, 3, 1), imshow(I), xlabel("(a) 原始图像");
[m, n] = size(I);

X = imnoise(I, "gaussian", 0, 0.01);
subplot(2, 3, 2), imshow(X), xlabel("(b) 加噪图像");

J = zeros(m, n);
J = double(J);
for i=1:2
    X = imnoise(I, "gaussian");
    Y = double(X);
    J = J + Y / 2;
end
subplot(2, 3, 3), imshow(mat2gray(J)), xlabel("(c) 2图平均");

J = zeros(m, n);
J = double(J);
for i=1:4
    X = imnoise(I, "gaussian");
    Y = double(X);
    J = J + Y / 4;
end
subplot(2, 3, 4), imshow(mat2gray(J)), xlabel("(d) 4图平均");

J = zeros(m, n);
J = double(J);
for i=1:8
    X = imnoise(I, "gaussian");
    Y = double(X);
    J = J + Y / 8;
end
subplot(2, 3, 5), imshow(mat2gray(J)), xlabel("(d) 8图平均");

J = zeros(m, n);
J = double(J);
for i=1:16 
    X = imnoise(I, "gaussian");
    Y = double(X);
    J = J + Y / 16;
end
subplot(2, 3, 6), imshow(mat2gray(J)), xlabel("(d) 16图平均");