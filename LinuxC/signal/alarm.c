/*************************************************************************
	> File Name: alarm.c
	> Author: 
	> Mail: 
	> Created Time: 2016年04月26日 星期二 19时58分25秒
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>

int main()
{
    int counter;
    alarm(1);
    for (counter=0; 1; counter++)
    {
        printf("counter = %d", counter);
    }
    return 0;
}
