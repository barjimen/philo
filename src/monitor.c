/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 20:22:59 by barjimen          #+#    #+#             */
/*   Updated: 2025/03/15 19:59:29 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

int	full_or_dead(t_data *data)
{
	int	i = data->args[PHILO_NB];
	int	philos_full = 0;

	while (i--)
	{
		pthread_mutex_lock(&data->eating);
		if (data->philos[i].args[EAT_NB] == 0)
			philos_full++;
		else
		{
			pthread_mutex_lock(&data->muelto);
			if ((ft_gettime() - data->philos[i].last_meal)
				>= (unsigned long)data->args[DIE_TIME])
			{
				printf_mutex(&data->philos[i], DIED);
				data->vivo = 1;
				pthread_mutex_unlock(&data->muelto);
				pthread_mutex_unlock(&data->eating);
				return (1);
			}
			pthread_mutex_unlock(&data->muelto);
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
