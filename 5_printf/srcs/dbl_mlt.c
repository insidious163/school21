/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbl_mlt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 21:14:54 by trhogoro          #+#    #+#             */
/*   Updated: 2018/12/11 16:11:09 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dbl_2.h"
#include <stdlib.h>

int			*ft_newline(char *val2, char ch)
{
	int		*result;
	size_t	len;

	len = ft_strlen(val2);
	if (!(result = (int *)malloc(len * sizeof(int))))
		return (0x0);
	ft_memset(result, 0, sizeof(int) * (1 + len));
	while (len--)
		result[len] = (ch - '0') * (val2[len] - '0');
	return (result);
}

int			ft_fill_adds(char *val1, char *val2, int ***lines)
{
	int i;

	*lines = (int **)malloc(10 * sizeof(int*));
	i = -1;
	while (++i < 10)
		(*lines)[i] = 0x0;
	while (*val1)
	{
		if (!(*lines)[*val1 - '0'])
		{
			(*lines)[*val1 - '0'] = ft_newline(val2, *val1);
			if (!(*lines)[*val1 - '0'])
				return (1);
		}
		val1++;
	}
	return (0);
}

void		ft_add_line(int **temp, int *line, size_t index, size_t len)
{
	int i;

	i = 0;
	while (len--)
	{
		(*temp)[index - i] += line[len];
		i++;
	}
}

char		*ft_strmltfrc(char *val1, char *val2)
{
	size_t	len;
	int		**lines;
	int		*temp;
	size_t	index;

	index = ft_strlen(val1) + ft_strlen(val2);
	if (ft_fill_adds(val1, val2, &lines))
		return (0x0);
	temp = (int *)ft_memalloc(sizeof(int) * index);
	len = ft_strlen(val1);
	while (len--)
	{
		ft_add_line(&temp, lines[val1[len] - '0'], --index, ft_strlen(val2));
	}
	index = 10;
	while (index--)
		if (lines[index])
			free(lines[index]);
	free(lines);
	return (ft_convert_tostr(&temp, ft_strlen(val1) + ft_strlen(val2)));
}

char		*ft_strmltint(char *val1, char *val2)
{
	size_t	len;
	int		**lines;
	int		*temp;
	size_t	index;

	index = ft_strlen(val1) + ft_strlen(val2);
	if (ft_fill_adds(val1, val2, &lines))
		return (0x0);
	temp = (int *)ft_memalloc(sizeof(int) * index);
	len = ft_strlen(val1);
	while (len--)
	{
		ft_add_line(&temp, lines[val1[len] - '0'], --index, ft_strlen(val2));
	}
	index = 10;
	while (index--)
		if (lines[index])
			free(lines[index]);
	free(lines);
	return (ft_remove_zeros(ft_convert_tostr(&temp, ft_strlen(val1)
		+ ft_strlen(val2))));
}
