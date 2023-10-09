#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
void sigfpe_handler(int signum) {
    printf("Caught SIGFPE (Floating-Point Exception)\n");
    exit(1);
}

int main() {
    signal(SIGFPE, sigfpe_handler);

    int result = 5 / 0;

    return 0;
}
