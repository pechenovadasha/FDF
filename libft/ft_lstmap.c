/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croxane <croxane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 16:27:51 by croxane           #+#    #+#             */
/*   Updated: 2019/04/17 13:34:34 by croxane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *res;
	t_list *tmp;
	t_list *s;

	if (!lst || !f)
		return (0);
	s = f(lst);
	if ((res = ft_lstnew(s->content, s->content_size)))
	{
		tmp = res;
		lst = lst->next;
		while (lst != NULL)
		{
			s = (*f)(lst);
			if (!(tmp->next = ft_lstnew(s->content, s->content_size)))
				return (NULL);
			tmp = tmp->next;
			lst = lst->next;
		}
	}
	return (res);
}
