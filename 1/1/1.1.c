/*************************************************************************
	> File Name: 1.1.c
	> Author: 
	> Mail: 
	> Created Time: 2016年03月31日 星期四 14时24分11秒
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
int main()
{
    int p, x;
    p = fork();
    if (p > 0)
        printf("parent output x = %d\n", ++x);
    else 
        printf("child output x = %d\n", ++x);

    return 0;
}
