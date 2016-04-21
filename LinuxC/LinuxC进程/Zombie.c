/*************************************************************************
	> File Name: Zombie.c
	> Author: 
	> Mail: 
	> Created Time: 2016年04月21日 星期四 20时14分04秒
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
    pid_t pid=fork();
    if (pid < 0)
    {
        perror("fork");
        exit(1);
    }
    if (pid>0)
    {
        //parent
        while(1);
    }
    //child
    return 0;
}
