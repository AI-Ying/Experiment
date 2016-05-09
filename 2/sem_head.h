/*************************************************************************
	> File Name: sem_head.h
	> Author: 
	> Mail: 
	> Created Time: 2016年05月08日 星期日 13时01分09秒
 ************************************************************************/

#ifndef _SEM_HEAD_H
#define _SEM_HEAD_H
#include <sys/types.h>
#include <sys/ipc.h>
#include <unistd.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wait.h>

union semun
{
    int val;
    struct semid_ds *buf;
    unsigned short *array;
};


//创建信号量
int open_semaphore_set(key_t keyval, int numsems)
{
    int sid;
    sid = semget(keyval, numsems, IPC_CREAT|0660); 
    return sid;
}

//初始化信号量
void init_a_semaphore(int sid, int semnum, int initval)
{
    union semun semopts;
    semopts.val = initval;
    semctl(sid, semnum, SETVAL, semopts);
}

//删除信号量
int rm_semaphore(int sid)
{
    return (semctl(sid, 0, IPC_RMID, 0));
}

//信号量的Ｐ操作
int semaphore_P(int sem_id)
{
    struct sembuf sb;
    sb.sem_num = 0;
    sb.sem_op = -1;
    sb.sem_flg = SEM_UNDO;
    if (semop(sem_id, &sb, 1) == -1)
    {
        printf("semaphore_P failed.\n");
        return 0;
    }
    return 1;
}

//信号量的V操作
int semaphore_V(int sem_id)
{
    struct sembuf sb;
    sb.sem_num = 0;
    sb.sem_op = 1;
    sb.sem_flg = SEM_UNDO;
    if (semop(sem_id, &sb, 1) == -1)
    {
        printf("semaphore_V failed.\n");
        return 0;
    }
    return 1;
}
#endif
