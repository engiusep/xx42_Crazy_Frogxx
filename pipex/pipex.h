/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiusep <engiusep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 15:57:11 by engiusep          #+#    #+#             */
/*   Updated: 2025/01/08 16:25:13 by engiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
#include <sys/wait.h>

typedef struct s_test
{
	char	*file;
	char	*file2;
	char 	**cmds;
	char	*error;
	int		i;
	int saved;
}			t_test;

char		*ft_get_path(char *cmd, char **env);
char		*get_env(char *name, char **env);
void	free_split(char **split, int j);
char	*get_next_line(int fd);

#endif