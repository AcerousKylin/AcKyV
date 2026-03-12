close all
clear
clc

%% 
read_filename = "202409W2-1";
postname = '.png';

img = imread(read_filename + postname);
subplot(2, 3, 1), imshow(img), xlabel('(a) 原图像');

% 将图像转换为灰度图像
gray_img = rgb2gray(img);
% figure, imshow(gray_img);

%% 
% 对灰度图像进行灰度反比变换
inverted_img = imcomplement(gray_img);
subplot(2, 3, 2), imshow(inverted_img), xlabel('(b-1) 灰度反转图像');
subplot(2, 3, 3), imhist(inverted_img), ylim([0, 400]), xlabel({'','','(b-2) 灰度反转图像的灰度统计直方图'});
% figure, imshow(inverted_img);
%imwrite(inverted_img, read_filename + '_inverted' + '.png');

%% 
% 对反转后的灰度图像进行灰度截取式正比变换
[n, m] = size(inverted_img);
inverted_img = imadjust(inverted_img, [25/255 230/255], [0/255 255/255]);
subplot(2, 3, 4), imshow(inverted_img), xlabel('(c-1) 变换图像');
subplot(2, 3, 5), imhist(inverted_img), ylim([0, 400]), xlabel({'','','(c-2) 变换图像的灰度统计直方图'});

% 检测图片多余部分的行与列
final_row = ones(n, 1);
vacuum_row = ones(1, m) * 255;
cols = 1:m;
for i=1 : n
    if inverted_img(i) == vacuum_row
        final_row(i) = 0;
    end
end

final_col = ones(1, m);
vacuum_col = ones(n, 1) * 255;
rows = 1:n;
for j=1 : m
    if inverted_img(rows, j) == vacuum_col
        final_col(j) = 0;
    end
end

% 确定图像最终大小
top_left_x = 0;     top_left_y = 0;
bot_right_x = 0;    bot_right_y = 0;
for i=1 : m
    if top_left_y == 0 && final_col(i) == 1
        top_left_y = i-1;
    end
    if bot_right_y == 0 && final_col(m+1-i) == 1
        bot_right_y = m+1-i+1;
    end
end

for j=1 : n
    if top_left_x == 0 && final_row(j) == 1
        top_left_x = j-1;
    end
    if bot_right_x == 0 && final_row(n+1-j) == 1
        bot_right_x = n+1-j+1;
    end
end

% 对图像进行裁剪
rect = [top_left_x, top_left_y, bot_right_y-top_left_y, bot_right_x-top_left_x];
resize_img = imcrop(inverted_img, rect);
subplot(2, 3, 6), imshow(resize_img), xlabel('(d) 裁剪后的图像');
% figure, imshow(resize_img);

% imwrite(inverted_img, read_filename + '_inverted' + '.png');