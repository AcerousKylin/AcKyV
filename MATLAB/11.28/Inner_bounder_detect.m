close all 
clear
clc

Image = imread("rice.png");
Image = imbinarize(Image);
% Image = rgb2gray(Image);
ImageSize = size(Image);
row = ImageSize(1, 1);
col = ImageSize(1, 2);

%% 第1步：左移
ImageLA = Image;
subplot(5, 4, 1), imshow(ImageLA), xlabel("(a1) 原始图像"), ylabel("第1步：左移");

ImageLB = ImageLA;
ImageLB(:, 1) = [];
ImageLB = [ImageLB ones(row, 1)];
subplot(5, 4, 2), imshow(ImageLB), xlabel("(b1) 左移1个像素");

ImageLC = ImageLA | ImageLB;
subplot(5, 4, 3), imshow(ImageLC), xlabel("(c1) a OR b");

ImageLD = xor(ImageLA, ImageLC);
subplot(5, 4, 4), imshow(ImageLD), xlabel("(d1) a XOR c");

%% 第2步：右移
ImageRA = Image;
subplot(5, 4, 5), imshow(ImageRA), xlabel("(a2) 原始图像"), ylabel("第2步，=：右移");
ImageRB = ImageRA;
ImageRB(:, col) = [];
ImageRB = [ones(row, 1) ImageRB];
subplot(5, 4, 6), imshow(ImageRB), xlabel("(b2) 右移1个像素");
ImageRC = ImageRA | ImageRB;
subplot(5, 4, 7), imshow(ImageRC), xlabel("(c2) a OR b");

ImageRD = xor(ImageRA, ImageRC);
subplot(5, 4, 8), imshow(ImageRD), xlabel("(d2) a XOR c");

%% 第3步：上移
ImageUA = Image;
subplot(5, 4, 9), imshow(ImageUA), xlabel("(a3) 原始图像"), ylabel("第3步：上移");

ImageUB = ImageUA;
ImageUB(1, :) = [];
ImageUB = [ImageUB; ones(1, col)];
subplot(5, 4, 10), imshow(ImageUB), xlabel("(b3) 上移1个像素");

ImageUC = ImageUA | ImageUB;
subplot(5, 4, 11), imshow(ImageUC), xlabel("(c3) a OR b");

ImageUD = xor(ImageUA, ImageUC);
subplot(5, 4, 12), imshow(ImageUD), xlabel("(d3) a XOR c");

%% 第4步：下移
ImageDA = Image;
subplot(5, 4, 13), imshow(ImageDA), xlabel("(a4) 原始图像"), ylabel("第4步：下移");

ImageDB = ImageDA;
ImageDB(row, :) = [];
ImageDB = [ones(1, col); ImageDB];
subplot(5, 4, 14), imshow(ImageDB), xlabel("(b4) 上移1个像素");

ImageDC = ImageDA | ImageDB;
subplot(5, 4, 15), imshow(ImageDC), xlabel("(c4) a OR b");

ImageDD = xor(ImageDA, ImageDC);
subplot(5, 4, 16), imshow(ImageDD), xlabel("(d4) a XOR c");

%% 第5步：结果或
subplot(5, 4, 17), imshow(Image), xlabel("(a) 原二值图像"), ylabel("第5步：结果或");
subplot(5, 4, 20), imshow(ImageLD | ImageRD | ImageUD | ImageDD), xlabel("(e) 边缘检测结果");