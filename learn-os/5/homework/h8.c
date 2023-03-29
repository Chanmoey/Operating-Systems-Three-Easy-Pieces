//
// Created by Chanmoey on 2023/3/30.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char* argv[]) {
    // 0读端，1写端
    int fd[2] = {0, 0};
    int sp = pipe(fd);

    if(sp != 0) {
        // 创建管道失败
        exit(-1);
    }

    // 创建两个子进程
    int p1 = fork();
    if(p1 < 0) {
        fprintf(stderr, "can not fork new process");
    } else if (p1 == 0) {
        // 第一个子进程写数据到pipe
        close(fd[0]);
        char* msg = "Hello World, I am p1";
        write(fd[1], msg, strlen(msg));
        close(fd[1]);
        printf("I am p1, send msg to p2 by pipe\n");
        return 0;
    }

    // 创建两个子进程
    int p2 = fork();
    if(p2 < 0) {
        fprintf(stderr, "can not fork new process");
    } else if (p2 == 0) {
        // 第一个子进程写数据到pipe
        waitpid(p1, NULL, 0);
        close(fd[1]);
        char buffer[1024];
        int len = read(fd[0], buffer, 1024);
        if (len > 0) {
            buffer[len] = '\0';
            printf("I am p2, recv msg from p2\n");
            int i;
            for (i = 0; i < len; ++i) {
                printf("%c", buffer[i]);
            }
            printf("\n");
        }

        return 0;
    }

    waitpid(p1, NULL, 0);
    waitpid(p2, NULL, 0);

    printf("I am father, all exit\n");
    return 0;
}