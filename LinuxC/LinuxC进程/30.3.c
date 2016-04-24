/*************************************************************************
	> File Name: 30.3.c
	> Author: 
	> Mail: 
	> Created Time: 2016年04月20日 星期三 20时32分35秒
 ************************************************************************/

#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    pid_t pid;
    char *message;
    int n;
    pid = fork();
    if (pid < 0)
    {
        perror("fork failed\n");
        exit(1);
    }
    if (pid == 0)
    {
        message = "This is the child\n";
        n = 6;
    }
    else 
    {
        fork();
        message = "This is the parent\n";
        n = 3;
    }

    for (; n > 0; n--)
    {
        printf(message);
        sleep(1);
    }
    return 0;
}
