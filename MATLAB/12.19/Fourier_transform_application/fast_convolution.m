close all
clear
clc

disp('步骤1：生成3×3的矩阵A和B');
A = [4 5 6
     7 8 9];
B = [3 2
     1 0];

disp('步骤2：验证利用卷积函数直接进行卷积');
AconvB = conv2(A, B);

disp('步骤3；对A和B补零，使其大小均为(2+2-1)×(3+2-1)，即3×4');
A(3, 4) = 0;
A0 = A;
B(3, 4) = 0;
B0 = B;

disp('步骤4；对A和B分别进行傅里叶变换，并将变换结果相乘');
fftA0 = fft2(A0);
fftB0 = fft2(B0);
A0dcB0 = fftA0 .* fftB0;

disp("步骤5：对结果进行傅里叶反变换");
ifftA0dcB0 = ifft2(A0dcB0);