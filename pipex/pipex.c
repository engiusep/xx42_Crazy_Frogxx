/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiusep <engiusep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 15:45:23 by engiusep          #+#    #+#             */
/*   Updated: 2025/01/09 11:17:40 by engiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../get_next_line/get_next_line.h"
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
 t_test creat_struct_here_doc(char **argv,int argc)
 {
	t_test str;
    int i;
	int j;

    str.cmds = malloc((argc - 3 + 1) * sizeof(char *));
    if (!str.cmds)
        exit(EXIT_FAILURE);
    i = 3;
    j = 0;
    while (i < argc - 1) 
	{
        str.cmds[j] = ft_strdup(argv[i]);
        if (!str.cmds[j]) 
		{
            while (--j >= 0)
                free(str.cmds[j]);
            free(str.cmds);
            exit(EXIT_FAILURE);
        }
        i++;
        j++;
    }
    str.cmds[j] = NULL;
    str.file = ft_strdup(argv[1]);
    str.file2 = ft_strdup(argv[argc - 1]);
    if (!str.file || !str.file2) {
        j = 0;
        while (str.cmds[j])
            free(str.cmds[j++]);
        free(str.cmds);
        free(str.file);
        free(str.file2);
        exit(EXIT_FAILURE);
    }
	str.i = 0;
    return str;
 }
t_test creat_struct(char **argv, int argc) 
{
    t_test str;
    int i;
	int j;

    str.cmds = malloc((argc - 3 + 1) * sizeof(char *));
    if (!str.cmds)
        exit(EXIT_FAILURE);
    i = 2;
    j = 0;
    while (i < argc - 1) 
	{
        str.cmds[j] = ft_strdup(argv[i]);
        if (!str.cmds[j]) 
		{
            while (--j >= 0)
                free(str.cmds[j]);
            free(str.cmds);
            exit(EXIT_FAILURE);
        }
        i++;
        j++;
    }
    str.cmds[j] = NULL;
    str.file = ft_strdup(argv[1]);
    str.file2 = ft_strdup(argv[argc - 1]);
    if (!str.file || !str.file2) {
        j = 0;
        while (str.cmds[j])
            free(str.cmds[j++]);
        free(str.cmds);
        free(str.file);
        free(str.file2);
        exit(EXIT_FAILURE);
    }
	str.i = 0;
    return str;
}

void	child_pipe(int *pipefd, int *newfd, t_test *str, char **env)
{
	char	*path;
	char	**s_cmd;
	s_cmd = ft_split(str->cmds[str->i], ' ');
	if(!s_cmd)
	{
		perror("");
		exit(EXIT_FAILURE);
	}
	dup2(pipefd[0], STDIN_FILENO);  // lecture
	dup2(newfd[1], STDOUT_FILENO); // ecriture
	close(pipefd[0]);
	path = ft_get_path(s_cmd[0], env);
	if(execve(path, s_cmd, env) == -1)
	{
		free_split(s_cmd,0);
		perror("error");
		exit(EXIT_FAILURE);
	}
}

void	child(int *pipefd, t_test *str, char **env)
{
	int		fd;
	char	*path;
	char	**s_cmd;
	s_cmd = ft_split(str->cmds[str->i], ' ');
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

void	last_child(int *pipefd, t_test *str, char **env)
{
	int		fd;
	char	*path;
	char	**s_cmd;
	s_cmd = ft_split(str->cmds[str->i], ' ');
	if(!s_cmd)
	{
		perror("Error malloc");
		exit(EXIT_FAILURE);
	}
	if(ft_strncmp(str->file2,"here_doc",8) == 0)
		fd = open(str->file2, O_WRONLY | O_CREAT | O_APPEND, 0777);
	else
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
	free_split(str.cmds,0);
	free(str.file2);
}

void child_line(t_test *str, char **env)
{
	char	*path;
	char	**s_cmd;
	
	s_cmd = ft_split(str->cmds[str->i], ' ');
	if(!s_cmd)
	{
		perror("");
		exit(EXIT_FAILURE);
	}
	path = ft_get_path(s_cmd[0], env);
	if(execve(path, s_cmd, env) == -1)
	{
		free_split(s_cmd,0);
		perror("error");
		exit(EXIT_FAILURE);
	}
}

void pipeline(int *m_pipefd, t_test *str, char **env)
{
	int new_pipefd[2];
	pid_t pid;
	
	while (str->cmds[str->i + 1])
	{
		pipe(new_pipefd);
		pid = fork();
		if (pid == 0)
		{
			dup2(m_pipefd[0], STDIN_FILENO);
			dup2(new_pipefd[1], STDOUT_FILENO);
			close(m_pipefd[0]);
			close(new_pipefd[1]);
			child_pipe(m_pipefd, new_pipefd, str, env);
		}
		//close(m_pipefd[0]);
		//close(new_pipefd[1]);
		m_pipefd[0] = new_pipefd[0];
		str->i++;
	}
}

int	main(int argc, char **argv, char **env)
{
	int pipefd[2];
	pid_t pid;
	t_test str;
	int status;
	int exit_status;
	char *line;

	//str.saved = dup(STDOUT_FILENO);
	if(ft_strncmp(argv[1],"here_doc",8) == 0)
	{
		int fd_temp;
		fd_temp = open("here_doc", O_RDWR | O_CREAT, 0777);
		while(1)
		{		
			line = get_next_line(STDIN_FILENO);
			if(ft_strncmp(line,argv[2],ft_strlen(argv[2])) == 0)
				break;
			write(fd_temp,line,ft_strlen(line));		
		}
		str = creat_struct_here_doc(argv,argc);
	}
	else
		str = creat_struct(argv,argc);
	if (pipe(pipefd) == -1)
	{
		perror("ERROR");
		return (0);
	}
	pid = fork();
	if (pid == 0)
		child(pipefd, &str, env);
	str.i++;
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
	pipeline(pipefd, &str, env);
	pid = fork();
	if(pid == -1)
	{
		free_struct(str);
		exit(EXIT_FAILURE);
	}
	if(pid == 0)
		last_child(pipefd, &str, env);
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
		unlink("here_doc");
	free_struct(str);
	exit(EXIT_SUCCESS);
}
