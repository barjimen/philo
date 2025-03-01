/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 00:51:14 by barjimen          #+#    #+#             */
/*   Updated: 2025/02/23 01:31:40 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

void sleep(t_philo *philo)
{
    printf_mutex(philo, SLEEPING);
    ft_usleep(philo->args[SLEEP_TIME]);
}

void eat(t_philo *philo)
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
    philo->args[EAT_NB] -= 1;
    pthread_mutex_unlock(philo->eating);
    printf_mutex(philo, EATING);
    ft_usleep(philo->args[EAT_TIME]);
    if (philo->args[EAT_NB] == 0)
        printf_mutex(philo, FULL);
    pthread_mutex_unlock(philo->left);
    pthread_mutex_unlock(philo->right);
}

void think(t_philo *philo)
{
    printf_mutex(philo, THINKING);

}

void *routine(void *arg)
{
    t_philo *philo;
    
    philo = (t_philo *)arg;
    while (condition)
    {
        /* code */
    }
    
    
}

