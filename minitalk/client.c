#include "minitalk.h"

volatile sig_atomic_t wait_not_wait = WAIT;

void    message_received(int signo)
{
    (void)signo;
    write(1,"message received\n",18);
    exit(EXIT_SUCCESS);
}
void    wait_process(int signo)
{
    (void)signo;
    wait_not_wait = READY;
}
void    send_char(char c, pid_t pid)
{
    int bit;
    
    bit = 0;

    while(bit < 8)
    {
        if(c & (0x80 >> bit))
            Kill(pid,SIGUSR1);
        else
            Kill(pid,SIGUSR2);
        bit++;
    
        while(WAIT == wait_not_wait)
            usleep(100);
        wait_not_wait = WAIT;
    }
}

int main(int argc,char **argv)
{
    pid_t pid;
    char *message;
    int i;

    i = 0;

    if(argc != 3)
    {
        write(2,"./client <PID_SERVER> <message>\n",33);
        exit(EXIT_FAILURE);
    }
    pid = atoi(argv[1]);
    message = argv[2];

    Signal(SIGUSR1, wait_process, false);
    Signal(SIGUSR2, message_received, false);
    while(message[i])
        send_char(message[i++],pid);
    send_char('\0',pid);
    return (EXIT_SUCCESS);
}