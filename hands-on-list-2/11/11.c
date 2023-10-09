#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

int main() {
    struct sigaction sa;
    sa.sa_handler = SIG_IGN; // Ignore SIGINT

    if (sigaction(SIGINT, &sa, NULL) == -1) {
        perror("sigaction");
        return 1;
    }

    printf("Press Ctrl+C to send SIGINT...\n");
    sleep(5);

    sa.sa_handler = SIG_DFL;
    if (sigaction(SIGINT, &sa, NULL) == -1) {
        perror("sigaction");
        return 1;
    }

    printf("Press Ctrl+C to send SIGINT again...\n");
    sleep(5);

    return 0;
}

