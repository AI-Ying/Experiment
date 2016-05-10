/*************************************************************************
	> File Name: syscall.c
	> Author: 
	> Mail: 
	> Created Time: 2016年04月29日 星期五 13时18分06秒
 ************************************************************************/

#include<linux/unistd.h>
#include<sys/syscall.h>

#define _NR_ai 666

int main()
{
    syscall(666);
    return 0;
}
