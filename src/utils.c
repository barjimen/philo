/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 00:55:34 by barjimen          #+#    #+#             */
/*   Updated: 2025/03/01 16:09:52 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

void	printf_mutex(t_philo *philo, char *msg)
{
	pthread_mutex_lock(philo->writing);
	printf(msg, ft_gettime() - philo->start_time, philo->index);
	pthread_mutex_unlock(philo->writing);
}
