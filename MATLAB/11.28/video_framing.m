close all
clear
clc

video_file = "1.avi";
video = VideoReader(video_file);
frame_number = floor(video.Durantion * video.FrameRate);

for i=1 : frame_number
    image_name = strcat("video3sup\", num2str(i));
    image_name = strcat(image_name, ".jpg");
    I = read(video, i);
    imwrite(I, image_name, "jpg");
    I = [];
end