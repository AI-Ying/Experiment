/*************************************************************************
	> File Name: 1.3.c
	> Author: 
	> Mail: 
	> Created Time: 2016年04月23日 星期六 19时34分40秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
    int p, x;
    p = vfork();
    if (p > 0)
    {
        printf("parent = %d\n", ++x);
    }
    if (p == 0)
    {
        printf("child = %d\n", ++x);
    }
    else
    {
        exit(0);
    }
    return 0;
}
