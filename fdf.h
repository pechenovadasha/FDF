/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscottie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 18:50:58 by sscottie          #+#    #+#             */
/*   Updated: 2019/09/06 16:07:48 by croxane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "get_next_line.h"
# include "./libft/libft.h"

# define BUFF_SIZE 4096
# define WIDTH 1024
# define HEIGHT 1000

typedef struct	s_default
{
	int			x;
	int			y;
	int			z;
	int			colour;
}				t_default;

typedef struct	s_pixel
{
	int			x;
	int			y;
	int			z;
	int			colour;
}				t_pixel;

typedef	struct	s_volume
{
	int			x;
	int			y;
	int			z;
}				t_volume;

typedef struct	s_struct
{
	double		alfa;
	void		*mlx;
	void		*win;
	void		*image;
	int			*art;
	int			endian;
	int			line_s;
	int			bbp;
	int			count;
	float		push;
	int			length;
	float		zoom;
	t_pixel		*pixel;
	t_volume	*volume;
	t_default	*def;
}				t_struct;

typedef struct	s_print
{
	int			width;
	int			heigth;
	int			x0;
	int			y0;
	int			error;
	int			dx;
	int			dy;
	int			ystep;
	int			x;
	int			y;
	int			i;
	int			steep;
}				t_print;

typedef	struct	s_coor
{
	int			x;
	int			y;
	int			i;
}				t_coor;

int				ft_check_map(int fd, struct s_struct *data);
void			ft_filling(int fd, t_struct *data, t_coor *coor);
void			ft_zoom(struct s_struct *data);
int				ft_check_colour(const char *str);
int				ft_isblank(char c);
int				isvalid(char c, int base);
int				value_of(char c);
int				ft_atoi_base(const char *str, int str_base);
void			ft_move(struct s_struct *data);
void			ft_print_mistake(void);
void			ft_check_colour_two(struct s_struct *data, int i);
int				key_mouse(int key, int x, int y, t_struct *data);
int				key_hook(int key, void *param);
void			ft_push_left(t_struct *data);
void			ft_push_right(t_struct *data);
void			ft_push_up(t_struct *data);
void			ft_push_down(t_struct *data);
void			ft_swap(int *a, int *b);
void			ft_bresenhamline(int x1, int y1, t_struct *data, int i);
void			ft_print(struct s_struct *data);
void			ft_volume_point(struct s_struct *data);
void			ft_volume_point_y(struct s_struct *data);
void			clear_image(t_struct *data);
void			ft_volume_point(struct s_struct *data);
void			ft_volume_point_y(struct s_struct *data);
void			foo(t_struct *data);
void			ft_menu(struct s_struct *data);
void			ft_coor(t_coor *coor);
void			ft_not_iso(t_struct *data);
void			ft_move_2(t_struct *data);
void			ft_iso(t_struct *data);

#endif
