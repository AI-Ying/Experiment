/*************************************************************************
	> File Name: signal.c
	> Author: 
	> Mail: 
	> Created Time: 2016年04月27日 星期三 12时43分57秒
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<signal.h>
int main()
{
    signal(SIGINT, SIG_IGN);
    while(1);
    printf("Hello World\n");
    return 0;
}
