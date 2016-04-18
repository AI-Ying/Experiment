/*************************************************************************
	> File Name: 1.3.c
	> Author: 
	> Mail: 
	> Created Time: 2016年03月31日 星期四 15时01分47秒
 ************************************************************************/

#include<stdio.h>
#include <unistd.h>
int main()
{
    int p, x;
    p = vfork();
    if (p>0)
        printf("parent output x = %d\n", ++x);
    else
        printf("parent output x = %d\n", ++x);
    return 0;
}
