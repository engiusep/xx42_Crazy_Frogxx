#include "minitalk.h"

void    handler(int signo, siginfo_t *info)
{
    static char c;
    static int bit;
    static pid_t pid_process;

    if(info->si_pid)
        pid_process = info->si_pid;
    if(SIGUSR1 == signo)
        c |= (0x80 >> bit);
    else if(SIGUSR2 == signo)
        c &= ~(0x80 >> bit);
    bit++;
    if(bit == 8)
    {
        bit = 0;
        if(c == '\0')
        {
            write(1, "\n",1);
            Kill(pid_process, SIGUSR2);
            c = 0;
            return ;
        }
        write(1, &c, 1);
        c = 0;
    }
    kill(pid_process,SIGUSR1);
}

int  main(void)
{
    printf("PID server = %d\n",getpid());
    Signal(SIGUSR1,  handler, true);
    Signal(SIGUSR2, handler, true);
    while(1)
        pause();
    return EXIT_SUCCESS;
}