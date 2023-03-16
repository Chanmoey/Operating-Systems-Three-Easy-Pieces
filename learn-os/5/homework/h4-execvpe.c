//
// Created by Chanmoey on 2023/3/17.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>


int main(int argc, char *argv[]) {
    printf("hello world (pid:%d)\n", (int) getpid());

    int rc = fork();

    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        // 子程序，通过exec()进行替换
        char *filepath = "/bin/ls";
        char *command = "ls";
        char *param = "./";
        char *args[] = {command, param, NULL};
        execvpe(filepath, args, NULL);
    } else {
        printf("I am parent, I done\n");
    }

    return 0;
}