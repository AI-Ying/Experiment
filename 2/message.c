/*************************************************************************
	> File Name: message.c
	> Author: 
	> Mail: 
	> Created Time: 2016年05月06日 星期五 16时45分37秒
 ************************************************************************/
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wait.h>
#include <unistd.h>


#define MSGKEY 67
struct msgform
{
    int mtype;
    char mtext[512];
};

int msgqid;

int main()
{
    struct msgform msg1, msg2;
    int p1, p2;
    p1 = fork();
    if (p1 == 0)
    {
        msgqid = msgget(MSGKEY, 0777);
        strcpy(msg1.mtext, "Happy!");
        msg1.mtype = 1;
        msgsnd(msgqid, &msg1, 512, 0);
        sleep(3);
        msgrcv(msgqid, &msg1, 256, 7, 0);
        printf("client receive from server %s\n", msg1.mtext);
        msgctl(msgqid, IPC_RMID, 0);
        exit(0);
    }
    else
    {
        p2 = fork();
        if (p2 == 0)
        {
            msgqid = msgget(MSGKEY, 0777|IPC_CREAT);
            msgrcv(msgqid, &msg2, 512, 1, 0);
            printf("server receive form client %s\n", msg2.mtext);
            msg2.mtype = 7;
            strcpy(msg2.mtext, "yes");
            msgsnd(msgqid, &msg2, 256, 0);
            exit(0);
        }
        if (p2 > 0)
        {
            wait(0);
            wait(0);
            exit(0);
        }
    }
    return 0;
}
