/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croxane <croxane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 12:30:54 by croxane           #+#    #+#             */
/*   Updated: 2019/04/16 15:14:52 by croxane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char *str;
	unsigned char *src;

	str = (unsigned char *)s1;
	src = (unsigned char *)s2;
	if (!n)
		return (0);
	n--;
	while (*str == *src && *str != '\0' && *src != '\0' && 0 < n)
	{
		str++;
		src++;
		n--;
	}
	return (*str - *src);
}
