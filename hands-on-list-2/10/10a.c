#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void sigsegv_handler(int signum, siginfo_t *info, void *context) {
    printf("Caught SIGSEGV (Segmentation Fault)\n");
    exit(1);
}

int main() {
    struct sigaction sa;
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = sigsegv_handler;

    if (sigaction(SIGSEGV, &sa, NULL) == -1) {
        perror("sigaction");
        return 1;
    }

    int *ptr = NULL;
    *ptr = 42; // This will trigger a segmentation fault

    return 0;
}

