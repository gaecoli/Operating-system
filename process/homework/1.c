#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void test1();
void test2();

int main(int argc, char *argv[]) {
    if (argc == 1) {
        test1();
    } else {
        test2();
    }

    return 0;
}

void test1() {
    int x = 100;
    int pid = fork();
    if(pid < 0) {
        fprintf(stderr, "fork() failed\n");
        exit(1);
    } else if (pid == 0) {
        printf("i am child, x: %d\n", x);
    } else {
        printf("i am parent, x: %d\n", x);
    }
}

void test2() {
    int x = 100;
    int pid = fork();
    if(pid < 0) {
        fprintf(stderr, "fork() failed\n");
        exit(1);
    } else if (pid == 0) {
        printf("i am child, x: %d\n", x);
        x = 0;
        printf("in child (x: %d)\n", x);
    } else {
        printf("i am parent, x: %d\n", x);
        x = 11;
        printf("in parent (x: %d)\n", x);
    }
}
