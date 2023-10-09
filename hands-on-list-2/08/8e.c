#include <stdio.h>
#include <signal.h>
#include <sys/time.h>

void sigalrm_handler(int signum) {
    printf("Caught SIGALRM\n");
}

int main() {
    struct itimerval timer;
    
    timer.it_value.tv_sec = 5;
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 5;
    timer.it_interval.tv_usec = 0;

    signal(SIGALRM, sigalrm_handler);

    if (setitimer(ITIMER_REAL, &timer, NULL) == -1) {
        perror("setitimer");
        return 1;
    }

    while (1) {
    }

    return 0;
}

