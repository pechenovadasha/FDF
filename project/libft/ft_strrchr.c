/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croxane <croxane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 12:05:48 by croxane           #+#    #+#             */
/*   Updated: 2019/04/14 11:56:58 by croxane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strrchr(const char *str, int c)
{
	int				i;
	unsigned char	k;
	char			*s;

	i = 0;
	while (str[i])
		i++;
	k = (unsigned char)c;
	s = (char *)str;
	while (s[i] != k)
	{
		if (i < 0)
			return (0);
		i--;
	}
	return (&s[i]);
}
