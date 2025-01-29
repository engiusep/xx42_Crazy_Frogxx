#include "minitalk.h"

void    send_char(int pid,char c)
{
    int bit;
    bit = 0;

    while(bit < 8)
    {
        if((c >> bit) & 1)
            kill(pid,SIGUSR1);
        else
            kill(pid,SIGUSR2);
        usleep(100);
        bit++;
    }
}

int main(int argc,char **argv)
{
    int i;
    i = 0;
    pid_t pid;
    if(argc != 3)
    {
        printf("Usage %s <PID> <Message> \n",argv[0]);
            return (1);
    }
    pid = atoi(argv[1]);
    while(argv[2][i])
        send_char(pid,argv[2][i++]);

}