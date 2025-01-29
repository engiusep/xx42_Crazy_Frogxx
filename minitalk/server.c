#include "minitalk.h"

void    take_signal(int sig)
{
    static int bit = 0;
    static char c = 0;

    if(sig == SIGUSR1)
        c|= (1 << bit); //transforme le bit en 1 
    bit++;
    if(bit == 8)
    {
        write(1,&c,1);
        bit = 0;
        c = 0;
    }
    
}
int    main(void)
{
    pid_t pid;

    pid = getpid();
    if(pid < 0)
        return (0);
    printf("pid server = %d\n",pid);
    signal(SIGUSR1,take_signal);
    signal(SIGUSR2,take_signal);
    while(1)
        pause();
}