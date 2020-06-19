/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croxane <croxane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 16:22:04 by croxane           #+#    #+#             */
/*   Updated: 2019/04/17 12:11:41 by croxane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_atoi(const char *str)
{
	long long	n;
	int			prefix;

	n = 0;
	prefix = 1;
	while ((*str >= 0 && *str <= 13) || (*str == ' '))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			prefix = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		if (n != ((n * 10 + (*str - '0')) / 10) && prefix == -1)
			return (0);
		else if (n != ((n * 10 + (*str - '0')) / 10))
			return (-1);
		n = n * 10 + *str - '0';
		str++;
	}
	n = n * prefix;
	return ((int)n);
}
