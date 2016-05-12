/*************************************************************************
	> File Name: memory.c
	> Author: 
	> Mail: 
	> Created Time: 2016年05月12日 星期四 16时57分19秒
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>

#define n 10 //假定系统允许的最大作业为n,假定模拟实验中的n值为10
#define m 10 //既定系统允许的空闲区表最大为m,假定模拟实验中的m值为10
#define minisize 100


//定义已分配区表
struct 
{
    float address; //已分分区起始地址
    float length;  //已分分区长度，单位为字节
    int flag; //已分配区表登记栏标志，用'0'表示空栏目
              //'1'表示已分配
}used_table[n];

//定义空闲区表
struct
{
    float address;//空闲区起始地址
    float length; //空闲区长度，单位为字节
    int flag; //空闲区表登记栏标志，用'0'表示空栏目
              //用'1'表示未分配
}free_table[m]; 


int uflag; //分区表标志
int fflag; //空闲表标志
float uend_address;
float fend_address;

void allocate(char str, float leg)
{
    int k, i;
    float ressize;
    uflag = 0;
    fflag = 0;

    for (i = 0; i < m; i++)
    {
        if (free_table[i].flag = 1 && free_table[i].length >= leg)
        {
            fflag = 1;
            break;
        }
    }
    
    if (fflag == 0)
    {
        printf("没有满足条件的空闲区!\n");
    }
    else
    {
        ressize = free_table[i].length - leg;
        for (k = 0; k < n; k++)
        {
            if (used_table[k].flag == 0)
            {
                if (ressize < minisize)
                {
                    used_table[k].length = free_table[i].length;
                    used_table[k].address = free_table[i].address;
                    used_table[k].flag = str;
                    free_table[i].length = 0;
                    free_table[i].flag = 0;
                    break;
                }
                else
                {
                    used_table[k].address = free_table[i].address + ressize;
                    used_table[k].flag = str;
                    used_table[k].length = leg;
                    free_table[i].length = ressize;
                    break;
                }
            }
        }
    }
}

void reclaim(char str)
{
    int k, i;
    uflag = 0; 
    fflag = 0;
    for (k = 0; k < n; k++)
    {
        if (used_table[k].flag == str)
        {
            uflag = 1;
            break;
        }
    }

    if (uflag == 0)
    {
        printf("\n找不到该作业\n");
    }
    else
    {
        for (i = 0; i < m; i++)
        {
            uend_address = used_table[k].address + used_table[k].length;
            fend_address = free_table[i].address + free_table[i].length;
            if (used_table[k].address == fend_address)
            {
                fflag = 1;
                free_table[i].length = free_table[i].length + used_table[k].length;
                free_table[i].flag = 1;
                used_table[k].flag = 0;
                used_table[k].length = 0;
                used_table[k].address = 0;
                printf("\n已回收\n");
                break;
            }
            else
            {
                if (free_table[i].address == uend_address)
                {
                    fflag = 1;
                    free_table[i].address = used_table[k].address;
                    free_table[i].length = used_table[k].length; + free_table[i].length;
                    used_table[i].flag = 1;
                    used_table[k].flag = 0;
                    used_table[k].length = 0;
                    used_table[k].address = 0;
                    printf("\n已回收\n");
                    break;
                }
            }
            if (fflag = 0)
            {
                i = 0;
                for (i = 0; i < m; i++)
                {
                    if (free_table[i].flag == 0)
                    {
                        free_table[i].address = used_table[k].address;
                        free_table[i].length = used_table[k].length;
                        free_table[i].flag = 1;
                        used_table[k].length = 0;
                        used_table[k].flag = 0;
                        used_table[k].address = 0;
                        break;
                    }
                }
                printf("\n已回收\n");
            }
        }
    }
}



int main()
{
    int i, a;
    
    //分配主存空间函数
    void allocate(char str, float leg); 

    //分配回收空间函数
    void reclaim(char str);

    float jobLen;
    char job;
    
    //空间分区表初始化
    free_table[0].address = 10240;
    free_table[0].length = 102400;
    free_table[0].flag = 1;
    for(i = 1; i < n; i++)
    {
        free_table[i].flag = 0;
    }

    //已分配表初始化
    for (i = 0; i < m; i++)
    {
        used_table[i].flag = 0;
    }

    while (1)
    {
        printf("\n选择功能项(0-退出,1-分配主存,2-回收主存,3-显示主存)\n");
        printf("选择功项(0-3):");
        scanf("%d", &a);
        switch(a)
        {
            case 0:
                {
                    exit(0);
                }
            case 1:
                {
                    printf("输入作业名job和作业所需长度jobLen:");
                    scanf("%*c%c%f", &job, &jobLen);
                    allocate(job, jobLen);
                    break;
                }
            case 2:
                {
                    printf("输出要回收的作业名：");
                    scanf("%*c%c", &job);
                    reclaim(job);
                    break;
                }
            case 3:
                {
                    printf("输出空闲区表：\n起始地址\t分区长度\t标志\n");
                    for (i = 0; i < m; i++)
                    {
                        printf("%6.0f%9.0f%6d\n", free_table[i].address,free_table[i].length, free_table[i].flag);
                    }
                    printf("按任意键，输出已分配区表\n");
                    getchar();
                    printf("输出已分配区表：\n起始地址\t分区长度\t标志\n");
                    for (i = 0; i < n; i++)
                    {
                        if (used_table[i].flag != 0)
                            printf("%6.0f%9.0f%6c\n", used_table[i].address, used_table[i].length, used_table[i].flag);
                        else
                            printf("%6.0f%9.0f%6d\n", used_table[i].address, used_table[i].length, used_table[i].flag);
                    }
                }
            default :
                {
                     printf("输入错误！\n");
                }
        }
    }

    return 0; 
}


