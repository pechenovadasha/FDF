/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croxane <croxane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 13:10:29 by croxane           #+#    #+#             */
/*   Updated: 2019/04/14 12:33:58 by croxane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	int		k;
	char	*str;

	i = 0;
	j = 0;
	if (!s)
		return (0);
	while (s[i] == '\t' || s[i] == '\n' || s[i] == ' ')
		i++;
	k = i;
	while (s[i + 1])
		i++;
	while (s[i] == '\t' || s[i] == '\n' || s[i] == ' ')
		i--;
	if (!(str = (char *)malloc(i - k + 2)))
		return (NULL);
	while (k <= i)
		str[j++] = s[k++];
	str[j] = '\0';
	return (str);
}
