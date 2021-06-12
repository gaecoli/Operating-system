#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc, char *argv[]) {
    printf("hello world (pid: %d)\n", (int)getpid());

    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        printf("hello, i am chiled!");
        char *myargs[3];
        myargs[0] = strdup("wc");
        myargs[1] = strdup("exec.c");
        myargs[2] = NULL;

        execvp(myargs[0], myargs);
        printf("this shouldn't print out");
    } else {
        int wc = wait(NULL);
        printf("hello, i am parent (wc: %d)\n", wc);
    }

    return 0;
}