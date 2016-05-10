/*************************************************************************
	> File Name: z.c
	> Author: 
	> Mail: 
	> Created Time: 2016年05月02日 星期一 21时42分19秒
 ************************************************************************/
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#include<stdio.h>
#include<wait.h>
void waiting(), stop();
int a = 1;
int main()
{
    int p,q;
  //  signal(SIGINT, SIG_IGN);
    p = fork();
    if (p > 0)
    {
        a = 1;
        signal(SIGINT, stop);
        waiting();
        kill(p, 10);
        wait(0);
        printf("Parent!\n");
        exit(0);
    }
    else
    {
        a = 1;
        signal(10,stop);
        waiting();
        printf("child!\n");
        exit(0);
    }

    return 0;
    
}

void stop()
{
    a = 0;
}

void waiting()
{
    while(a != 0);
}
