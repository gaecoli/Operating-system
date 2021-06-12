// fork() 系统调用

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
    fork() 返回值
    1. 父进程中，返回新创建子进程的 pid；
    2. 子进程中，fork 返回 0；
    3. 如果 fork() 发生错误，返回一个负值;
*/

int main(int argc, char *argv[]) {
    // 获取进程主进程 id
    printf("hello world (pid: %d)\n", (int)getpid());
    
    int rc = fork();    // fork() 返回新进程的 pid
    if (rc < 0) {   // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {   // child (new process)
        printf("hello, i am child process, my pid is: (%d)\n", (int)getpid());
    } else {    // parent goes down this path (main)
        printf("hello, i am parent of %d (pid: %d)\n", rc, (int)getpid());
    }

    return 0;
}