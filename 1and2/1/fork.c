/*************************************************************************
	> File Name: fork.c
	> Author: 
	> Mail: 
	> Created Time: 2016年04月23日 星期六 17时35分25秒
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
int main()
{
    int p, x;
    p = fork();
    if (p > 0)
    {
        fork();
    }
    else
    {
        fork();
        fork();
    }
    sleep(5);
    return 0;
}
