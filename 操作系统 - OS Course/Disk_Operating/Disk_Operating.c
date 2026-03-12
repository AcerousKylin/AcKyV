#include<stdio.h>
#include<math.h>
#define L 9

int track_number[L] = {55, 58, 39, 18, 90, 160, 150, 38, 184};
int shift_number[L] = {0};
int shift_track[L] = {0};
int current_track = 100;

void Reset(void)
{
    for (int i=0; i<L; i++)
        shift_number[i] = 0;
    current_track = 100;
}

void Debug_shift(void)
{
    printf("[Debug] Print the shift number:\n");
    for (int i=0; i<L; i++)
        printf("%d ", shift_number[i]);
    printf("\n");
}

double Average(void)
{
    int sum = 0;
    for (int i=0; i<L; i++)
        sum += shift_number[i];
    return (double)sum / (double)L;
}

void Print(void)
{
    printf("-------------\n");
    for (int i=0; i<L; i++)
        printf("| %3d | %3d |\n", shift_track[i], shift_number[i]);
    printf("|-----------|\n");
    printf("|平均       |\n");
    printf("|寻道：%3.1f |\n", Average());
    printf("|时间       |\n");
    printf("-------------\n");
}

void FCFS(void) // First Come First Serve - 先来先服务
{
    printf("[Info] It's FCFS Algorithm is working down below.\n");
    for (int i=0; i<L; i++)
    {
        shift_number[i] = abs(current_track - track_number[i]);
        current_track = track_number[i];
        shift_track[i] = current_track;
    }
    printf("[Info] The FCFS Algorithm is finished.\n");
}

void SSTF(void) // Shortest Seek Time First - 最短寻道时间优先
{
    printf("[Info] It's SSTF Algorithm is working down below.\n");
    int seeked[L] = {0};
    for (int i=0; i<L; i++)
    {
        int nearest_index = i, nearest_distance = 200;  // 每次寻找最近磁道前，重置标识量
        for (int j=0; j<L; j++)
        {
            if (seeked[j])  // 如果已经寻道，则跳过
                continue;
            if (abs(track_number[j] - current_track) < nearest_distance)
            {
                nearest_index = j;
                nearest_distance = abs(track_number[j] - current_track);
            }
        }
        seeked[nearest_index] = 1;
        shift_number[i] = nearest_distance;
        current_track = track_number[nearest_index];    // 将刚寻道过的磁道作为基准磁道
    }
}

void SCAN(void)
{
    printf("[Info] It's SCAN Algorithm is working below.\n");
    int seeked[L] = {0};
    int turn = 0;
    for (int i=0; i<L; i++)
    {
        int nearest_index = i, nearest_distance = 200;
        if (!turn)
        {
            int not_floor = 0;
            for (int j=0; j<L; j++)
            {
                int distance = abs(track_number[j] - current_track);
                if (seeked[j])
                    continue;
                if (track_number[j] > current_track && distance < nearest_distance)
                {
                    nearest_distance = distance;
                    nearest_index = j;
                    not_floor = 1;
                }
            }
            if (!not_floor)
                turn = 1;
            else
            {
                shift_number[i] = nearest_distance;
                shift_track[i] = track_number[nearest_index];
                current_track = track_number[nearest_index];
                seeked[nearest_index] = 1;
            }
        }

        if (turn)
        {
            for (int j=0; j<L; j++)
            {
                int distance = abs(track_number[j] - current_track);
                if (seeked[j])
                    continue;
                if (track_number[j] < current_track && distance < nearest_distance)
                {
                    nearest_distance = distance;
                    nearest_index = j;
                }
            }
            shift_number[i] = nearest_distance;
            shift_track[i] = track_number[nearest_index];
            current_track = track_number[nearest_index];
            seeked[nearest_index] = 1;
        }
    }
}

int main(void)
{
    Reset();
    FCFS();
    Print();

    Reset();
    SSTF();
    Print();

    Reset();
    SCAN();
    Print();
    return 1;
}

