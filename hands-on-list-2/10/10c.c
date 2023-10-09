#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void sigfpe_handler(int signum, siginfo_t *info, void *context) {
    printf("Caught SIGFPE (Floating-Point Exception)\n");
    exit(1);
}

int main() {
    struct sigaction sa;
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = sigfpe_handler;

    if (sigaction(SIGFPE, &sa, NULL) == -1) {
        perror("sigaction");
        return 1;
    }

    int result = 10 / 0; // This will trigger a floating-point exception

    return 0;
}
