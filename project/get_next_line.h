/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croxane <croxane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 17:27:57 by croxane           #+#    #+#             */
/*   Updated: 2019/05/04 17:07:06 by croxane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <stdio.h>
# include "get_next_line.h"
# define BUFF_SIZE 4096

int	get_next_line(int const fd, char **line);
int	ft_new_str(char **str, char **line, int const fd, int ret);

#endif
