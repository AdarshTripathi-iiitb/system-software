#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void sigint_handler(int signum) {
    printf("SIGINT (Ctrl+C) signal ignored.\n");
}

int main() {
    signal(SIGINT, sigint_handler);

    printf("Press Ctrl+C to send SIGINT...\n");
    sleep(5); // Sleep for 5 seconds to allow sending SIGINT

    signal(SIGINT, SIG_DFL);

    printf("Press Ctrl+C to send SIGINT again...\n");
    sleep(5);

    return 0;
}

