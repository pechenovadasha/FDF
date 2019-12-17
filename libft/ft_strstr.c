/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croxane <croxane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 10:11:33 by croxane           #+#    #+#             */
/*   Updated: 2019/04/16 15:10:49 by croxane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		index;
	int		r;

	i = 0;
	if (!(needle[0]))
		return ((char*)&haystack[i]);
	while (haystack[i] != '\0')
	{
		index = 0;
		if (haystack[i] == (char)(needle[index]))
		{
			r = i;
			while (haystack[i] == (char)(needle[index]))
			{
				if ((char)(needle[index + 1]) == '\0')
					return ((char *)&haystack[r]);
				i++;
				index++;
			}
			i = r;
		}
		i++;
	}
	return (0);
}
