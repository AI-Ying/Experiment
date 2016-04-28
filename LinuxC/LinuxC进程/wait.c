/*************************************************************************
	> File Name: wait.c
	> Author: 
	> Mail: 
	> Created Time: 2016年04月26日 星期二 21时08分36秒
 ************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
    pid_t pid = fork();
    if (pid < 0)
    {
        perror("fork");
        exit(1);
    }

    if (pid > 0)
    {
        while(1);
    }
    return 0;
}
