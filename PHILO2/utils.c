/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiusep <engiusep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 13:10:12 by engiusep          #+#    #+#             */
/*   Updated: 2025/07/17 15:32:49 by engiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	long	num;
	int		i;

	num = 0;
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		if (num > INT_MAX)
			return (-1);
		i++;
	}
	if (str[i] != '\0')
		return (-1);
	return ((int)num);
}

long	get_time_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((long)(tv.tv_sec) *1000L + (long)(tv.tv_usec) / 1000L);
}

void	unlocked(t_philo *philo)
{
	if (philo->right == 1)
	{
		philo->right = 0;
		pthread_mutex_unlock(philo->right_fork);
	}
	if (philo->left == 1)
	{
		philo->left = 0;
		pthread_mutex_unlock(philo->left_fork);
	}
}

void	locked(t_philo *philo, int i)
{
	if (i == 1)
	{
		philo->right = 1;
		print_mutex(philo, "has taken a fork");
	}
	if (i == 2)
	{
		philo->left = 1;
		print_mutex(philo, "has taken a fork");
	}
}

int	take_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	locked(philo, 1);
	if (philo->data->nb_philo == 1)
		return (1);
	pthread_mutex_lock(philo->left_fork);
	locked(philo, 2);
	return (0);
}
