/*************************************************************************
	> File Name: lab1.c
	> Author: 
	> Mail: 
	> Created Time: 2016年04月27日 星期三 20时39分48秒
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
    pid_t pid, pir;
    int fd[2];
    pipe(fd);
     
    pif = fork();
    if (pid == 0)
    {
        close(fd[0]);
        write();
    }

}
