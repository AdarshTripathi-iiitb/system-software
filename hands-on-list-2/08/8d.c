#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void sigalrm_handler(int signum) {
    printf("Caught SIGALRM\n");
}

int main() {
    signal(SIGALRM, sigalrm_handler);
    
    alarm(5);
    
    while (1) {
    }

    return 0;
}
