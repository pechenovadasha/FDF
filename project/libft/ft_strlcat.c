/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croxane <croxane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 15:19:58 by croxane           #+#    #+#             */
/*   Updated: 2019/04/16 15:01:44 by croxane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t l;
	size_t l2;

	l = 0;
	l2 = 0;
	while (*dst)
	{
		l++;
		dst++;
	}
	while (src[l2])
		++l2;
	if (size <= l)
		l2 += size;
	else
		l2 += l;
	while (*src && l + 1 < size)
	{
		*dst++ = *src++;
		l++;
	}
	*dst = '\0';
	return (l2);
}
