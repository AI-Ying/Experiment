/*************************************************************************
	> File Name: client.c
	> Author: 
	> Mail: 
	> Created Time: 2016年05月06日 星期五 20时44分37秒
 ************************************************************************/
#include <sys/types.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#define MSGKEY 75

struct msgform
{
    long mtype;
    char mtext[1000];
}msg;
int msgqid;

void client()
{
    int i;
    msgqid = msgget(MSGKEY, 0777);
    for (i = 10; i >= 1; i--)
    {
        msg.mtype = i;
        printf("(client)sent!,mtype = %ld\n", msg.mtype);
        msgsnd(msgqid, &msg, 1024, 0);
        sleep(1);
    }
    exit(0);
}

int main()
{
    client();
    return 0;
}
