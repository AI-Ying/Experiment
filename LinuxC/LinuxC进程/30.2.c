/*************************************************************************
	> File Name: 30.2.c
	> Author: 
	> Mail: 
	> Created Time: 2016年04月20日 星期三 20时28分57秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int main()
{
    printf("PATH=%s\n", getenv("PATH"));
    setenv("PATH", "hello", 1);
    printf("PATH=%s\n", getenv("PATH"));
    return 0;
}
