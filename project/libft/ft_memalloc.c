/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croxane <croxane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 17:47:37 by croxane           #+#    #+#             */
/*   Updated: 2019/04/12 16:25:38 by croxane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memalloc(size_t size)
{
	void	*str;

	if (size + 1 == 0)
		return (NULL);
	if (!(str = (void*)malloc(size)))
		return (0);
	ft_bzero(str, size);
	return (str);
}
