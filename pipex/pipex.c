/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiusep <engiusep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 15:45:23 by engiusep          #+#    #+#             */
/*   Updated: 2024/12/29 18:54:56 by engiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "../libft/libft.h"

char *ft_strdup(const char *s)
{
	int size;
	char *ptr;
	int i;
	int j;
	j = 0;
	i = -1;
	size = strlen(s);
	ptr = malloc(size + 1);
	if(!ptr)
		return (NULL);
	while(s[++i])
		ptr[i] =s[i];
	ptr[i] = '\0';
	return (ptr);
}
t_test creat_struct(char **argv)
{
	t_test str;
	
	str.file = ft_strdup(argv[1]);
	str.cmd = ft_strdup(argv[2]);
	str.cmd2 = ft_strdup(argv[3]);
	str.file2 = ft_strdup(argv[4]);
	return (str);
}

void child(int *pipefd,t_test *str,char **env)
{
	int fd;
	char *path;
	char **s_cmd;

	s_cmd = ft_split(str->cmd, ' ');
	fd = open(str->file,O_RDONLY,0777);
	dup2(fd,STDIN_FILENO); //lecture
	dup2(pipefd[1],STDOUT_FILENO); //ecriture
	close(pipefd[0]);
	path = ft_get_path(s_cmd[0],env, 0);
	execve(path,s_cmd,env);
}

void parent(int *pipefd, t_test *str,char **env)
{
	int fd;
	char *path;
	char **s_cmd;

	s_cmd = ft_split(str->cmd2, ' ');
	fd = open(str->file2,O_WRONLY | O_CREAT | O_TRUNC,0777);
	dup2(pipefd[0],STDIN_FILENO);
	dup2(fd,STDOUT_FILENO);
	close(pipefd[1]);
	path = ft_get_path(s_cmd[0],env, 1);
	execve(path,s_cmd,env);
}

int main(int argc, char **argv,char **env)
{
	int i;
	int pipefd[2];
	pid_t pid;
	t_test str;
	if(argc != 5)
	{
		write(1,"ERROR\n",6);
		return (0);
	}
	
	str = creat_struct(argv);
	if(pipe(pipefd) == -1)
	{
		perror("ERROR");
		return (0);
	}
	pid = fork();
	
	if (pid == 0)
		child(pipefd,&str,env);
	else
		parent(pipefd,&str,env);
	
}	