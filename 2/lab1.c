/*************************************************************************
	> File Name: lab1.c
	> Author: 
	> Mail: 
	> Created Time: 2016年04月27日 星期三 20时39分48秒
 ************************************************************************/


#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{ 
    int fd[2],pid,n;
    char buffer[256],dat[20]="hello world\n";
    pipe(fd);
    pid=fork();
    if(pid==0)
    { 
            close(fd[1]);
            n=read(fd[0],buffer,256);
            printf("child %d read %d bytes:%s",getpid(),n,buffer);
        }
    else
    {
                close(fd[0]);
                        write(fd[1],dat,strlen(dat));
                                printf("parent write%d byge: %s\n",strlen(dat),dat);
                                    
    }
    return 0;
}
