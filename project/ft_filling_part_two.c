/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filling_part_two.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscottie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 18:49:36 by sscottie          #+#    #+#             */
/*   Updated: 2019/09/06 16:07:18 by croxane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_move(struct s_struct *data)
{
	int		i;
	int 	center_x;
	int 	center_y;

	i = -1;
	while (++i < data->count)
	{
		data->pixel[i].x *= (int)data->zoom;
		data->pixel[i].y *= (int)data->zoom;
		data->pixel[i].z *= (int)data->zoom;
	}
	i = -1;
	center_x = WIDTH/2 - data->length*(int)data->zoom/2;
	center_y = (HEIGHT-HEIGHT_MENU/2)/2 - (data->count/data->length)*(int)data->zoom/2;
	//printf("center = %i\n", center);
	while (++i < data->count)
	{
		data->pixel[i].x += center_x;
		data->pixel[i].y += center_y;
	}
}

void		ft_print_mistake(void)
{
	write(1, "This map isn't valid. Fix the map!!!\n", 37);
	exit(0);
}

void		ft_check_colour_two(struct s_struct *data, int i)
{
	if (!data->pixel[i].colour)
	{
		if (data->pixel[i].z == 0)
			data->pixel[i].colour = 0x576bfc;
		else if (data->pixel[i].z < 0)
			data->pixel[i].colour = 0x23efff * abs(data->pixel[i].z - 1);
		else
			data->pixel[i].colour = 0xcdff00 * abs(data->pixel[i].z + 1);
	}
}

void		ft_coor(t_coor *coor)
{
	coor->x = 0;
	coor->y = 0;
	coor->i = 0;
}
