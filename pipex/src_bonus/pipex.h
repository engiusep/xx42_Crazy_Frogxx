/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiusep <engiusep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 15:57:11 by engiusep          #+#    #+#             */
/*   Updated: 2024/12/30 16:43:26 by engiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../../libft/libft.h"
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
}			t_test;

char		*ft_get_path(char *cmd, char **env);
char		*get_env(char *name, char **env);
void	free_split(char **split, int j);

#endif