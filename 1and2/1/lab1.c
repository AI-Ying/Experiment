/*************************************************************************
	> File Name: lab1.c
	> Author: 
	> Mail: 
	> Created Time: 2016年04月23日 星期六 20时40分58秒
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>

int main()
{
    int p, q;
    p = fork();
    if (p < 0)
        printf("fork failed!\n");
    else if(p > 0)
    {
        q = fork();
        if (q < 0)
            printf("fork failed!\n");
        else if (q > 0)
            printf("parent a.\n");
        else 
            printf("child b.\n");
    }
    else
        printf("child c.\n");;
    return 0;
}
