//
// Created by Chanmoey on 2023/3/16.
//
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int x = 0;

int main(int argc, char* argv[]) {
    printf("我是父进程，首次进来，x的值为：%d\n", x);
    x = 100;
    printf("我是父进程，我将x的值改为100，x的值为：%d\n", x);

    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "创建子进程失败\n");
        exit(1);
    } else if (rc == 0) {
        printf("我是子进程，我首次进来，看到x的值为：%d\n", x);
        x =50;
        printf("我是子进程，我将x的值改为50，x的值为：%d\n", x);
    } else {
        int wc = wait(NULL);
        printf("我是父进程，创建完子进程后，x的值为：%d\n", x);
    }
}