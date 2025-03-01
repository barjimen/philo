/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 00:51:14 by barjimen          #+#    #+#             */
/*   Updated: 2025/03/01 20:14:23 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

void	philo_sleep(t_philo *philo)
{
	printf_mutex(philo, SLEEPING);
	ft_usleep(philo->args[SLEEP_TIME]);
}

void	eat(t_philo *philo)
{
	pthread_mutex_lock(philo->left);
	printf_mutex(philo, TAKE_FORK);
	if (philo->args[PHILO_NB] == 1)
		return ((void)ft_usleep(philo->args[DIE_TIME]),
			(void)pthread_mutex_unlock(philo->left));
	pthread_mutex_lock(philo->right);
	printf_mutex(philo, TAKE_FORK);
	pthread_mutex_lock(philo->eating);
	philo->last_meal = ft_gettime();
	philo->args[EAT_NB]--;
	pthread_mutex_unlock(philo->eating);
	printf_mutex(philo, EATING);
	ft_usleep(philo->args[EAT_TIME]);
	pthread_mutex_lock(philo->eating);
	if (philo->args[EAT_NB] == 0)
		printf_mutex(philo, FULL);
	pthread_mutex_unlock(philo->eating);
	pthread_mutex_unlock(philo->left);
	pthread_mutex_unlock(philo->right);
}

void	think(t_philo *philo)
{
	printf_mutex(philo, THINKING);
}

int	alive_or_hungry(t_philo *philo)
{
	pthread_mutex_lock(philo->muelto);
	if (*philo->vivo == 1)
		return (pthread_mutex_unlock(philo->muelto), 0);
	pthread_mutex_unlock(philo->muelto);
	pthread_mutex_lock(philo->eating);
	if (philo->args[EAT_NB] == 0)
		return (pthread_mutex_unlock(philo->eating), 0);
	pthread_mutex_unlock(philo->eating);
	return (1);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (alive_or_hungry(philo))
	{
		eat(philo);
		if (alive_or_hungry(philo))
		{
			philo_sleep(philo);
			think(philo);
		}
	}
	return (NULL);
}

