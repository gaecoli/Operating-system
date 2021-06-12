#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    int pid = fork();
    if (pid < 0) {
        fprintf(stderr, "fork() failed\n");
        exit(1);
    } else if (pid == 0) {
        int cc = wait(NULL); 
        printf("i am child (cc: %d)\n", cc);
    } else {
        int wc = wait(NULL);
        printf("i am parent (wc: %d)\n", wc);
    }

    return 0;
}