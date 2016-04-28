/*************************************************************************
	> File Name: 3.1.c
	> Author: 
	> Mail: 
	> Created Time: 2016年04月27日 星期三 17时35分48秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
    int fd[2];
    pid_t pid;
    int n;
    char buffer[256];
    char dat[20] = "hello world\n";
    pipe(fd);
    pid = fork();
    if (pid == 0)
    {
        close(fd[1]);
        n = read(fd[0], buffer, 256);
        printf("child %d read %d bytes:%s", getpid(), n, buffer);
    }

    else
    {
        close(fd[0]);
        write(fd[1], dat, strlen(dat));
        printf("parent write%d byge:%s\n", strlen(dat), dat);
    }
    exit(0);
}
