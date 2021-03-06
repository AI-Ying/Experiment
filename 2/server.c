/*************************************************************************
	> File Name: server.c
	> Author: 
	> Mail: 
	> Created Time: 2016年05月06日 星期五 20时48分27秒
 ************************************************************************/
#include <sys/types.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define MSGKEY 75

struct msgform
{
    long mtype;
    char mtext[1000];
}msg;

int msgqid;

void server()
{
    msgqid = msgget(MSGKEY, 0777|IPC_CREAT);
    do
    {
        msgrcv(msgqid, &msg, 1030, 0, 0);
        printf("(server)received! mytype = %ld\n", msg.mtype);
        sleep(1);
    }while(msg.mtype != 1);
    msgctl(msgqid, IPC_RMID, 0);
    exit(0);
}

int main()
{
    server();
    return 0;
}
