#include <sys/types.h> // for using `pid_t`
#include <unistd.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
    pid_t pid; // `int pid;` 로 해도 실행되기는 한다...
    int cnt = 1;

    pid = fork(); // returns 0 for child process, {child process's pid} for parent process

    switch (pid) {
        case -1: // fork()에 문제가 생겼을 경우의 리턴값이 항상 `-1`이라면 switch문을 써도 되는거 아닌가..?
            fprintf(stderr, "Fork failed!");
            return 1;
        case 0:
            printf("This is Child Process!\n");
            while (cnt < 4) {
                printf("%d'th iteration of CHILD\n", cnt);
                cnt++;
                sleep(1);
            }
            break;
        default:
            printf("This is Parent Process!\n");
            while (cnt < 4) {
                printf("%d'th iteration of PARENT\n", cnt);
                cnt++;
                sleep(1);
            }
            wait(NULL);
            printf("Processs Completed!\n");
    }
    return 0;
}

/* 원래 제공된 예제 코드:

    if (pid < 0) {
        fprintf(stderr, "Fork failed");
        return 1;
    }
    else if (pid == 0) {
        printf("Child here!\n");
        while (cnt < 6) {
            printf("Child num: %d\n", cnt);
            cnt++;
            sleep(1);
        }
    }
    else {
        printf("I'm Parent!\n");
        while (cnt < 6) {
            printf("Parent num: %d\n", cnt);
            cnt++;
            sleep(1);
        }
        wait(NULL);
        printf("Process Complete!\n");
    }
    return 0;

*/
