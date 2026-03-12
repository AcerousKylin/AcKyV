close all
clear
clc

I = imread("rice.png");
subplot(3, 3, 1), imshow(I), ylabel("原图像");
subplot(3, 3, 2), imhist(I);

% 把灰度值范围[80, 160]映射到[20, 220], 灰度值小于80的映射为20， 灰度值大于160的映射为220
% 方法1-系统函数
J = imadjust(I, [80/255 160/255], [20/255 220/255]);
subplot(3, 3, 4), imshow(J), ylabel("变换图像（方法1）");
subplot(3, 3, 5), imhist(J);

% 方法2-编程实现
f0 = 0;     g0 = 20;
f1 = 80;    g1 = 20;
f2 = 160;   g2 = 220;
f3 = 220;   g3 = 220;
subplot(3, 3, 9), plot([f0, f1, f2, f3], [g0, g1, g2, g3]), xlabel('f'), ylabel('g'), axis([0 255 0 255]);

%绘制变换曲线
r1 = (g1-g0) / (f1-f0); b1 = g0 - r1*f0;    % 曲线1的斜率与结局截距
r2 = (g2-g1) / (f2-f1); b2 = g1 - r2*f1;    % 曲线2的斜率与结局截距
r3 = (g3-g2) / (f3-f2); b3 = g2 - r3*f2;    % 曲线3的斜率与结局截距
[m ,n] = size(I);
K = double(I);
g = ones(size(I));
for i=1:m
    for j=1:n
        f = K(i, j);
        g(i, j) = 0;
        if (f >= f0) && (f <= f1)
            g(i, j) = r1*f + b1;
        else
            if (f >= f1) && (f <= f2)
                g(i, j) = r2*f + b2;
            else
                if (f >= f2) && (f <= f3)
                    g(i, j) = r3*f + b3;
                end
            end
        end
    end
end
subplot(3, 3, 7), imshow(uint8(g)), ylabel("变换图像（方法2）");
subplot(3, 3, 8), imhist(uint8(g));