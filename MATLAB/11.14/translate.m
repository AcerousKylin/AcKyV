close all
clear
clc

I = imread("2.png");
figure, imshow(I), title("Original Image");

% x正方向移位15个像素，y负方向移位25个像素。
% 默认情况下，imtanslate在原始256px图像的边界内显示转换后的图像。
% 这将导致某些移位的图像被剪切。
J = imtranslate(I, [150, -250]);
figure, imshow(J), title("Translated Image");
