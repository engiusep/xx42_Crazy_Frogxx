/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiusep <engiusep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 15:45:23 by engiusep          #+#    #+#             */
/*   Updated: 2024/12/30 16:32:41 by engiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "pipex.h"

char	*ft_strdup(const char *s)
{
	int		size;
	char	*ptr;
	int		i;
	int		j;
	j = 0;
	i = -1;
	size = strlen(s);
	ptr = malloc(size + 1);
	if (!ptr)
		exit(EXIT_FAILURE);
	while (s[++i])
		ptr[i] = s[i];
	ptr[i] = '\0';
	return (ptr);
}
t_test	creat_struct(char **argv)
{
	t_test	str;

	str.error = NULL;
	str.file = ft_strdup(argv[1]);
	if (!str.file)
		exit(EXIT_FAILURE);
	str.cmd = ft_strdup(argv[2]);
	if (!str.cmd)
	{
		free(str.file);	
		exit(EXIT_FAILURE);
	}
	str.cmd2 = ft_strdup(argv[3]);
	if (!str.cmd2)
	{
		free(str.file);	
		free(str.cmd);	
		exit(EXIT_FAILURE);
		
	}
	str.file2 = ft_strdup(argv[4]);
	if (!str.file2)
	{
		free(str.file);	
		free(str.cmd);	
		free(str.cmd2);		
		exit(EXIT_FAILURE);
	}
	return (str);
}

void	child(int *pipefd, t_test *str, char **env)
{
	int		fd;
	char	*path;
	char	**s_cmd;
	s_cmd = ft_split(str->cmd, ' ');
	if(!s_cmd)
	{
		perror("");
		exit(EXIT_FAILURE);
	}
	fd = open(str->file, O_RDONLY);
	if (fd == -1)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
	dup2(fd, STDIN_FILENO);         // lecture
	dup2(pipefd[1], STDOUT_FILENO); // ecriture
	close(pipefd[0]);
	path = ft_get_path(s_cmd[0], env);
	close(fd);
	if(execve(path, s_cmd, env) == -1)
	{
		free_split(s_cmd,0);
		perror("error");
		exit(EXIT_FAILURE);
	}
	
	
}

void	parent(int *pipefd, t_test *str, char **env)
{
	int		fd;
	char	*path;
	char	**s_cmd;
	s_cmd = ft_split(str->cmd2, ' ');
	if(!s_cmd)
	{
		perror("Error malloc");
		exit(EXIT_FAILURE);
	}
	fd = open(str->file2, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd == -1)
	{
		close(pipefd[1]);
		close(pipefd[0]);
		perror("Error opening or creating file");
		exit(EXIT_FAILURE);
	}
	dup2(pipefd[0], STDIN_FILENO);
	dup2(fd, STDOUT_FILENO);
	close(pipefd[1]);
	path = ft_get_path(s_cmd[0], env);
	if(!path)
	{
		free_split(s_cmd,0);
		perror("Error allocating command argumetns");
		exit(EXIT_FAILURE);
	}
	close(fd);
	if(execve(path, s_cmd, env) == -1)
	{
		free_split(s_cmd,0);
		perror("Error");
		exit(EXIT_FAILURE);
	}
	free_split(s_cmd,0);
}
void	free_struct(t_test str)
{
	free(str.file);
	free(str.cmd);
	free(str.cmd2);
	free(str.file2);
}

int	main(int argc, char **argv, char **env)
{
	int pipefd[2];
	pid_t pid;
	t_test str;
	int status;
	int exit_status;
	if (argc != 5)
	{
	 	write(2, "ERROR\n", 6);
	 	exit(EXIT_FAILURE);
	 }
	str = creat_struct(argv);
	if (pipe(pipefd) == -1)
	{
		perror("ERROR");
		return (0);
	}
	pid = fork();
	if (pid == 0)
		child(pipefd, &str, env);
	waitpid(pid,&status,0);
	if(WIFEXITED(status))
	{
		exit_status = WEXITSTATUS(status);
		if(exit_status != EXIT_SUCCESS)
		{
			exit(EXIT_FAILURE);
			close(pipefd[1]);
			close(pipefd[0]);
		}
	}
	pid = fork();
	if(pid == 0)
		parent(pipefd, &str, env);
	free_struct(str);	
	exit(EXIT_SUCCESS);
}
