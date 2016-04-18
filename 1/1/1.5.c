/*************************************************************************
	> File Name: 1.5.c
	> Author: 
	> Mail: 
	> Created Time: 2016年03月31日 星期四 15时08分49秒
 ************************************************************************/

#include<stdio.h>
#include <unistd.h>

int main()
{
    int p;
    p = fork();
    if (p > 0)
    {
        printf("this is child first\n");
        printf("this is child second");
        _exit(0);
    }
    return 0;
}
