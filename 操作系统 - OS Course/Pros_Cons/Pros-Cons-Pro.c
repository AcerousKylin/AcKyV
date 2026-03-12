#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define N 15
#define sleepTime 1

// 使用链表作为缓冲区，需要特殊的数量检测机制。
struct LinkBuffer
{
    int item;
    struct LinkBuffer *next;
};

struct LinkBuffer *head = NULL;    // 头指针
struct LinkBuffer *temp = NULL;    // 临界节点指针

// 以静态方式初始化互斥信号量和条件变量
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t has_producer = PTHREAD_COND_INITIALIZER;
//pthread_mutex_t consumer_block_index = PTHREAD_MUTEX_INITIALIZER;
//pthread_mutex_t

void * Producer(void * arg)
{
    while (1)   //线程正常不会解锁，除非收到终止信号
	{
        pthread_mutex_lock(&mutex);         //互斥信号量上锁

        temp = malloc(sizeof(struct LinkBuffer));
        temp->item = rand() % 100 + 1;
        temp->next = head;
        head = temp;                        //头插法
        printf("Produce a number: %d——\n", temp->item);

        pthread_mutex_unlock(&mutex);       //解锁
        pthread_cond_signal(&has_producer); //唤醒消费者线程
        usleep(rand() % 3000);              //为了使该线程放弃cpu,让结果看起来更加明显。
    }

    return NULL;
}

void * Consumer(void * arg)
{
    while (1)       //线程正常不会解锁，除非收到终止信号
	{
        pthread_mutex_lock(&mutex);     //加锁
        while (head == NULL)            //如果共享区域没有数据，则解锁并等待条件变量
	    {
	        printf("Now the buffer is empty......Consumer was blocked.\n");
            pthread_cond_wait(&has_producer, &mutex);   //我们通常在一个循环内使用该函数
        }
        temp = head;
        head = temp->next;
        printf("——Consume the number: %d\n", temp->item);
        free(temp);                     //删除节点，头删法
        temp = NULL;                    //防止野指针
        pthread_mutex_unlock(&mutex);   //解锁

        usleep(rand() % 3000);          //为了使该线程放弃cpu,让结果看起来更加明显。
    }

    return NULL;
}

int main(void)
{
    pthread_t ptid, ctid;
    srand(time(NULL));      //根据时间摇一个随机数种子

    //创建生产者和消费者线程
    pthread_create(&ptid, NULL, Producer, NULL);
    pthread_create(&ctid, NULL, Consumer, NULL);

    //主线程回收两个子线程
    pthread_join(ptid, NULL);
    pthread_join(ctid, NULL);

    return 0;
}
