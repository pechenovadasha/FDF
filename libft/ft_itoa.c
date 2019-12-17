/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croxane <croxane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 10:35:14 by croxane           #+#    #+#             */
/*   Updated: 2019/04/17 13:41:45 by croxane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n)
{
	int		i;
	int		size;
	char	*str;

	i = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	size = ft_nbrlen(n);
	str = (char*)malloc(sizeof(char) * (size + 1));
	if (str == 0)
		return (0);
	str[size] = 0;
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
		i++;
	}
	while (i < size--)
	{
		str[size] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}
