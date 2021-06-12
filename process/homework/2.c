#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

// write() 函数
// ssize_twrite(int handle, void *buf, int nbyte)
// return > 0 表示写了部分 buf 内容或者全部 buf 内容
// return < 0 error

int main(int argc, char *argv[]) {
    int pid = fork();
    int fd = open("test.txt", O_CREAT | O_RDWR | O_TRUNC, S_IRWXU);
    if (pid < 0) {
        fprintf(stderr, "fork() failed\n");
        exit(1);
    } else if (pid == 0) {
        char *buf = "i am child\n";
        int error = write(fd, buf, sizeof(char) * strlen(buf));
        printf("child error: %d", error == -1 ? 1 : 0);
    } else {
        char *buf = "i am parent\n";
        int error = write(fd, buf, sizeof(char) * strlen(buf));
        printf("parent error: %d", error == -1 ? 1 : 0);

        int wc = wait(NULL);
        printf("wc: %d\n", wc);
        close(fd);
    }

    return 0;
}