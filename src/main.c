/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 22:27:37 by barjimen          #+#    #+#             */
/*   Updated: 2025/03/18 17:47:59 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

int	is_valid(char *av)
{
	while (*av)
	{
		if (!ft_isdigit(*av))
			return (0);
		av++;
	}
	return (1);
}

int	argument_manage(int ac, char **av, t_data *data)
{
	int	i;

	i = 1;
	if (ac == 5 || ac == 6)
	{
		while (av[i])
		{
			if (is_valid(av[i]))
				data->args[i - 1] = ft_atoi(av[i]);
			else
				return (0);
			i++;
		}
		i = 0;
		while (i < (ac - 1))
		{
			if (data->args[i] == 0 || data->args[PHILO_NB] > 200)
				return (0);
			i++;
		}
		if (ac == 5)
			data->args[EAT_NB] = -1;
		return (1);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;
	int		i;

	ft_bzero(&data, sizeof(t_data));
	i = 0;
	if (!argument_manage(ac, av, &data))
		return (1);
	if (data.args[EAT_NB] != -1)
		data.args[EAT_NB]++;
	if (init_mutex(&data))
	{
		printf("mutex init error\n");
		return (1);
	}
	init_philos(&data);
	init_threads(&data);
	return (0);
}
