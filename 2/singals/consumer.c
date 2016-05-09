/*************************************************************************
	> File Name: consumer.c
	> Author: 
	> Mail: 
	> Created Time: 2016年05月09日 星期一 21时42分44秒
 ************************************************************************/
#include "myshm.h"
#include <unistd.h>
#include <stdlib.h>
int main()
{
     char *shm;
     int shmid;
     int producer, consumer, i;
     consumer=open_semaphore_set(ftok("consumer",0),1);
     init_a_semaphore(consumer,0,1);
     producer=open_semaphore_set(ftok("producer",0),1);
     init_a_semaphore(producer,0,1);
   //  shm=(struct exchange *)shminit(ftok("shared",0));
     if((shmid=shmget(ftok("shared",0),SHMSZ, 0666|IPC_CREAT))==-1)
     { 
          printf("shmget failed.\n");
          exit(1);
     } 
    shm=shmat(shmid,(unsigned char *)0,0);
     for(i=0; ; i++)
     {
        semaphore_V(consumer);
        semaphore_P(producer);
       printf("Data receiverd: %s\n",shm);
           sleep(1);
          if(strcmp(shm,"end")==0)
               break;
       }
           semctl(producer,0,IPC_RMID,0);
          semctl(consumer,0,IPC_RMID,0);
                }
