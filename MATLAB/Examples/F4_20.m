% F4_20.m

close all
clear
clc

I1=imread('A.bmp');
I2=imread('B.bmp');
IA=im2bw(I1);
IB=im2bw(I2);

% I3=and(IA,~IB);
I3=IA&~IB;
I4=and(~IA,IB);
I5=and(~IA,~IB);
I6=~and(IA,IB);
% I7=IA|~IB;
I7=or(IA,~IB);
I8=~IA|IB;
I9=~IA|~IB;
I10=~(IA|IB);
I11=xor(IA,~IB);
I12=xor(~IA,IB);
I13=xor(~IA,~IB);
I14=~xor(IA,IB);

subplot(4,4,2),imshow(IA),xlabel('(a) \itA');
subplot(4,4,3),imshow(IB),xlabel('(b) \itB');
subplot(4,4,5),imshow(I3),xlabel('(c) $A\cdot\overline{B}$','interpreter','latex');
subplot(4,4,6),imshow(I4),xlabel('(d) $\overline{A}\cdot{B}$','interpreter','latex');
subplot(4,4,7),imshow(I5),xlabel('(e) $\overline{A}\cdot\overline{B}$','interpreter','latex');
subplot(4,4,8),imshow(I6),xlabel('(f) $\overline{{A}\cdot{B}}$','interpreter','latex');
subplot(4,4,9),imshow(I7),xlabel('(g) $A+\overline{B}$','interpreter','latex');
subplot(4,4,10),imshow(I8),xlabel('(h) $\overline{A}+B$','interpreter','latex');
subplot(4,4,11),imshow(I9),xlabel('(i) $\overline{A}+\overline{B}$','interpreter','latex');
subplot(4,4,12),imshow(I10),xlabel('(j) $\overline{A+B}$','interpreter','latex');
subplot(4,4,13),imshow(I11),xlabel('(k) $A\oplus\overline{B}$','interpreter','latex');
subplot(4,4,14),imshow(I12),xlabel('(l) $\overline{A}\oplus{B}$','interpreter','latex');
subplot(4,4,15),imshow(I13),xlabel('(m) $\overline{A}\oplus\overline{B}$','interpreter','latex');
subplot(4,4,16),imshow(I14),xlabel('(n) $\overline{{A}\oplus{B}}$','interpreter','latex');

% imwrite(IA,'.\F4_20a.bmp');
% imwrite(IB,'.\F4_20b.bmp');
% imwrite(I3,'.\F4_20c.bmp');
% imwrite(I4,'.\F4_20d.bmp');
% imwrite(I5,'.\F4_20e.bmp');
% imwrite(I6,'.\F4_20f.bmp');
% imwrite(I7,'.\F4_20g.bmp');
% imwrite(I8,'.\F4_20h.bmp');
% imwrite(I9,'.\F4_20i.bmp');
% imwrite(I10,'.\F4_20j.bmp');
% imwrite(I11,'.\F4_20k.bmp');
% imwrite(I12,'.\F4_20l.bmp');
% imwrite(I13,'.\F4_20m.bmp');
% imwrite(I14,'.\F4_20n.bmp');
