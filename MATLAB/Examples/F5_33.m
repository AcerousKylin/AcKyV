% F5_33.m

close all
clear
clc

im=imread('F5_33.bmp');
subplot(1,3,1),imshow(im),xlabel('(a) Ô­Ê¼Í¼Ïñ');
% imwrite(im,'.\F5_33a.bmp');

% dim = size(size(im));
% if ~(dim(2)==2)
%     I = rgb2gray(im);
% end
I = rgb2gray(im);

MaskPrewittV = fspecial('prewitt')
MaskPrewittH = MaskPrewittV'

KB1=filter2(MaskPrewittH,I);
subplot(1,3,2),imshow(uint8(KB1)),xlabel('(b) Ë®Æ½Ä£°åÂË²¨Í¼Ïñ');
% imwrite(uint8(KB1),'.\F5_33b.bmp');

KB2 = filter2(MaskPrewittV,I);
subplot(1,3,3),imshow(uint8(KB2)),xlabel('(c) ´¹Ö±Ä£°åÂË²¨Í¼Ïñ');
% imwrite(uint8(KB2),'.\F5_33c.bmp');
