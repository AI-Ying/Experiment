/*************************************************************************
	> File Name: consum.c
	> Author: 
	> Mail: 
	> Created Time: 2016年05月08日 星期日 13时10分42秒
 ************************************************************************/
#include "sem_head.h"

int main()
{
    //定义共享存储区结构体
    struct exchange 
    {
        char buf[BUFSIZ+80];
        int seq;
    }shm;

    int shmid;
    unsigned char *retval;
    int producer, consumer, i;

    //创建信号量consumer
    consumer = open_semaphore_set(ftok("consumer", 0), 1);

    //初始化信号量consumer的值为1
    init_a_semaphore(consumer, 0, 1);
    
    //创建信号量producer
    producer = open_semaphore_set(ftok("producer", 0), 1);

    //初始化信号量producer的值为1
    init_a_semaphore(producer, 0, 1);

    //创建共享存储区用于存放生产者产生的数据
    shmid = shmget(ftok("share", 0), sizeof(struct exchange), 0666|IPC_CREAT);
    retval = shmat(shmid, (unsigned char *)0, 0);

    //进行生产与消费的同步
    for (i = 0; ; i++)
    {
        semaphore_V(consumer);
        printf("data receive:%s ,sequence:%d\n", retval, shm.seq);
        semaphore_P(producer);
        if (strncmp(retval, "end", 3) == 0)
            break;
    }

    rm_semaphore(producer);
    rm_semaphore(consumer);
    exit(0);
    return 0;
}
