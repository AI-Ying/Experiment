/*************************************************************************
	> File Name: exec.c
	> Author: 
	> Mail: 
	> Created Time: 2016年05月02日 星期一 09时43分44秒
 ************************************************************************/
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
    pid_t pid;
    pid = fork();
    if (pid == 0)
    {
        printf("This is child!\n");
        execl("/bin/ls", "ls", "-a", (char *)0);
    }
    if (pid > 0)
    {
        wait(0);
        printf("This is parent!\n");
    }
    return 0;
}
