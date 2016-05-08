/*************************************************************************
	> File Name: producer.c
	> Author: 
	> Mail: 
	> Created Time: 2016年05月08日 星期日 13时22分06秒
 ************************************************************************/
#include "sem_head.h"

int main()
{
    struct exchange
    {
        char buf[BUFSIZ+80];
        int seq;
    }shm;

    int shmid;
    unsigned char *retval;
    int producer, consumer, i;

    char readbuf()
    {
        char *readbuf;
        return readbuf[100];
    }
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

    //生产者与消费者同步
    for (i = 0; ; i++)
    {
        printf("enter some text:");
        fgets(readbuf, BUFSIZ, stdin);
        semaphore_P(consumer);
        shm.seq = i;
        sprintf(shm.buf, "messge %4d form producer %d is\"%s\"\n", i, getpif(), readbuf());
        semaphore_V(producer);
        if (strncmp(readbuf, "end", 3) == 0)
            break;
    }
    exit(0);

    return 0;
}
