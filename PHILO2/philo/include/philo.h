/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiusep <engiusep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 12:55:37 by engiusep          #+#    #+#             */
/*   Updated: 2025/07/17 16:25:04 by engiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_philo
{
	int				id;
	int				meals_count;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	long			last_meal_time;

	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	int				left;
	int				right;
	struct s_data	*data;
}					t_philo;

typedef struct s_data
{
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_reach_meal;
	int				someone_die;
	int				done;
	int				all_is_done;

	size_t			start_time;

	pthread_t		thread_monitor;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	var_mutex;
	pthread_mutex_t	*forks;
	t_philo			*philos;
}					t_data;

int					ft_atoi(const char *str);
long				get_time_ms(void);
void				*routine_philo(void *arg);
void				*routine_monitor(void *arg);
int					print_mutex(t_philo *philo, char *str);
int					take_fork(t_philo *philo);
void				check_done(t_data *data, int i);
void				unlocked(t_philo *philo);
void				destroy_mutex(t_data *data);
void				free_all(t_data *data, t_philo *philos);
#endif
