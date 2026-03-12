close all
clear
clc

video = 'Megahead.avi';
aviObj = VideoReader(video);

frameRate = aviObj.FrameRate;
numFrames = aviObj.NumFrames;

open(aviObj);
outputPrefix = 'avi_frame_';

for i = 1 : numFrames
    frame = readFrame(aviObj);
    imshow(frame);

    title(['Current Frame: ', num2str(i)]);
    pause(1 / frameRate);

    outputName = [outputPrefix, num2str(i), '.jpg'];
    imwrite(frame, outputName);
end