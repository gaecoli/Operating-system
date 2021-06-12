#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

/**
    pid_t waitpid(pid_t pid, int *status, int options);
    
    waitpid()会暂时停止目前进程的执行, 直到有信号来到或子进程结束. 如果在调用wait()时子进程
    已经结束, 则wait()会立即返回子进程结束状态值. 子进程的结束状态值会由参数status 返回, 而
    子进程的进程识别码也会一快返回. 如果不在意结束状态值, 则参数status 可以设成NULL. 参数pid 
    为欲等待的子进程识别码, 其他数值意义如下：
    1、pid<-1 等待进程组识别码为pid绝对值的任何子进程.
    2、pid=-1 等待任何子进程, 相当于wait().
    3、pid=0 等待进程组识别码与目前进程相同的任何子进程.
    4、pid>0 等待任何子进程识别码为pid 的子进程.

    参数option 可以为0 或下面的OR 组合：
    1、WNOHANG：如果没有任何已经结束的子进程则马上返回, 不予以等待；
    2、WUNTRACED：如果子进程进入暂停执行情况则马上返回, 但结束状态不予以理会. 子进程的结束状态返回后存于status, 底下有几个宏可判别结束情况；
    3、WIFEXITED(status)：如果子进程正常结束则为非0 值；
    4、WEXITSTATUS(status)：取得子进程exit()返回的结束代码, 一般会先用WIFEXITED 来判断是否正常结束才能使用此宏；
    5、WIFSIGNALED(status)：如果子进程是因为信号而结束则此宏值为真；
    6、WTERMSIG(status)：取得子进程因信号而中止的信号代码, 一般会先用WIFSIGNALED 来判断后才使用此宏；
    7、WIFSTOPPED(status)：如果子进程处于暂停执行情况则此宏值为真. 一般只有使用WUNTRACED时才会有此情况；
    8、WSTOPSIG(status)：取得引发子进程暂停的信号代码, 一般会先用；
    9、WIFSTOPPED 来判断后才使用此宏。
*/

int main(int argc, char *argv[]) {
    int pid = fork();
    if (pid < 0) {
        fprintf(stderr, "fork() failed\n");
        exit(1);
    } else if (pid == 0) {
        // sleep(1);
        int cc = waitpid(pid, NULL, 0);
        printf("i am child (cc: %d)\n", cc);
    } else {
        int wc = waitpid(pid, NULL, 0);
        printf("i am parent (wc: %d)\n", wc);
    }

    return 0;
}