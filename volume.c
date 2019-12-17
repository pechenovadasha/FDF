/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   volume.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croxane <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 17:07:49 by croxane           #+#    #+#             */
/*   Updated: 2019/08/19 17:07:51 by croxane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		foo(t_struct *data)
{
	int		i;

	i = 0;
	while (i < data->count)
	{
		data->volume[i].x = data->pixel[i].x;
		data->volume[i].y = data->pixel[i].y;
		data->volume[i].z = data->pixel[i].z;
		i++;
	}
}

void		ft_volume_point(struct s_struct *data)
{
	int		i;
	int		k;

	i = -1;
	k = -1;
	data->alfa += M_PI / 360;
	while (++i < data->count)
	{
		data->pixel[i].y = data->volume[i].y * cos(data->alfa)
				+ data->volume[i].z * sin(data->alfa);
		data->pixel[i].z = k * (data->volume[i].y * sin(data->alfa))
				+ data->volume[i].z * cos(data->alfa);
		data->pixel[i].x = data->volume[i].x;
	}
	foo(data);
}

void		ft_volume_point_y(struct s_struct *data)
{
	int		i;
	int		k;

	i = -1;
	k = -1;
	data->alfa += M_PI / 360;
	while (++i < data->count)
	{
		data->pixel[i].x = data->volume[i].x * cos(data->alfa)
				+ data->volume[i].z * sin(data->alfa);
		data->pixel[i].z = k * data->volume[i].x * sin(data->alfa)
				+ data->volume[i].z * cos(data->alfa);
		data->pixel[i].y = data->volume[i].y;
	}
	foo(data);
}
