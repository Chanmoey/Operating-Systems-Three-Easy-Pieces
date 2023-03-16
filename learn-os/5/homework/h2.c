//
// Created by Chanmoey on 2023/3/16.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>


int main(int argc, char *argv[]) {
    printf("作业第二题，父子进程共同写文件\n", (int) getpid());
    close(STDOUT_FILENO);
    open("./h2.output", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        printf("child process write file, my pid: %d\n", getpid());
    } else {
        printf("parent process write file, my pid: %d\n", getpid());
    }

    return 0;
}
