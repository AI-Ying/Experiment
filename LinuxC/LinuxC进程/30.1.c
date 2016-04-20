/*************************************************************************
	> File Name: 30.1.c
	> Author: 
	> Mail: 
	> Created Time: 2016年04月20日 星期三 20时18分38秒
 ************************************************************************/

#include<stdio.h>
int main()
{
    extern char **environ;
    int i;
    for (i = 0; environ[i] != NULL; i++)
        printf("%s\n", environ[i]);
    return 0;
}
