/*************************************************************************
	> File Name: upper.c
	> Author: 
	> Mail: 
	> Created Time: 2016年04月20日 星期三 21时04分16秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
    int ch;
    while ((ch = getchar()) != EOF)
    {
        putchar(toupper(ch));
    }
    return 0;
}
