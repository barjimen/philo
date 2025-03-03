/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 20:22:59 by barjimen          #+#    #+#             */
/*   Updated: 2025/03/03 18:55:40 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

int	full_or_dead(t_data *data)
{
	int	i;
	int	philos_full;

	philos_full = 0;
	i = data->args[PHILO_NB];
	while (i--)
	{
		pthread_mutex_lock(&data->eating);
		if (data->philos[i].args[EAT_NB] != 0)
		{
			pthread_mutex_lock(&data->muelto);
			if ((ft_gettime() - data->philos[i].last_meal)
				>= (unsigned long)data->args[DIE_TIME])
			{
				printf_mutex(&data->philos[i], DIED);
				data->vivo = 1;
				return (pthread_mutex_unlock(&data->muelto),
					pthread_mutex_unlock(&data->eating), 1);
			}
			pthread_mutex_unlock(&data->muelto);
		}
		else
			philos_full++;
		pthread_mutex_unlock(&data->eating);
	}
	if (philos_full == data->args[PHILO_NB])
		return (1);
	return (0);
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
