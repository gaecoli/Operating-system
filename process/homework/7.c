#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  int pid = fork();
  if (pid < 0) {
    printf("fork error\n");
    exit(1);
  } else if (pid == 0) {
    close(STDOUT_FILENO);
    printf("child\n");  // 不会被打印，close() 发生了错误
  } else {
    int wc = wait(NULL);
    printf("%d\n", wc);
  }
  return 0;
}