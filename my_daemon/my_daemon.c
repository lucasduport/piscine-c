#define _DEFAULT_SOURCE
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

void handler(int signum)
{
    static int count = 0;
    static int generation = 0;
    count++;
    switch (signum)
    {
    case SIGUSR1:
        fflush(stdout);
        printf("Received %d signals.\n", count);
        break;
    case SIGUSR2:
        fflush(stdout);
        printf("Current generation: %d\n", generation);
        break;
    case SIGTERM:
        generation++;
        count = 0;
        pid_t p = fork();
        if (p != 0)
            exit(0);
        break;
    default:
        exit(0);
        break;
    }
}

int main(void)
{
    struct sigaction sa;
    sa.sa_flags = 0;
    sa.sa_handler = handler;
    pid_t p = fork();
    if (p != 0)
        exit(0);
    // One if per signal !!!
    if (sigemptyset(&sa.sa_mask) < 0)
    {}
    if (sigaction(SIGINT, &sa, NULL) < 0)
    {}
    if (sigaction(SIGUSR1, &sa, NULL) < 0)
    {}
    if (sigaction(SIGUSR2, &sa, NULL) < 0)
    {}
    if (sigaction(SIGTERM, &sa, NULL) < 0)
    {}
    while (1)
        ;
    return 0;
}
