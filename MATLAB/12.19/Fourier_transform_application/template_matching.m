close all
clear
clc

% 读入匹配图像
fxy = imread('F6_17a.bmp');
subplot(3, 3, 1), imshow(fxy), xlabel('(a) 步骤1：二值原始图像');
axis image off;
Bwfxy = imbinarize(fxy);    % 把匹配图像转为二值图像

Fuv = fft2(Bwfxy);
subplot(3, 3, 2), mesh(abs(fftshift(Fuv))), xlabel('(b) 步骤2：二值原始图像对称傅里叶幅度谱');
grid on;
axis([0 500 0 500 0 40000]);

txy = imread('F6_17c.bmp');
subplot(3, 3, 3), imshow(txy), xlabel('(c) 步骤3：二值模板图像');
axis image off;
Bwtxy = imbinarize(txy);

RotBwtxy = rot90(Bwtxy, 2);
subplot(3, 3, 4), imshow(RotBwtxy), xlabel('(d) 步骤4：二值模板图像旋转180度');
axis image off;

Tuv = fft2(RotBwtxy);   
subplot(3, 3, 6), mesh(abs(fftshift(Tuv))), xlabel('(d) 步骤5：二值模板图像对称傅里叶幅度谱');
grid on;
axis([0 500 0 500 0 4000]);

f = ifft2(Fuv .* Tuv);
fxy_result = abs(fftshift(f));
subplot(3, 3, 7), mesh(fxy_result, [- 10 50]), xlabel('(f) 步骤6：相关性矩阵的模矩阵三维图');
grid on;
axis([0 500 0 500 0 4000]);

thresh = max(fxy_result(:));
subplot(3, 3, 9), imshow(fxy_result >= thresh-250), xlabel('(g) 步骤7：模板匹配结果');