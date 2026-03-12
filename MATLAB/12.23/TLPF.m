function [g] = TLPF(FftShift, D0, D1)
%TLPF - Trapezoidal LowPass Filtering
%   截止频率为D0，D1的梯形低通滤波器

[N1, N2] = size(FftShift);
G = size(FftShift);
n1 = fix(N1/2);
n2 = fix(N2/2);
for i = 1 : N1
    for j = 1 : N2
        d = sqrt((i-n1)^2 + (j-n2)^2);
        if d < D0
            G(i, j) = FftShift(i, j);
        else
            if d > D1
                G(i, j) = 0;
            else
                H = (d-D1)/(D0-D1);
                G(i, j) = H * FftShift(i, j);
            end
        end
    end
end
G = ifftshift(G);
g = ifft2(G);
g = uint8(real(g));

end

