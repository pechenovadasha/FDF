/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croxane <croxane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 14:34:27 by croxane           #+#    #+#             */
/*   Updated: 2019/04/14 11:54:02 by croxane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strchr(const char *str, int n)
{
	char	*s;
	char	m;
	int		i;

	i = 0;
	m = (char)n;
	s = (char*)str;
	while (s[i] != m)
	{
		if (!s[i])
			return (0);
		i++;
	}
	return (&s[i]);
}
