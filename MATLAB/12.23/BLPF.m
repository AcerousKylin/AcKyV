function [g] = BLPF(FftShift, D0, n)
%BLPF Butterworth LowPass Filter
%   阶数为n，截止频率为D0的巴特沃斯低通滤波器

[N1, N2] = size(FftShift);
G = size(FftShift);
n1 = fix(N1/2);
n2 = fix(N2/2);
for i = 1 : N1
    for j = 1 : N2
        d = sqrt((i-n1)^2 + (j-n2)^2);
        H = 1 / (1+(sqrt(2) - 1) * (d/D0)^(2*n));
        G(i, j) = H * FftShift(i, j);
    end
end
G = ifftshift(G);
g = ifft2(G);
g = uint8(real(g));

end

