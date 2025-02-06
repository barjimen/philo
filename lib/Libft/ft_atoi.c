/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 12:32:34 by barjimen          #+#    #+#             */
/*   Updated: 2024/10/19 21:56:16 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
