/*************************************************************************
	> File Name: 2client.c
	> Author: 
	> Mail: 
	> Created Time: 2016年05月07日 星期六 21时25分14秒
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#define SHMKEY 75
int shmid, i;
int *addr;

void client()
{
    int i;
    shmid = shmget(SHMKEY, 1024, 0777);
    addr = shmat(shmid, 0, 0);
    for (i = 9; i >= 0; i--)
    {
        while(*addr != -1);
        printf("(client)sent\n");
        *addr = i;
        sleep(1);
    }
    exit(0);
}

void server()
{
    shmid = shmget(SHMKEY, 1024, 0777|IPC_CREAT);
    addr = shmat(shmid, 0, 0);
    do
    {
        *addr = -1;
       while (*addr == -1);
        printf("(server)receive *addr = %d\n", *addr);
        sleep(1);
    }while(*addr);
    shmctl(shmid, IPC_RMID, 0);
    exit(0);
}

int main()
{
    i = fork();
    if (!i)
        server();
    system("ipcs -m");
    i = fork();
    if (!i)
        client();
    wait(0);
    wait(0);
    return 0;
}
