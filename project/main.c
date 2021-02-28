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
static int flag = 0;

void			ft_menu(struct s_struct *data)
{
	mlx_string_put(data->mlx, data->win, 0, HEIGHT - HEIGHT_MENU/3, 0xAAAAAA,
			"Push 'A' to rotate on axis Y");
	mlx_string_put(data->mlx, data->win, 0, HEIGHT - HEIGHT_MENU/2, 0xAAAAAA,
			"Push '>' to rotate on axis X");
	mlx_string_put(data->mlx, data->win, 0, HEIGHT - 2*HEIGHT_MENU/3, 0xAAAAAA,
			"Push arrow keys to move");
	mlx_string_put(data->mlx, data->win, 0, HEIGHT - 5*HEIGHT_MENU/6, 0xAAAAAA,
			"Push space to Reset");
	mlx_string_put(data->mlx, data->win, 0, HEIGHT - HEIGHT_MENU, 0xAAAAAA,
			"Push 'i' to change  projection (isometric view)");
}

int				ft_check_map(int fd, struct s_struct *data)
{
	char		*str;
	int			i;

	data->alfa = 0;
	data->length = 0;
	data->count = 0;
	i = 0;
	while (get_next_line(fd, &str))
	{
		if (str[i] == '\0' || str[0] == '/')
			return (1);
		while (str[i] != '\0')
		{
			if ((str[i] == ' ' || str[i] == '\t') && (i == 0))
				return (1); // пропуск отступов в начале карты
			if (str[i] >= '0' && str[i] <= '9' && (str[i + 1] != 'x' && str[i + 1] != 'X'))
				data->count++; // подсчет колличества цифр в карте
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
	ft_coor(coor); //обнуление x, y, z
	ft_filling(fd1, data, coor);
	ft_zoom(data); //нахождение зума, судя по всему неправильно
	ft_move(data); //cдвиг на зум координат
	while (i < data->count)
	{
		data->volume[i].x = data->pixel[i].x;
		data->volume[i].y = data->pixel[i].y;
		data->volume[i].z = data->pixel[i].z;
		data->def[i].x = data->pixel[i].x;
		data->def[i].y = data->pixel[i].y; // в data->def хранятся начальные координаты изображения
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
 int key(int i, t_mlx *data)
 {
	int j = 0;
	char str[1000];
	switch (i) {
		case 48:
			strcat(str, "1");
			mlx_string_put(data->mlx, data->win, j, 25, 0xAAAAAA,"1");
			mlx_put_image_to_window(data->mlx, data->win, data->image, 0, 0);
			j++;
			break;
		case 49:
			strcat(str, "2");
			mlx_string_put(data->mlx, data->win, j, 25, 0xAAAAAA,"2");
			j++;
			break;
		case 50:
			strcat(str, "3");
			mlx_string_put(data->mlx, data->win, j, 25, 0xAAAAAA,"3");
			j++;
			break;
		case 51:
			strcat(str, "4");
			mlx_string_put(data->mlx, data->win, j, 25, 0xAAAAAA,"4");
			j++;
			break;
		case 52:
			strcat(str, "5");
			mlx_string_put(data->mlx, data->win, j, 25, 0xAAAAAA,"5");
			j++;
			break;
		case 53:
			strcat(str, "6");
			mlx_string_put(data->mlx, data->win, j, 25, 0xAAAAAA,"6");
			j++;
			break;
		case 54:
			strcat(str, "7");
			mlx_string_put(data->mlx, data->win, j, 25, 0xAAAAAA,"7");
			j++;
			break;
		case 56:
			strcat(str, "8");
			mlx_string_put(data->mlx, data->win, j, 25, 0xAAAAAA,"8");
			j++;
			break;
		case 57:
			strcat(str, "9");
			mlx_string_put(data->mlx, data->win, j, 25, 0xAAAAAA,"9");
			j++;
			break;
		case 189:
			strcat(str, "_");
			mlx_string_put(data->mlx, data->win, j, 25, 0xAAAAAA,"_");
			j++;
			break;
		case 191:
			strcat(str, "/");
			mlx_string_put(data->mlx, data->win, j, 25, 0xAAAAAA,"/");
			j++;
			break;
		case 190:
			strcat(str, ".");
			mlx_string_put(data->mlx, data->win, j, 25, 0xAAAAAA,".");
			j++;
			break;
		case 65:
			strcat(str, "a");
			mlx_string_put(data->mlx, data->win, j, 25, 0xAAAAAA,"a");
			j++;
			break;
		case 66:
			strcat(str, "b");
			mlx_string_put(data->mlx, data->win, j, 25, 0xAAAAAA,"b");
			j++;
			break;
		case 67:
			strcat(str, "c");
			mlx_string_put(data->mlx, data->win, j, 25, 0xAAAAAA,"c");
			j++;
			break;
		case 68:
			strcat(str, "d");
			mlx_string_put(data->mlx, data->win, j, 25, 0xAAAAAA,"d");
			j++;
			break;
		case 69:
			strcat(str, "e");
			mlx_string_put(data->mlx, data->win, j, 25, 0xAAAAAA,"e");
			j++;
			break;
		case 70:
			strcat(str, "f");
			mlx_string_put(data->mlx, data->win, j, 25, 0xAAAAAA,"f");
			j++;
			break;
		case 71:
			strcat(str, "g");
			mlx_string_put(data->mlx, data->win, j, 25, 0xAAAAAA,"g");
			j++;
			break;
		case 72:
			strcat(str, "h");
			mlx_string_put(data->mlx, data->win, j, 25, 0xAAAAAA,"h");
			j++;
			break;
		case 73:
			strcat(str, "i");
			mlx_string_put(data->mlx, data->win, j, 25, 0xAAAAAA,"i");
			j++;
			break;
		case 74:
			strcat(str, "j");
			mlx_string_put(data->mlx, data->win, j, 25, 0xAAAAAA,"j");
			j++;
			break;
		case 75:
			strcat(str, "k");
			mlx_string_put(data->mlx, data->win, j, 25, 0xAAAAAA,"k");
			j++;
			break;
		case 76:
			strcat(str, "l");
			mlx_string_put(data->mlx, data->win, j, 25, 0xAAAAAA,"l");
			j++;
			break;
		case 77:
			strcat(str, "m");
			mlx_string_put(data->mlx, data->win, j, 25, 0xAAAAAA,"m");
			j++;
			break;
		case 78:
			strcat(str, "n");
			mlx_string_put(data->mlx, data->win, j, 25, 0xAAAAAA,"n");
			j++;
			break;
		case 79:
			strcat(str, "o");
			mlx_string_put(data->mlx, data->win, j, 25, 0xAAAAAA,"o");
			j++;
			break;
		case 80:
			strcat(str, "p");
			mlx_string_put(data->mlx, data->win, j, 25, 0xAAAAAA,"p");
			j++;
			break;
		case 81:
			strcat(str, "q");
			mlx_string_put(data->mlx, data->win, j, 25, 0xAAAAAA,"q");
			j++;
			break;
		case 82:
			strcat(str, "r");
			mlx_string_put(data->mlx, data->win, j, 25, 0xAAAAAA,"r");
			j++;
			break;
		case 83:
			strcat(str, "s");
			mlx_string_put(data->mlx, data->win, j, 25, 0xAAAAAA,"s");
			j++;
			break;
		case 84:
			strcat(str, "t");
			mlx_string_put(data->mlx, data->win, j, 25, 0xAAAAAA,"t");
			j++;
			break;
		case 85:
			strcat(str, "u");
			mlx_string_put(data->mlx, data->win, j, 25, 0xAAAAAA,"u");
			j++;
			break;
		case 86:
			strcat(str, "v");
			mlx_string_put(data->mlx, data->win, j, 25, 0xAAAAAA,"v");
			j++;
			break;
		case 87:
			strcat(str, "w");
			mlx_string_put(data->mlx, data->win, j, 25, 0xAAAAAA,"w");
			j++;
			break;
		case 88:
			strcat(str, "x");
			mlx_string_put(data->mlx, data->win, j, 25, 0xAAAAAA,"x");
			j++;
			break;
		case 89:
			strcat(str, "y");
			mlx_string_put(data->mlx, data->win, j, 25, 0xAAAAAA,"y");
			j++;
			break;
		case 90:
			strcat(str, "z");
			mlx_string_put(data->mlx, data->win, j, 25, 0xAAAAAA,"z");
			j++;
			break;
		default:
			flag = -1;
	}
 }

void read_window(t_mlx *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIN, WIN, "FDF");
	data->image = mlx_new_image(data->mlx, WIN, WIN);
	data->art = (int*)mlx_get_data_addr(data->image, &data->endian,
										&data->line_s, &data->bbp);
	mlx_hook(data->win, 2, 0, key, &data);
	if (flag == -1)
	{
		mlx_string_put(data->mlx, data->win, 0, 30, 0xAAAAAA,
					   "wrong simbol\n");
	}

}

int				main(int argc, char **argv)
{
	int			fd;
	int			fd1;
	t_struct	data;
	t_coor		coor;
	t_mlx		lib;

	if (argc < 2)
	{
		write(2, "usage: ./fdf [file_map]\n", 25);
		return (1);
	}
	read_window(&lib);
	fd = open(argv[1], O_RDONLY);
	fd1 = open(argv[1], O_RDONLY);
	if ((fd <= 0) || (fd1 <= 0) || ((ft_check_map(fd, &data) == 1)) //проверка на цифры в файле
	|| (data.count <= 0))
		ft_print_mistake();
	initialize(&data); // объявление mlx переменных
	ft_hurt(&data, &coor, fd1);
	mlx_hook(data.win, 4, 0, key_mouse, &data);
	mlx_hook(data.win, 2, 0, key_hook, &data);
	mlx_loop(data.mlx);
	close(fd);
	close(fd1);
	return (0);
}
