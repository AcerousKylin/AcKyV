close all
clear
clc

% 读取文件的名称
read_filename = "实验1-测试集";
postfix = '.png';

% 读取原始图像
img = imread(read_filename + postfix);

% 将图像转换为灰度图像
gray_img = rgb2gray(img);

% 对灰度图像进行灰度插值
gray_img = interp2(double(gray_img), 'cubic');

% 对灰度图像进行灰度反转处理
inverted_img = imcomplement(gray_img);
 
% 显示结果图像
subplot(1,3,1), imshow(img), title('Original Image');
subplot(1,3,2), imshow(gray_img), title('Grayscale Image');
subplot(1,3,3), imshow(inverted_img), title('Inverted Grayscale Image');

%imwrite(inverted_img, 'processed_' + read_filename + postfix);