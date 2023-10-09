#include <stdio.h>
#include <signal.h>
#include <sys/time.h>

void sigprof_handler(int signum) {
    printf("Caught SIGPROF (using setitimer system call)\n");
}

int main() {
    struct itimerval timer;
    timer.it_value.tv_sec = 5;
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 0;
    timer.it_interval.tv_usec = 0;

    signal(SIGPROF, sigprof_handler);
    setitimer(ITIMER_PROF, &timer, NULL);

    while (1) {
    }
    return 0;
}
