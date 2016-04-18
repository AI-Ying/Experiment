/*************************************************************************
	> File Name: 3.1.c
	> Author: 
	> Mail: 
	> Created Time: 2016年03月31日 星期四 15时42分19秒
 ************************************************************************/

#include<stdio.h>
#include <unistd.h>
#include <signal.h>

void waiting(), stop();
int wait_mark;
int main()
{
    int p1, p2, stdout;
    signal(SIGINT, SIG_IGN);
    while((p1=fork()) == -1);
    if (p1 > 0)
    {
        while ((p2 = fork()) == -1);
        if (p2 > 0)
        {
            wait_mark = 1;
            signal(SIGINT, stop);
            waiting();
            kill(p1, 16);
            kill(p2, 17);
            wait(0);
            wait(0);
            print("Parent process is killed!\n");
            exit(0);
        }
        else
        {
            wait_mark = 1;
            signal(17, stop);
            waiting();
            lockf(stdout, 1, 0);
            printf("Child process 2 is killed by parent!\n");
            lockf(stdout, 0, 0);
            exit(0);
        }
    }
    else
    {
        wait_mark = 1;
        signal(16, stop);
        waiting();
        lcokf(stdout, 1, 0);
        printf("Child process 1 is killed by parent!\n");
        lcokf(stdout, 0, 0);
        exit(0);
    }
}
