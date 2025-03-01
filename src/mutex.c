/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 20:56:10 by barjimen          #+#    #+#             */
/*   Updated: 2025/03/01 20:25:31 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

int	init_mutex(t_data *data)
{
	int	i;

	i = data->args[PHILO_NB];
	if (pthread_mutex_init(&data->writing, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&data->start, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&data->muelto, NULL) != 0)
		return (1);
	while (i--)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
			return (1);
	}
	return (0);
}

int	destroy_mutex(t_data *data)
{
	int	i;

	i = data->args[PHILO_NB];
	pthread_mutex_destroy(&data->writing);
	pthread_mutex_destroy(&data->start);
	pthread_mutex_destroy(&data->muelto);
	while (i--)
		pthread_mutex_destroy(&data->forks[i]);
	return (0);
}

void	init_philos(t_data *data)
{
	int	i;
	int	j;

	i = data->args[PHILO_NB];
	while (i--)
	{
		j = 5;
		while (j--)
			data->philos[i].args[j] = data->args[j];
		if (!data->args[EAT_NB])
			data->philos[i].args[EAT_NB] = 10;
		data->philos[i].index = i + 1;
		data->philos[i].start_time = ft_gettime();
		data->philos[i].last_meal = data->philos[i].start_time;
		data->philos[i].writing = &data->writing;
		data->philos[i].start = &data->start;
		data->philos[i].muelto = &data->muelto;
		data->philos[i].vivo = &data->vivo;
		data->philos[i].eating = &data->eating;
		data->philos[i].left = &data->forks[i];
		if (i == data->args[PHILO_NB] - 1)
			data->philos[i].right = &data->forks[0];
		else
			data->philos[i].right = &data->forks[i + 1];
	}
}

void	init_threads(t_data *data)
{
	int	i;

	i = data->args[PHILO_NB];
	while (i--)
	{
		if (pthread_create(&data->philos[i].thread, NULL, &routine,
				&data->philos[i]) != 0)
		{
			destroy_mutex(data);
			printf("Error al crear philos\n");
		}
	}
	monitor(data);
	i = data->args[PHILO_NB];
	while (i--)
	{
		if (pthread_join(data->philos[i].thread, NULL) != 0)
		{
			destroy_mutex(data);
			printf("Error al unir philos\n");
		}
	}
}
