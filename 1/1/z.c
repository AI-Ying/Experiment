/*************************************************************************
	> File Name: z.c
	> Author: 
	> Mail: 
	> Created Time: 2016年05月02日 星期一 21时42分19秒
 ************************************************************************/
#include<unistd.h>
#include<signal.h>
#include<stdio.h>
int main()
{
    signal(SIGINT, SIG_IGN);
    fork();
    while(1);
    fork();
    fork();
    sleep(5);
    return 0;
    
}
