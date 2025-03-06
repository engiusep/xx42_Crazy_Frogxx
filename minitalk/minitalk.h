/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiusep <engiusep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:07:01 by engiusep          #+#    #+#             */
/*   Updated: 2024/11/25 17:08:43 by engiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <stdio.h>
# include <limits.h>
# include <stdbool.h>

#define WAIT 0
#define READY 1

void    Signal(int signo, void *handler, bool use_siginfo);
void Kill(pid_t pid,int signo);
#endif
