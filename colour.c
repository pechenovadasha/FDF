/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croxane <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 12:38:09 by croxane           #+#    #+#             */
/*   Updated: 2019/08/19 12:38:11 by croxane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_isblank(char c)
{
	if (c <= 32)
		return (1);
	return (0);
}

int			isvalid(char c, int base)
{
	int		i;
	char	digits[17];
	char	digits2[17];

	i = -1;
	while (++i < 10)
	{
		digits[i] = 48 + i;
		digits2[i] = 48 + i;
	}
	while (++i < 17)
	{
		digits[i] = 88 + i;
		digits2[i] = 56 + i;
	}
	while (base--)
		if (digits[base] == c || digits2[base] == c)
			return (1);
	return (0);
}

int			value_of(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	else if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	else if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	return (0);
}

int			ft_atoi_base(const char *str, int str_base)
{
	int		result;
	int		sign;

	result = 0;
	while ((ft_isblank(*str)))
		str++;
	sign = (*str == '-') ? -1 : 1;
	(*str == '-' || *str == '+') ? ++str : 0;
	while (isvalid(*str, str_base))
		result = result * str_base + value_of(*str++);
	return (result * sign);
}
