/*************************************************************************
	> File Name: wrapper.c
	> Author: 
	> Mail: 
	> Created Time: 2016年04月21日 星期四 19时20分40秒
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<fcntl.h>

int main(int argc, char *argv[])
{
    int fd;
    if (argc != 2)
    {
        fputs("usage: wrapper file\n", stderr);
        exit(1);
    }
    fd = open(argv[1], O_RDONLY);
    if (fd<0)
    {
        perror("open");
        exit(1);
    }
    dup2(fd, STDIN_FILENO);
    close(fd);
    execl("./upper", "upper", NULL);
    perror("exec ./upper");
    exit(1);
}
