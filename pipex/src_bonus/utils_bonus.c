/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiusep <engiusep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 16:33:36 by engiusep          #+#    #+#             */
/*   Updated: 2024/12/30 16:38:25 by engiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

#include "../../libft/libft.h"
#include "pipex.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while ((*s1 || *s2) && n--)
	{
		if (*s1 != *s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		s1++;
		s2++;
	}
	return (0);
}

char	*get_env(char *name, char **env)
{
	int	i;
	int	j;

	i = 0;
	while (env[i])
	{
		j = 0;
		while (env[i][j] && env[i][j] != '=')
			j++;
		if (ft_strncmp(env[i], name, j) == 0 && name[j] == '\0') // '=';
			return (env[i] + j + 1);
		i++;
	}
	return (NULL);
}

void	free_split(char **split, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		free(split[i]);
		i++;
	}
	free(split);
}

char	*ft_get_path(char *cmd, char **env)
{
	int		i;
	char	**path_split;
	char	*cmd_path;
	char	*temp;
	char	*path;

	i = 0;
	path = get_env("PATH", env);
	path_split = ft_split(path, ':');
	if (!path_split)
		exit(EXIT_FAILURE);
	while (path_split[i])
	{
		temp = ft_strjoin(path_split[i], "/");
		cmd_path = ft_strjoin(temp, cmd);
		free(temp);
		if (access(cmd_path, F_OK | X_OK) == 0)
		{
			free_split(path_split,i);
			return (cmd_path);
		}
		free(cmd_path);
		i++;
	}
	write(2, "cmd not found\n", 14);
	exit(EXIT_FAILURE);
}