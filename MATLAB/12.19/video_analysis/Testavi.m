close all;
clc
clear

video = 'Megamind.avi';

aviTest = VideoReader(video);
start = 1;

nFrames = aviTest.NumFrames;

for k=start : nFrames
    I = read(aviTest, k);
    imwrite(I, strcat('./test',num2str(k),'.jpg'));
end
