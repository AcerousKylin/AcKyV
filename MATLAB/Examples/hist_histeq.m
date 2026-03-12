I = imread('tire.tif');
imhist(I);

J = histeq(I);
figure, imshow(I)
figure, imshow(J)