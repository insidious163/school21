/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbl_mlt_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 04:19:27 by trhogoro          #+#    #+#             */
/*   Updated: 2018/12/25 04:19:30 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_convert_tostr(int **temp, size_t len)
{
	char	*result;
	int		add;

	add = 0;
	if (!(result = ft_strnew(len)))
	{
		free(*temp);
		return (0x0);
	}
	while (len--)
	{
		(*temp)[len] += add;
		add = (*temp)[len] / 10;
		result[len] = (char)('0' + (*temp)[len] % 10);
	}
	free(*temp);
	return (result);
}

char		*ft_remove_zeros(char *result)
{
	int		index;
	char	*sub;

	index = 0;
	while (result[index] && result[index] == '0')
		index++;
	if (!index)
		return (result);
	if (!result[index])
	{
		free(result);
		return (ft_memmove(ft_strnew(1), "0", 1));
	}
	else
	{
		sub = ft_strsub(result, (unsigned int)index, ft_strlen(result) - index);
		free(result);
	}
	return (sub);
}
