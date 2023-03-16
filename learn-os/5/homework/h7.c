//
// Created by Chanmoey on 2023/3/17.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>


int main(int argc, char* argv[]) {
    printf("hello world (pid:%d)\n", (int) getpid());

    int rc = fork();

    if(rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if(rc == 0) {
        printf("close the STDOUT_FILENO in child process");
        close(STDOUT_FILENO);
        printf("关闭标准输出后，在子进程使用printf会怎样");
    } else{
        int wc = wait(NULL);
        printf("关闭标准输出后，在父进程使用printf会怎样");
    }

    return 0;
}