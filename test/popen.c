#include <stdio.h>      
#include <stdlib.h>     
#include <unistd.h>     
#include <sys/types.h>
#include <sys/wait.h>   




int ft_popen(char *command,char *argv[],char mod)
{
    int fd[2];
    pid_t pid;

    pid  = fork();
    if(pid == 0)
    {
        if(mod == 'r')
        {
            close(fd[0]);
            dup2(fd[1],STDOUT_FILENO);
        }
        else if(mod == 'w')
        {
            close(fd[1]);
            dup2(fd[0],STDIN_FILENO);
        }
        close(fd[0]);
        close(fd[1]);
        execvp(command,argv);
    }
    if(mod == 'r')
    {
        close(fd[1]);
        return(fd[0]);
    }
    else if(mod == 'w')
    {
        close(fd[0]);
        return(fd[1]);
    }
    return (0);
}

int main()
{
	
	int fd = ft_popen("ls", (char *[]){"ls", NULL}, 'w');

	char buf[1];
	while(read(fd, buf, 1))
		write(1, buf, 1);

	close(fd);
	return (0);
}