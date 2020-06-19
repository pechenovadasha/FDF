/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.C                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croxane <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 16:58:26 by croxane           #+#    #+#             */
/*   Updated: 2019/09/09 17:25:52 by croxane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			ft_menu(struct s_struct *data)
{
	mlx_string_put(data->mlx, data->win, 0, 830, 0xAAAAAA,
			"Push 'A' to rotate on axis Y");
	mlx_string_put(data->mlx, data->win, 0, 860, 0xAAAAAA,
			"Push '>' to rotate on axis X");
	mlx_string_put(data->mlx, data->win, 0, 890, 0xAAAAAA,
			"Push arrow keys to move");
	mlx_string_put(data->mlx, data->win, 0, 800, 0xAAAAAA,
			"Push space to Reset");
	mlx_string_put(data->mlx, data->win, 0, 920, 0xAAAAAA,
			"Push 'i' to change  projection");
}

int				ft_check_map(int fd, struct s_struct *data)
{
	char		*str;
	int			i;

	data->alfa = 0;
	data->length = 0;
	i = 0;
	while (get_next_line(fd, &str))
	{
		if (str[i] == '\0' || str[0] == '/')
			return (1);
		while (str[i] != '\0')
		{
			if ((str[i] == ' ' || str[i] == '\t') && (i == 0))
				return (1);
			if (str[i] >= '0' && str[i] <= '9')
				data->count++;
			i++;
		}
		if ((str[i] == '\0' && !str[i - 1]) || !(data->count))
			return (1);
		i = 0;
		free(str);
	}
	return (0);
}

void			ft_hurt(t_struct *data, t_coor *coor, int fd1)
{
	int			i;

	i = 0;
	ft_coor(coor);
	ft_filling(fd1, data, coor);
	ft_zoom(data);
	ft_move(data);
	while (i < data->count)
	{
		data->volume[i].x = data->pixel[i].x;
		data->volume[i].y = data->pixel[i].y;
		data->volume[i].z = data->pixel[i].z;
		data->def[i].x = data->pixel[i].x;
		data->def[i].y = data->pixel[i].y;
		data->def[i].z = data->pixel[i].z;
		i++;
	}
	ft_print(data);
}

void			initialize(t_struct *data)
{
	data->push = 1;
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "FDF");
	data->image = mlx_new_image(data->mlx, WIDTH, HEIGHT - 200);
	data->art = (int*)mlx_get_data_addr(data->image, &data->endian,
			&data->line_s, &data->bbp);
	data->count--;
	if (!(data->pixel = malloc(sizeof(t_pixel) * data->count)) ||
	!(data->volume = malloc(sizeof(t_volume) * data->count)) ||
	!(data->def = malloc(sizeof(t_default) * data->count)))
	{
		write(1, "malloc nerror\n", 14);
		exit(0);
	}
}

int				main(int argc, char **argv)
{
	int			fd;
	int			fd1;
	t_struct	data;
	t_coor		coor;

	if (argc < 2)
	{
		write(2, "usage: ./fdf [file_map]\n", 25);
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	fd1 = open(argv[1], O_RDONLY);
	if ((fd <= 0) || (fd1 <= 0) || ((ft_check_map(fd, &data) == 1))
	|| (data.count <= 0))
		ft_print_mistake();
	initialize(&data);
	ft_hurt(&data, &coor, fd1);
	mlx_hook(data.win, 4, 0, key_mouse, &data);
	mlx_hook(data.win, 2, 0, key_hook, &data);
	mlx_loop(data.mlx);
	close(fd);
	close(fd1);
	return (0);
}
