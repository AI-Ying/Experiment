/*************************************************************************
	> File Name: 3.1.c
	> Author: 
	> Mail: 
	> Created Time: 2016年04月27日 星期三 17时35分48秒
 ************************************************************************/

#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wait.h>

int main(  )
{ 
    int pid1, pid2;
    int fd[2];
    char outpipe[100],inpipe[100];
    pipe(fd);                   
    pid1 = fork();
    if(pid1==0)
    {
        lockf(fd[1],1,0);
        sprintf(outpipe,"child 1 process is sending message!");
        write(fd[1],outpipe,50);  
        lockf(fd[1],0,0);
        exit(0);
    }
    else    
    {    
        pid2 = fork();
        if(pid2==0)
        { 
            lockf(fd[1],1,0);           
            sprintf(outpipe,"child 2 process is sending message!");
            write(fd[1],outpipe,50);
            lockf(fd[1],0,0);
            exit(0);
        }
        if (pid2 > 0)
        {                
            wait(0);              
            read(fd[0],inpipe,50);   
            printf("%s\n",inpipe);
            wait(0);
            read(fd[0],inpipe,50);
            printf("%s\n",inpipe);
            exit(0);
        }
      
    }
}
