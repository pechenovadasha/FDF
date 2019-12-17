/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croxane <croxane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 14:39:05 by croxane           #+#    #+#             */
/*   Updated: 2019/04/17 13:03:09 by croxane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;
	void	*str;

	if (!(new = (t_list*)malloc(sizeof(t_list))))
		return (0);
	if (!content)
	{
		new->content = NULL;
		new->content_size = 0;
	}
	else
	{
		if (!(str = (void*)malloc(content_size)))
			return (NULL);
		ft_memcpy(str, content, content_size);
		new->content = str;
		new->content_size = content_size;
	}
	new->next = NULL;
	return (new);
}
