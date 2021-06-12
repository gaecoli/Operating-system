#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// exit()
// exit(0) 表示正常退出, 其他为非正常退出 

int main(int argc, char *argv[]) {
    int pid = fork();
    if (pid < 0) {
        fprintf(stderr, "fork() failed\n");
        exit(1);
    } else if (pid == 0) {
        printf("hello\n");
        exit(0);
    } else {
        printf("good bye\n");
    }

    return 0;
}