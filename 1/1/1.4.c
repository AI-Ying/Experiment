/*************************************************************************
	> File Name: 4.1.c
	> Author: 
	> Mail: 
	> Created Time: 2016年03月31日 星期四 15时04分36秒
 ************************************************************************/

#include<stdio.h>
#include <unistd.h>

int main()
{
    int p;
    p = fork();
    if (p>0)
        printf("parent\n");
    else
    {
        printf("\nbefore execute exec\n");
        execl("/bin/ps", "ps", "-l", (char *)0);
        printf("after execute exec\n");
    }

    return 0;
}
