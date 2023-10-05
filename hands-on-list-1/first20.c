#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/time.h>
#include<sys/resource.h>

int main() {
    int current_priority, new_priority;

    current_priority = getpriority(PRIO_PROCESS, 0);
    if (current_priority == -1) {
        perror("Error getting priority");
        return 1;
    }

    printf("Current priority: %d\n", current_priority);

    printf("Enter new priority value (-20 to 19): ");
    scanf("%d", &new_priority);

    if (new_priority < -20 || new_priority > 19) {
        printf("Invalid priority value. Priority range: -20 to 19\n");
        return 1;
    }

    if (nice(new_priority) == -1) {
        perror("Error setting new priority");
        return 1;
    }

    current_priority = getpriority(PRIO_PROCESS, 0);
    if (current_priority == -1) {
        perror("Error getting priority");
        return 1;
    }

    printf("Updated priority: %d\n", current_priority);

    return 0;
}

