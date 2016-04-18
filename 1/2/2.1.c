/*************************************************************************
	> File Name: 2.1.c
	> Author: 
	> Mail: 
	> Created Time: 2016年03月31日 星期四 15时12分33秒
 ************************************************************************/

#include<stdio.h>
#include <unistd.h>
#include <>

int main()
{
    int p1, p2, i;
    int *fp;
    fp = fopen("to_be_locked.txt", "W+");
    if (fp == NULL)
    {
        printf("Fail to create file");
        exit(-1);
    }

    if (p1 == 0)
    {
        lockf(*fp, 1, 0);
        for (i = 0; i < 10; i++)
            fprintf(fp, "daughter %d\n", i);
            lockf(*fp, 0, 0);
    }

    else
    {
        while ((p2 = fork()) == -1)
            ;
        if (p2 == 0)
        {
            lockf(*fp, 1, 0);
            for (i = 0; i < 10; i++)
            {
                fprintf(fp, "son %d\n", i);
                lockf(*fp, 0, 0);
            }
        }
        else
        {
            wait(NULL);
            lockf(*fp, 1, 0);
            for (i = 0; i < 10; i++)
                fprintf(fp, "parent %d\n", i);
                lockf(*fp, 0, 0);
        }
    }
    fclose(fp);
}
