#include <stdio.h>      
#include <stdlib.h>     
#include <unistd.h>     
#include <sys/types.h>
#include <sys/wait.h>   





int ft_popen(const char *file, char *const av[], int type)
{
  int   fd[2];
  pid_t pid;
  pipe(fd);

  pid = fork();
  if(pid == 0)
  {
    if(type == 'r')
    {
        close(fd[0]);
        dup2(fd[1],1);
        close(fd[1]);
    }
    if(type == 'w')
    {
        close(fd[1]);
        dup2(fd[0],0);
        close(fd[0]);
    }
    execvp(file,av);
  }
  else
  {
    if(type == 'r')
    {
        close(fd[1]);
        return(fd[0]);
    }
    else
    {
        close(fd[0]);
        return(fd[1]);
    }
  }
  return 0;
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