#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct Process_Control_Block
{
    char NAME[5];  //进程名
    int PRIO_ROUND; // 优先级/时间片大小
    int CPU_TIME;   // 处理机占用时间
    struct Process_Control_Block *COUNT;      // 计数器
    int NEED_TIME;  // 需要的处理机时间
    char STATE;     // 进程状态，W代表就绪，R代表运行，F代表完成
    struct Process_Control_Block *NEXT;  // PCB链指针
}PCB;

void PRISCH();
void ROUNDSCH();

PCB* READY;
PCB* TAIL;
PCB* RUN;
PCB* FINISH;

int NUMBER = 0;

void Debug_Print(PCB *temp)
{
    printf("\n[Warning] Debugger printer#\n");
    printf("Target PCB's Info:\n");
    printf("-------------------------\n");
    printf("Name: %s\nP/R: %d\nCPU_TIME: %d\nCOUNT: %d\nNEED_TIME: %d\nSTATE: %c\n",
            temp->NAME, temp->PRIO_ROUND, temp->CPU_TIME, temp->COUNT, temp->NEED_TIME, temp->STATE);
    printf("-------------------------\n\n");
}

void CREATE(int ALGO)
{   //  创建新的进程，并链入到就绪队列中去
    printf("[Info] Start to create PCBs.\n");
    if (!ALGO)  // 创建优先数算法调度用PCB
    {
        for (int i=0; i<5; i++)
        {
            PCB* new_process = (PCB *)malloc(sizeof(PCB));
            for (int i=0; i<5; i++) // 进程名随机生成
                new_process->NAME[i] = (rand()%2 ? rand()%26+'a' : rand()%26+'A');

            printf("Set PRIO of this PCB: ");
            scanf("%d", &new_process->PRIO_ROUND);

            new_process->CPU_TIME = 0;
            new_process->COUNT = new_process;

            printf("Set NEED_TIME of this PCB: ");
            scanf("%d", &new_process->NEED_TIME);

            new_process->STATE = 'W';
            new_process->NEXT = NULL;

            if (i == 0)  // 初始化就绪队列
            {
                READY = new_process;
                TAIL = READY;
            }
            else    // 队尾进队
            {
                TAIL->NEXT = new_process;
                TAIL = new_process;
            }
            printf("[Info] A new P-process is created\n");
            NUMBER++;
        }
    }
    else  // 创建轮转法调度用PCB
    {
        for (int i=0; i<5; i++)
        {
            PCB* new_process = (PCB *)malloc(sizeof(PCB));
            for (int i=0; i<5; i++) // 进程名随机生成
                new_process->NAME[i] = (rand()%2 ? rand()%26+'a' : rand()%26+'A');

            new_process->PRIO_ROUND = 2;
            new_process->CPU_TIME = 0;
            new_process->COUNT = new_process;

            printf("Set the NEED_TIME of this PCB: ");
            scanf("%d", &new_process->NEED_TIME);

            new_process->STATE = 'W';
            new_process->NEXT = NULL;

            if (i == 0)  // 初始化就绪队列
            {
                READY = new_process;
                TAIL = READY;
            }
            else    // 队尾进队
            {
                TAIL->NEXT = new_process;
                TAIL = new_process;
            }
            printf("[Info] A new R-process is created\n");
            NUMBER++;
        }
    }
    return;
}

void FIRSTIN(int ALGO)
{   // 将就绪队列中的第一个进程投入运行

    if (READY == NULL)  // 防止进程在此处出现READY队列空的情况
    {
        printf("[Warning] The ready queue is now empty.\n");
        return;
    }

    // 将READY队列的队首取出
    RUN = READY;            // 先取到READY所在的队首
    READY = READY->NEXT;    // 后移READY指针到下一个队列队首
    RUN->NEXT = NULL;       // 此时彻底断开旧队首结点与队列的连接

    if (!ALGO)  // 处理优先数算法调度PCB
    {
        printf("[Info] The P-Process is operating.\n");
        PRISCH();
    }
    else    // 处理轮转法调度下的PCB
    {
        printf("[Info] The R-Process is operating.\n");
        ROUNDSCH();
    }
    return;
}

void INSERT1(PCB *ran_process)
{   // 将未完成且优先级小于其他进程的PCB按进程优先级的顺序重新插入到就绪队列中

    // 将运行结束的进程插入就绪队列
    if (READY == NULL)
        READY = TAIL;
    else
    {
        TAIL->NEXT = ran_process;
        TAIL = ran_process;
    }

    PCB *s[5];
    int n=0;
    PCB *temp = READY;
    while (temp != NULL)
    {
        s[n++] = temp;
        temp = temp->NEXT;
    }

    for (int i=0; i<n; i++)
    {
        for (int j=i+1; j<n; j++)
        {
            if (s[j]->PRIO_ROUND > s[i]->PRIO_ROUND)
            {
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }

    READY = s[0];
    temp = READY;
    TAIL = s[n-1];
    TAIL->NEXT = NULL;
    for (int i=1; i<n; i++)
    {
        temp->NEXT = s[i];
        temp = temp->NEXT;
    }

    printf("[Info] Re-insert has finished\n");
    return ;
}

void INSERT2(PCB*ran_process)
{   // 轮转法的使用过程，将执行了一个单位时间片且尚未完成的PCB插入到就绪队列的队尾
    TAIL->NEXT = ran_process;
    TAIL = ran_process;
    return;
}

void PRINT(void)    // 打印所有进程的状态，就绪用W代表
{
    PCB* temp = READY;

    printf("[Info] Print all queue down below:\n");
    printf("\nThe PCB(s) in ready queue:\n");
    while(temp != NULL)
    {
        printf("-------------------------\n");
        printf("Name: %s\nP/R: %d\nCPU_TIME: %d\nCOUNT: %d\nNEED_TIME: %d\nSTATE: %c\n",
               temp->NAME, temp->PRIO_ROUND, temp->CPU_TIME, temp->COUNT, temp->NEED_TIME, temp->STATE);
        printf("-------------------------\n");
        temp = temp->NEXT;
    }

    temp = FINISH;
    printf("\nThe PCB(s) in finish queue:\n");
    while(temp != NULL)
    {
        printf("-------------------------\n");
        printf("Name: %s\nP/R: %d\nCPU_TIME: %d\nCOUNT: %d\nNEED_TIME: %d\nSTATE: %c\n",
               temp->NAME, temp->PRIO_ROUND, temp->CPU_TIME, temp->COUNT, temp->NEED_TIME, temp->STATE);
        printf("-------------------------\n");
        temp = temp->NEXT;
    }
    printf("\nPrint process finished.\n");
}

void PRISCH(void)
{   // 按优先数算法调度进程

    RUN->STATE = 'R';
    Debug_Print(RUN);
    // 运行优先数算法调度下的PCB
    RUN->PRIO_ROUND -= 3;
    RUN->CPU_TIME++;
    RUN->NEED_TIME--;
    printf("[Info] P-Process PCB has ran.\n");

    // 运行完成，将进程调离，并将运行区置空，
    PCB *temp = RUN;
    RUN = NULL;

    // 进程调离后的处理，进入完成区，否则返回就绪队列
    if (temp->NEED_TIME <= 0)   // 进程是否运行结束
    {
        // 运行完成则直接插入完成区
        printf("[Info] The P-Process is finished.\n");
        temp->NEXT = FINISH;
        FINISH = temp;
        FINISH->NEED_TIME = -1;
        FINISH->STATE = 'F';
        NUMBER--;
    }
    else    // 进程没运行完
    {
        printf("[Info] The P-Process isn't finished, so re-inserted.\n");
        INSERT1(temp); // 重新插入等待队列
    }
    return;
}

void ROUNDSCH(void)
{   // 按时间片轮转法调度进程

    RUN->STATE = 'R';   // 更新进程状态为Ready
    Debug_Print(RUN);   // Debug显示运行中的进程
    printf("[Info] R-Process PCB will run.\n");

    // 运行轮转法调度下的PCB操作
    RUN->CPU_TIME += RUN->PRIO_ROUND;
    RUN->NEED_TIME -= RUN->PRIO_ROUND;
    printf("[Info] R-Process PCB has ran.\n");

    // 运行一次后PCB的去向
    PCB* temp = RUN;
    RUN = NULL;
    if (temp->NEED_TIME <= 0)   // 需要CPU时间小于等于0
    {
        printf("[Info] The R-Process is finished.\n");
        temp->NEXT = FINISH;    // 前插法插入FINISH队列
        FINISH = temp;
        FINISH->NEED_TIME = -1; // 重设定所需时间为负值
        FINISH->STATE = 'F';    // 将进程状态更新为Finished
        NUMBER--;
    }
    else
    {
        printf("[Info] The R-Process isn't finished, so re-inserted.\n");
        INSERT2(temp);
    }
    return;
}

int main(void)
{
    srand(time(NULL));

    // 就绪队列链表的头为队尾，尾指针指向队头
    READY = NULL;
    TAIL = NULL;
    RUN = NULL;
    FINISH = NULL;

    printf("Enter the algorithm you want to run:[PRIORITY/ROUNDROBIN] ");
    char ALGO[10];
    int ALGO_CODE;
    scanf("%s", ALGO);

    if (!strcmp(ALGO, "PRIORITY"))  // strcmp相同输出0，不同输出1
        ALGO_CODE = 0;
    else if (!strcmp(ALGO, "ROUNDROBIN"))
        ALGO_CODE = 1;
    else
    {
        printf("[Error] Your input is not either PRIORITY or ROUNDROBIN.");
        exit(1);
    }

    // 初始化并输出
    CREATE(ALGO_CODE);
    PRINT();

    while(READY != NULL)
    {
        if (NUMBER <= 0)
            printf("[Warning] Process counter has ran out!\n");
        printf("[Info] An operation is on.\n");
        FIRSTIN(ALGO_CODE);
        PRINT();
    }

    return 0;
}
