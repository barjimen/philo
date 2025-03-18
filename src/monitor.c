/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 20:22:59 by barjimen          #+#    #+#             */
/*   Updated: 2025/03/18 17:52:32 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

int	is_philo_dead(t_philo *philo, t_data *data)
{
	pthread_mutex_lock(&data->dead);
	if ((ft_gettime()
			- philo->last_meal) >= (unsigned long)data->args[DIE_TIME])
	{
		printf_mutex(philo, DIED);
		data->vivo = 1;
		pthread_mutex_unlock(&data->dead);
		return (1);
	}
	pthread_mutex_unlock(&data->dead);
	return (0);
}

int	full_or_dead(t_data *data)
{
	int	i;
	int	philos_full;

	philos_full = 0;
	i = data->args[PHILO_NB];
	while (i--)
	{
		pthread_mutex_lock(&data->eating);
		if (data->philos[i].args[EAT_NB] == 0)
			philos_full++;
		else if (is_philo_dead(&data->philos[i], data))
		{
			pthread_mutex_unlock(&data->eating);
			return (1);
		}
		pthread_mutex_unlock(&data->eating);
	}
	return (philos_full == data->args[PHILO_NB]);
}

void	monitor(t_data *data)
{
	while (1)
	{
		if (full_or_dead(data))
			break ;
		ft_usleep(1);
	}
}
