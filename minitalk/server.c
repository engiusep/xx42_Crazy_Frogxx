/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiusep <engiusep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 11:00:58 by engiusep          #+#    #+#             */
/*   Updated: 2025/03/10 14:19:28 by engiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int signo, siginfo_t *info)
{
	static char		c;
	static int		bit;
	static pid_t	pid_process;

	if (info->si_pid)
		pid_process = info->si_pid;
	if (SIGUSR1 == signo)
		c |= (0x80 >> bit);
	else if (SIGUSR2 == signo)
		c &= ~(0x80 >> bit);
	bit++;
	if (bit == 8)
	{
		bit = 0;
		if (c == '\0')
		{
			write(1, "\n", 1);
			my_kill(pid_process, SIGUSR2);
			c = 0;
			return ;
		}
		write(1, &c, 1);
		c = 0;
	}
	kill(pid_process, SIGUSR1);
}

int	main(int argc, char **argv)
{
	(void)argv;
	if (argc != 1)
	{
		write(2, "You just need to run the program ./server.\n", 44);
		return (EXIT_FAILURE);
	}
	write(1, "PID server = ", 14);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	my_signal(SIGUSR1, handler, true);
	my_signal(SIGUSR2, handler, true);
	while (1)
		pause();
	return (EXIT_SUCCESS);
}
