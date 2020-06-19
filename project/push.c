/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croxane <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 16:29:27 by croxane           #+#    #+#             */
/*   Updated: 2019/08/19 16:29:31 by croxane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_push_left(t_struct *data)
{
	int i;

	i = -1;
	while (++i < data->count)
		data->pixel[i].x -= 100 / data->zoom;
	ft_print(data);
	foo(data);
}

void	ft_push_right(t_struct *data)
{
	int i;

	i = -1;
	while (++i < data->count)
		data->pixel[i].x += 100 / data->zoom;
	ft_print(data);
	foo(data);
}

void	ft_push_up(t_struct *data)
{
	int i;

	i = -1;
	while (++i < data->count)
		data->pixel[i].y += 100 / data->zoom;
	ft_print(data);
	foo(data);
}

void	ft_push_down(t_struct *data)
{
	int i;

	i = -1;
	while (++i < data->count)
		data->pixel[i].y -= 100 / data->zoom;
	ft_print(data);
	foo(data);
}
