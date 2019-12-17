/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croxane <croxane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 13:37:15 by croxane           #+#    #+#             */
/*   Updated: 2019/04/16 14:53:21 by croxane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	*src;

	i = 0;
	str = (unsigned char *)s1;
	src = (unsigned char *)s2;
	while ((i < n) && str[i] == src[i])
		i++;
	if (i == n)
		return (0);
	return (str[i] - src[i]);
}
