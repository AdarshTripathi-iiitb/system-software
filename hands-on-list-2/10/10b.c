#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void sigint_handler(int signum, siginfo_t *info, void *context) {
    printf("Caught SIGINT (Ctrl+C)\n");
    exit(0);
}

int main() {
    struct sigaction sa;
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = sigint_handler;

    if (sigaction(SIGINT, &sa, NULL) == -1) {
        perror("sigaction");
        return 1;
    }

    while (1) {
        // Infinite loop to keep the program running
    }

    return 0;
}

