/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 22:28:28 by barjimen          #+#    #+#             */
/*   Updated: 2025/03/03 18:54:42 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include "../lib/Libft/libft.h"
# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

typedef enum e_args
{
	PHILO_NB,
	DIE_TIME,
	EAT_TIME,
	SLEEP_TIME,
	EAT_NB
}					t_args;

typedef struct s_philo
{
	pthread_t		thread;
	pthread_mutex_t	*right;
	pthread_mutex_t	*left;
	pthread_mutex_t	*writing;
	pthread_mutex_t	*muelto;
	int				*vivo;
	pthread_mutex_t	*start;
	pthread_mutex_t	*eating;
	int				index;
	int				args[5];
	size_t			last_meal;
	size_t			start_time;
}					t_philo;

typedef struct s_data
{
	int				args[5];
	int				vivo;
	t_philo			philos[200];
	pthread_mutex_t	forks[200];

	// Para limitar los printf ya que tienen
	// que esperar para ir escribiendo cada evento
	pthread_mutex_t	writing;
	pthread_mutex_t	start;
	pthread_mutex_t	muelto;
	pthread_mutex_t	eating;

}					t_data;

int					ft_usleep(size_t milisec);
size_t				ft_gettime(void);
int					ft_atoi(const char *str);
int					ft_isdigit(int c);
void				ft_bzero(void *s, size_t n);
int					init_mutex(t_data *data);
void				init_threads(t_data *data);
int					destroy_mutex(t_data *data);
void				init_philos(t_data *data);
void				printf_mutex(t_philo *philo, char *msg);
void				*routine(void *arg);
void				monitor(t_data *data);

# define EATING "\033[0;32m[%d] %d is eating\n\033[m"
# define SLEEPING "[%d] %d is sleeping\n"
# define THINKING "[%d] %d is thinking\n"
# define TAKE_FORK "[%d] %d has taken a fork\n"
# define DIED "\033[0;31m[%d] %d died\n\033[m"
# define FULL "\033[0;32m[%d] %d is full\n\033[m"

#endif