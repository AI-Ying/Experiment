/*************************************************************************
	> File Name: 30.7.c
	> Author: 
	> Mail: 
	> Created Time: 2016年04月27日 星期三 17时18分56秒
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#define MAXLINE 80
#include<stdlib.h>
#include<sys/wait.h>
int main(void)
{
    int n;
    int fd[2];
    pid_t pid;
    char line[MAXLINE];

    if (pipe(fd) < 0)
    {
        perror("pipe");
        exit(1);
    }
    if ((pid = fork()) < 0)
    {
        perror("fork");
        exit(1);
    }

    if (pid > 0)
    {
        close(fd[0]);
        write(fd[1], "hello world\n", 12);
        wait(NULL);
    }
    else
    {
        close(fd[1]);
        write(fd[0], line, MAXLINE);
        write(STDOUT_FILENO, line, n);
    }
    return 0;
}
