//
// Created by Chanmoey on 2023/3/16.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


int main(int argc, char* argv[]) {
    printf("hello world (pid:%d)\n", (int) getpid());

    int rc = fork();

    if(rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if(rc == 0) {
        printf("hello\n");
    } else{
        int wc = wait(NULL);
        printf("goodbye\n");
    }

    return 0;
}
