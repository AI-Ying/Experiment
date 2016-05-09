/*************************************************************************
	> File Name: producer.c
	> Author: 
	> Mail: 
	> Created Time: 2016年05月09日 星期一 21时47分59秒
 ************************************************************************/
#include "myshm.h"
#include <stdlib.h>
#include <unistd.h>

int main()
{
     char *shm, *s;
      int shmid;
       int producer, consumer,i;
        char readbuf[SHMSZ];
         consumer=open_semaphore_set(ftok("consumer",0),1);
          init_a_semaphore(consumer,0,1);
           producer=open_semaphore_set(ftok("producer",0),1);
            init_a_semaphore(producer,0,1);
             if((shmid=shmget(ftok("shared",0),SHMSZ, 0666|IPC_CREAT))==-1)
                  { 
                    printf("shmget failed.\n");
                    exit(1);
                   }
             shm=shmat(shmid,(unsigned char *)0,0);
               for(i=0; ; i++)
               {
                     printf("Enter text:");
                       fgets(readbuf,SHMSZ,stdin);
                         semaphore_P(consumer);
    sprintf(shm,"Message %d from producer %d is \"%s\" \n",i, getpid(),readbuf);
                             semaphore_V(producer);
                              if(strcmp(readbuf,"end")==0)
                                     break;
                               
               }
                return 0;

}

