/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filling.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croxane <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 12:34:21 by croxane           #+#    #+#             */
/*   Updated: 2019/08/19 12:34:23 by croxane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_check_colour(const char *str)
{
	int		i;
	int		j;
	char	src[7];

	i = 0;
	j = 0;
	while (str[i] != 'x' && str[i] != 'X' && str[i] != '\0')
		i++;
	if (str[i] == '\0')
		return (0);
	i++;
	while (str[i])
	{
		src[j] = str[i];
		i++;
		j++;
	}
	src[j] = '\0';
	return (ft_atoi_base((const char*)src, 16));
}

void		ft_zoom(struct s_struct *data)
{
	int		i;
	int		j;

	data->zoom = 1;
	i = (WIDTH - 1) / data->length; // ширину экрана / ширину карты
	j = (HEIGHT - HEIGHT_MENU) / (data->count / data->length); // высоту экрана / высоту карты
	while ((data->zoom * (float)data->length < WIDTH/2)
	&& (data->zoom * (float)(data->count / data->length) < (HEIGHT - HEIGHT_MENU)/2)) // ??????????
		data->zoom += 1;
}

void		ft_coodinary(struct s_struct *data, t_coor *coor, char *split)
{
	int		i;

	i = (int)coor->i;
	if (split[0] != '0' && !ft_atoi(split))
		ft_print_mistake();
	data->pixel[i].colour = (ft_check_colour(split)); // присвоение цвета относительно глубины оси Оz
	data->pixel[i].z = ft_atoi((const char *)split);
	ft_check_colour_two(data, i);
	data->pixel[i].y = coor->y;
	data->pixel[i].x = coor->x;// координаты пикселя
}

void		ft_filling(int fd, t_struct *data, t_coor *coor)
{
	// запись в структуру координат из файла
	char	*str;
	char	**split;
	void	*to_free;

	while (get_next_line(fd, &str))
	{
		coor->x = 0;
		if (!*(split = ft_strsplit((const char *)str, ' ')))
			ft_print_mistake();
		to_free = split;
		while (*split)
		{
			ft_coodinary(data, coor, *split);
			coor->x++;
			coor->i++; // номер элемента масива струтур ?????
			free(*split);
			*split = NULL;
			split++;
			data->length = coor->x; // ширина поля
		}
		free(str);
		free(to_free);
		coor->y++;
	}
}
