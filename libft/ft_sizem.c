/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sizem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croxane <croxane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 09:02:19 by croxane           #+#    #+#             */
/*   Updated: 2019/04/14 11:49:35 by croxane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_sizem(char *str, char c)
{
	int			m;
	int			i;

	i = 0;
	m = 0;
	while (str[i] == c)
		i++;
	while (str[i] != '\0')
	{
		if (str[i] != c)
			m++;
		if (str[i] == c && str[i - 1] != c)
			return (m);
		i++;
	}
	return (m);
}
