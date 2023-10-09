#include <stdio.h>
#include <signal.h>
#include <sys/time.h>

void sigvtalrm_handler(int signum) {
    printf("Caught SIGVTALRM\n");
}

int main() {
    struct itimerval timer;

    timer.it_value.tv_sec = 3;
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 3;
    timer.it_interval.tv_usec = 0;

    signal(SIGVTALRM, sigvtalrm_handler);

    if (setitimer(ITIMER_VIRTUAL, &timer, NULL) == -1) {
        perror("setitimer");
        return 1;
    }

    while (1) {
    }

    return 0;
}

