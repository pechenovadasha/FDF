/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croxane <croxane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 09:00:07 by croxane           #+#    #+#             */
/*   Updated: 2019/04/14 11:47:03 by croxane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_memory(char *s, int m)
{
	char		*str;
	int			i;

	i = 0;
	if (!(str = (char*)malloc(sizeof(char) * (m + 1))))
		return (0);
	while (m > i)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
