#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
void sigint_handler(int signum) {
    printf("Caught SIGINT (Ctrl+C)\n");
    exit(0);
}

int main() {
    signal(SIGINT, sigint_handler);

    while (1) {
    }

    return 0;
}

