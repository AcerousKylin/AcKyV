function [g] = ILPF(FftShift, D0)
%ILPF - Ideal LowPass Filter
%   理想低通滤波器
    AbsFftShift = abs(FftShift);
    [N1, N2] = size(FftShift);
    G = [N1, N2];
    n1 = fix(N1/2);
    n2 = fix(N2/2);
    energy = 0;
    for i = 1 : N1
        for j = 1 : N2
            d = sqrt((i-n1)^2 + (j-n2)^2);
            if (d <= D0)
                G(i, j) = FftShift(i, j);
                energy = energy + AbsFftShift;
            else
                G(i, j) = 0;
            end
        end
    end
    disp(energy/sum(AbsFftShift(:)));
    G = ifftshift(G);
    g = ifft2(G);
    g = uint8(real(g));
end

