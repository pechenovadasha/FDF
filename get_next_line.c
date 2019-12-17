/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croxane <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 15:23:03 by croxane           #+#    #+#             */
/*   Updated: 2019/09/01 18:36:52 by croxane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"

int				ft_new_str(char **str, char **line, int fd, int ret)
{
	int			i;
	char		*src;

	i = 0;
	while (str[fd][i] != '\n' && str[fd][i] != '\0')
		i++;
	if (str[fd][i] == '\n')
	{
		*line = ft_strsub(str[fd], 0, i);
		src = ft_strdup(str[fd] + i + 1);
		free(str[fd]);
		str[fd] = src;
		if (str[fd][0] == '\0')
			ft_strdel(&str[fd]);
	}
	else if (str[fd][i] == '\0')
	{
		if (ret == BUFF_SIZE)
			return (get_next_line(fd, line));
		*line = ft_strdup(str[fd]);
		ft_strdel(&str[fd]);
	}
	return (1);
}

int				get_next_line(int const fd, char **line)
{
	static char	*str[1024];
	char		buff[BUFF_SIZE + 1];
	int			ret;
	char		*src;

	if (fd < 0 || line == NULL)
		return (-1);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (str[fd] == NULL)
			if (!(str[fd] = ft_memalloc(2)))
				return (-1);
		src = ft_strjoin(str[fd], buff);
		free(str[fd]);
		str[fd] = src;
		if (ft_strchr(buff, '\n'))
			break ;
	}
	if (ret < 0)
		return (-1);
	else if (ret == 0 && (str[fd] == NULL || str[fd][0] == '\0'))
		return (0);
	return (ft_new_str(str, line, fd, ret));
}
