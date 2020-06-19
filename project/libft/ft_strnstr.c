/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croxane <croxane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 12:58:19 by croxane           #+#    #+#             */
/*   Updated: 2019/04/17 12:11:41 by croxane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *hayst, const char *need, size_t l)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	if (!need[j])
		return ((char*)hayst);
	while (hayst[i] && (i < l))
	{
		while ((l > (i + j)) && hayst[i + j] == need[j] && need[j])
			j++;
		if (!need[j])
			return ((char*)&hayst[i]);
		j = 0;
		i++;
	}
	return (0);
}
