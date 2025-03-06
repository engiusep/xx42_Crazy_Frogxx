#include "minitalk.h"

void    Signal(int signo, void *handler, bool use_siginfo)
{
    struct  sigaction sa = {0};

    if(use_siginfo)
    {
        sa.sa_sigaction = handler;
        sa.sa_flags = SA_SIGINFO;
    }
    else
        sa.sa_handler = handler;

    sigemptyset(&sa.sa_mask);
    sigaddset(&sa.sa_mask,SIGUSR1);
    sigaddset(&sa.sa_mask,SIGUSR2);

    if(sigaction(signo, &sa, NULL) < 0)
    {
        write(2, "Sigaction failed\n",18);
        exit(EXIT_FAILURE);
    }
}

void Kill(pid_t pid,int signo)
{
    if(kill(pid, signo) < 0)
    {
        write(2,"kill failed\n",13);
        exit(EXIT_FAILURE);
    }
}