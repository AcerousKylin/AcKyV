% F6_17.m

close all
clear
clc

% ---- 步骤1 ----
% 读入匹配图像
fxy=imread('F6_17a.bmp');
subplot(3,3,1),imshow(fxy),xlabel('(a) 步骤1：二值原始图像');
axis image off
% 把匹配图像转为二值图像
Bwfxy=im2bw(fxy);

% ---- 步骤2 ----
Fuv=fft2(Bwfxy);
subplot(3,3,2),mesh(abs(fftshift(Fuv))),xlabel('(b) 步骤2：二值原始图像对称傅里叶幅度谱');
grid on;
axis([0 500 0 500 0 40000]);

% ---- 步骤3 ----
% 读入模板图像
txy=imread('F6_17c.bmp');
subplot(3,3,3),imshow(txy),xlabel('(c) 步骤3：二值模板图像');
axis image off;
% 把模板图像转为二值图像
Bwtxy=im2bw(txy);

% ---- 步骤4 ----
RotBwtxy=rot90(Bwtxy,2);
subplot(3,3,4),imshow(RotBwtxy),xlabel('(d) 步骤4：二值模板图像旋转180度');
axis image off;

% ---- 步骤5 ----
Tuv=fft2(RotBwtxy);
subplot(3,3,6),mesh(abs(fftshift(Tuv))),xlabel('(e) 步骤5：二值模板图像对称傅里叶幅度谱');
grid on;
axis([0 500 0 500 0 4000]);

% ---- 步骤6 ----
% 模板与匹配图像相关计算
f=ifft2(Fuv.*Tuv);
fxy_result=abs(fftshift(f));
subplot(3,3,7),mesh(fxy_result,[-10 50]),xlabel('(f) 步骤6：相关性矩阵的模矩阵三维图');
grid on;
axis([0 500 0 500 0 4000]);

% ---- 步骤7 ----
thresh = max(fxy_result(:))    % 设置阀值为图像数据中的最大值
subplot(3,3,9),imshow(fxy_result>=thresh-250),xlabel('(g) 步骤7：模板匹配结果');
