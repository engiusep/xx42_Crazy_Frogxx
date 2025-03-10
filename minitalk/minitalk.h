/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiusep <engiusep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:07:01 by engiusep          #+#    #+#             */
/*   Updated: 2025/03/10 12:27:45 by engiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <limits.h>
# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define WAIT 0
# define READY 1

void	my_signal(int signo, void *handler, bool use_siginfo);
void	my_kill(pid_t pid, int signo);
int		ft_atoi(const char *str);
void	ft_putnbr_fd(int n, int fd);
#endif
