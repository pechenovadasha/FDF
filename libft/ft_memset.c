/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croxane <croxane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 10:08:56 by croxane           #+#    #+#             */
/*   Updated: 2019/04/16 14:54:20 by croxane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memset(void *b, int c, size_t n)
{
	unsigned char	*src;

	src = (unsigned char *)b;
	while (n)
	{
		*src = c;
		src++;
		n--;
	}
	return (b);
}
