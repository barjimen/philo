/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 20:30:57 by barjimen          #+#    #+#             */
/*   Updated: 2025/02/22 20:51:33 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
		((unsigned char *) s)[i++] = '\0';
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int			x;
	long int	nb;
	int			sym;

	x = 0;
	nb = 0;
	sym = 1;
	while ((str[x] >= 9 && str[x] <= 13) || (str[x] == 32))
		x++;
	if (str[x] == '-' || str[x] == '+')
	{
		if (str[x] == '-')
			sym *= -1;
		x++;
	}
	while (str[x] >= '0' && str[x] <= '9')
	{
		nb = (str[x++] - '0') + (nb * 10);
		if ((nb > 2147483647 && sym == 1) || (nb > 2147483648 && sym == -1))
			return (EXIT_SUCCESS);
	}
	nb *= sym;
	return (nb);
}

size_t ft_gettime(void)
{
    struct timeval time;
    if(gettimeofday(&time,NULL) == -1)
    {
        printf("Error en gettime\n");
        exit(1);
    }
    return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

int ft_usleep(size_t milisec)
{
    size_t start;

    start = ft_gettime();
    while ((ft_gettime() - start) < milisec)
    {
        usleep(500);
    }
    return (0);
}
