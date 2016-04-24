/*************************************************************************
	> File Name: 1.5.c
	> Author: 
	> Mail: 
	> Created Time: 2016年04月24日 星期日 17时20分24秒
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
    int p;
    p = fork();
    if (p > 0)
        printf("this is parent \n");
    else
    {
        printf("this is child first \n");
        printf("this is child second \n");
       _exit(0);
    }
    return 0;
}
