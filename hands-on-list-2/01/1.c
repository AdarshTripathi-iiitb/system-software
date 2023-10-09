#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <signal.h>
#include <unistd.h>

void timer_handler(int signo) {
    if (signo == SIGALRM) {
        printf("ITIMER_REAL timer expired.\n");
    }
}

int main() {
    struct itimerval timer;

    timer.it_value.tv_sec = 10;          // Initial timer value (10 seconds)
    timer.it_value.tv_usec = 10;         // Initial timer value (10 microseconds)
    timer.it_interval.tv_sec = 10;       // Interval for subsequent timer fires (10 seconds)
    timer.it_interval.tv_usec = 10;      // Interval for subsequent timer fires (10 microseconds)
    
    signal(SIGALRM, timer_handler);

    if (setitimer(ITIMER_REAL, &timer, NULL) == -1) {
        perror("setitimer");
        return 1;
    }
    while(1);


    return 0;
}

