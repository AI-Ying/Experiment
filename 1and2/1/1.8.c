/*************************************************************************
	> File Name: 1.8.c
	> Author: 
	> Mail: 
	> Created Time: 2016年04月26日 星期二 17时48分34秒
 ************************************************************************/

#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

void waiting();
void stop();
int wait_mark;
int main()
{
    int p1, p2, stdout;
   // signal(SIGINT,SIG_IGN);
    while ((p1 = fork()) == -1);    /*创建子进程p1*/
	if (p1 == 0)
    {
        wait_mark = 1;
        signal(10, stop);
        waiting();
        lockf(stdout, 1, 0);
        printf("Child process 1 is killed by parent!\n");
        lockf(stdout, 0, 0);
        sleep(5);
        exit(0);
    }    

    if (p1 > 0)
    {
        while ((p2 = fork()) == -1); /*创建子进程p2*/
        if (p2 == 0)
        {
	wait_mark = 1;
            signal(12, stop);   /*接收到软中断信号17, 转stop*/
            waiting();
            lockf(stdout, 1, 0);
            printf("Child process 2 is killed by parent!\n");
            lockf(stdout, 0, 0);
            sleep(5);
            exit(0);            
        }
        if (p2 > 0)
        {
    	    wait_mark = 1;
            signal(SIGINT, stop);   /*接受到^c信号,转stop*/
            waiting();
            kill(p1, 10);           /*向p1发软中断信号10*/
            kill(p2, 12);           /*向p2发软中断信号12*/
            wait(0);                /*同步*/
            wait(0);    
            printf("Parent process is killed!\n");
            //sleep(5);
            exit(0);
            
        }

    }

    
    return 0;
}

void waiting()
{
    while (wait_mark != 0);
}

void stop()
{
    wait_mark = 0;
}


