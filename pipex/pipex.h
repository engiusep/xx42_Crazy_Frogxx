/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiusep <engiusep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 15:57:11 by engiusep          #+#    #+#             */
/*   Updated: 2024/12/29 18:51:50 by engiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

#include "../libft/libft.h"
typedef struct s_test
{
	char *file;
	char *file2;
	char *cmd;
	char *cmd2;
}t_test;

char *ft_get_path(char *cmd,char **env, int boolean);
char *get_env(char *name,char **env);

#endif