/*************************************************************************
	> File Name: 3.3.c
	> Author: 
	> Mail: 
	> Created Time: 2016年05月06日 星期五 16时13分29秒
 ************************************************************************/
#include <sys/ipc.h>
#include <stdio.h>
#include <sys/msg.h>

struct mymsg
{
    long mtype;
    char mtext[30];
};

int main()
{
    key_t key = ftok(".", 4);
    printf("当前文件夹的关键值是：%d\n", key);
    int mqid = msgget(key, 0664|IPC_CREAT|IPC_EXCL);
    printf("消息队列的标识符是：%d\n", mqid);
    struct mymsg msg_snd = {1,"qwerty"};
    int a = msgsnd(mqid, &msg_snd, 6, 0);
    if (a = 0)
    {
        struct mymsg msg_rcv;
        msg_rcv.mtype = 1;
        int b = msgrcv(mqid, &msg_rcv, 7, msg_rcv.mtype, 0);
        if (b != 1)
        {
            printf("通过msgrcv从消息队列里读取的消息:%s\n", msg_rcv.mtext);
        }
    }
    return 0;
}
