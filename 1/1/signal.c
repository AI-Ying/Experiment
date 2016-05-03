/*************************************************************************
	> File Name: signal.c
	> Author: 
	> Mail: 
	> Created Time: 2016年04月27日 星期三 12时43分57秒
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<sys/wait.h>
#include<stdlib.h>

void waiting();
void stop();
int wait_mark;

int main()
{
  //  signal(SIGINT, SIG_IGN);
    pid_t pid1, pid2;
    pid1 = fork();
    if (pid1 > 0)
    {
        pid2 = fork();
        if (pid2 > 0)
        {
            wait_mark = 1;
            signal(SIGINT, stop);
            waiting();
            kill(pid1, 10);
            kill(pid2, 12);
            wait(0);
            wait(0);
            printf("Parent process is killed!\n");
            exit(0);
        }
        
        if (pid2 == 0)
        {
            wait_mark = 1;
            signal(12, stop);
            waiting();
            lockf(1, 1, 0);
            printf("child process2 is killed by parent!\n");
            lockf(1, 0, 0);
            exit(0);
        }
    }
    if (pid1 == 0)
    {
        wait_mark = 1;
        signal(10, stop);
        waiting();
        lockf(1, 1, 1);
        printf("child process1 is killed by parent!\n");
        lockf(1, 0, 0);
        exit(0);
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
