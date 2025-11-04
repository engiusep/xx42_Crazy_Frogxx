#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>


int picoshell(char **cmds[])
{
    int i = 0;
    pid_t pid;
    int in_fd = 0;
    int fd[2];


    while(cmds[i])
    {
        if(cmds[i  + 1])
        {
            pipe(fd);
        }
        else
        {
            fd[1] = -1;
            fd[0] = -1;
        }

        pid = fork();
        if(pid == 0)
        {
            if(in_fd != 0)
            {
                dup2(in_fd,STDIN_FILENO);
                close(in_fd);
            }
            execvp(cmds[0][i],cmds[i]);
        }
        else
        {
            if(in_fd != 0)
                close(in_fd);
            if()
            in_fd = fd[0];
        }
        i++;
    }
    return 1;
}



int main() {
    char *cmd1[] = {"ls", "-l", NULL};
    char *cmd2[] = {"grep", "test", NULL};
    char **cmds[] = {cmd1, cmd2, NULL};

    int ret = picoshell(cmds);
    return ret;
}
