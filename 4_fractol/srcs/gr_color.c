/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gr_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 22:53:30 by trhogoro          #+#    #+#             */
/*   Updated: 2019/01/09 22:53:31 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>
#include "fractol.h"
#include "libft.h"
#include <fcntl.h>

static int	ft_get_color(int *color, char *line)
{
	int		i;

	*color = 0;
	i = 1;
	if (ft_strlen(line) != 10)
		return (1);
	if (!ft_strnequ("0x", line, 2))
		return (1);
	while (++i < 10)
	{
		*color = *color * 16;
		if (line[i] <= '9' && line[i] >= '0')
			*color += line[i] - '0';
		else if (line[i] <= 'F' && line[i] >= 'A')
			*color += line[i] - 'A' + 10;
		else if (line[i] <= 'f' && line[i] >= 'a')
			*color += line[i] - 'a' + 10;
		else
			return (1);
	}
	return (0);
}

int			ft_get_colors(char *color_file, t_params **params)
{
	int		fd;
	char	*line;
	int		i;
	int		color;

	if (!color_file)
		return (E_NUM_COL_FILE);
	if ((fd = open(color_file, O_RDONLY)) < 0)
		return (E_NUM_COL_FILE);
	i = 0;
	while (ft_gnl(fd, &line) > 0)
	{
		if (ft_get_color(&color, line))
			return (E_NUM_COL_FILE);
		(*params)[0].color[i++] = color;
	}
	return (0);
}
