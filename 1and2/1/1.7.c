/*************************************************************************
	> File Name: 1.7.c
	> Author: 
	> Mail: 
	> Created Time: 2016年04月26日 星期二 10时14分57秒
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>

int  main()
{
    int p1, p2, i;
    p1 = fork();                 /*创建子进程*/
    if (p1 == 0)
    {
        lockf(1, 1, 0);         /*加锁，这里第一个参数为stdout(标准输出设备的描述符)*/
        for (i = 0; i < 10; i++) 
        {
            printf("child1 = %d\n", i);
            sleep(1);
        }
        lockf(1, 0, 0);         /*解锁*/
    }
    else
    {
        p2 = fork();            /*创建子进程*/
        if (p2 == 0)
        {
            lockf(1, 1, 0);     /*加锁*/
            for (i = 0; i < 10; i++)
            {
                printf("child2 = %d\n", i);
                sleep(1);
            }
            lockf(1, 0, 0);     /*解锁*/
        }
        else
        {
            lockf(1, 1, 0);     /*加锁*/
            for (i = 0; i < 10; i++)
            {
                printf("parent %d\n", i);
                sleep(1);
            }
            lockf(1, 0, 0);     /*解锁*/
        }
    }
    return 0;
}
