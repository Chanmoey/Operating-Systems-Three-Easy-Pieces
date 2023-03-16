//
// Created by Chanmoey on 2023/3/17.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


int main(int argc, char *argv[]) {
    printf("hello world (pid:%d)\n", (int) getpid());

    int ppid = getpid();
    int rc = fork();

    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        printf("hello, I am child (pid:%d)\n", (int) getpid());
        // 等待父进程
        int wc = waitpid(ppid, NULL, 0);
        printf("I am child, the wait return result is: %d\n", wc);
    } else {
        // 等待子进程
        int pwc = waitpid(rc, NULL, 0);
        printf("hello, I am parent of %d (wc:%d) (pid:%d)\n", rc, pwc, (int) getpid());
        printf("I am parent, the wait return result is: %d\n", pwc);
    }

    return 0;
}