/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croxane <croxane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 09:02:09 by croxane           #+#    #+#             */
/*   Updated: 2019/04/14 10:48:45 by croxane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_s(char *str, char c)
{
	int			i;
	int			k;

	i = 0;
	k = 0;
	if (str[i] == c)
	{
		while (str[i] == c)
			i++;
	}
	if (!str[i])
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == c && str[i - 1] != c)
			k++;
		i++;
	}
	if (str[i] == '\0' && str[i - 1] != c)
		k++;
	return (k);
}
