/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croxane <croxane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 11:37:21 by croxane           #+#    #+#             */
/*   Updated: 2019/04/14 11:43:31 by croxane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	char			*d;
	char			*s;
	char			k;

	d = (char*)dest;
	s = (char*)src;
	k = (char)c;
	i = 0;
	while (n > i)
	{
		d[i] = s[i];
		if (s[i] == k)
			return (&d[i + 1]);
		i++;
	}
	return (0);
}
