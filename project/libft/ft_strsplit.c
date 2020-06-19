/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croxane <croxane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 10:34:30 by croxane           #+#    #+#             */
/*   Updated: 2019/04/17 12:11:41 by croxane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static char		**ft_free_all(char **s, int j)
{
	while (j)
	{
		j--;
		ft_memdel((void *)s);
	}
	free(s);
	s = NULL;
	return (0);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**s1;
	int			i;
	int			j;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	if (!(s1 = (char **)malloc(sizeof(char*) * ((ft_s((char *)(s), c)) + 1))))
		return (0);
	while (j < (ft_s((char *)(s), c)))
	{
		if (s[i] != c)
		{
			if (!(s1[j] = ft_memory((char*)(&s[i]), ft_sizem((char*)&s[i], c))))
				return (ft_free_all(&s1[j], j));
			j++;
			i += ft_sizem((char*)&s[i], c);
		}
		i++;
	}
	s1[j] = NULL;
	return (s1);
}
