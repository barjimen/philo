/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 22:28:28 by barjimen          #+#    #+#             */
/*   Updated: 2025/02/12 19:45:26 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include "../lib/Libft/libft.h"
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef enum e_args
{
    PHILO_NB,
    DIE_TIME,
    EAT_TIME,
    SLEEP_TIME,
    EAT_NB
}  t_args;

typedef struct s_data
{
    int args[5];
}	t_data;

#endif 