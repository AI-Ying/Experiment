/*************************************************************************
	> File Name: 1.2.c
	> Author: 
	> Mail: 
	> Created Time: 2016年03月31日 星期四 14时51分51秒
 ************************************************************************/

#include<stdio.h>
#include <unistd.h>
int main()
{
    int p, x;
    if (p > 0)
    {
        fork();
        printf("parent = %d\n", ++x);
        fork();
    }
    else
    {
        printf("child = %d\n", ++x);
        fork();
        fork();
    }
    sleep(5);
    return 0;
}
