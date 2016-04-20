/*************************************************************************
	> File Name: execlp.c
	> Author: 
	> Mail: 
	> Created Time: 2016年04月20日 星期三 20时59分53秒
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
    execlp("ps", "ps", "-o", "pid,ppid,pgrp,session,tpgid,comm", NULL);
    perror("exec ps");
    exit(1);
}
