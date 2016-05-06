/*************************************************************************
	> File Name: 3.2.c
	> Author: 
	> Mail: 
	> Created Time: 2016年04月27日 星期三 19时07分50秒
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<wait.h>

int main()
{
    int fd[2], i, n;
    pid_t pid, pir;
    char b[20] = "", dat[20] = "";
    pipe(fd);
    pid = fork();
    if (pid > 0)
    {
        pir = fork();
        if (pir == 0)
        {
            while (b[0] != 'a')
            {
                n = read(fd[0], b, 20);
                printf("child2:%s\n", b);
                sleep(1);
            }
        }
        else
        {
            wait(0);
            wait(0);
            printf("parent is kill!\n");
        }
    }

    else
    {
        while (dat[0] != 'a')
        {
            scanf("%s", dat);
            write(fd[1], dat, strlen(dat));
            sleep(1);
        }
        printf("child1 is writing\n");
    }
    return 0;
}
