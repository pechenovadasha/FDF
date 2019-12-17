/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croxane <croxane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 11:40:36 by croxane           #+#    #+#             */
/*   Updated: 2019/04/16 14:58:44 by croxane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned char *str;
	unsigned char *src;

	str = (unsigned char *)s1;
	src = (unsigned char *)s2;
	while (*str == *src && *str != '\0' && *src != '\0')
	{
		str++;
		src++;
	}
	return (*str - *src);
}
