/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstrutf8.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 02:08:55 by trhogoro          #+#    #+#             */
/*   Updated: 2018/12/23 02:14:13 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>
#include "libft.h"

char			*ft_utf8strstr(wchar_t *ws)
{
	size_t	len;
	char	*result;
	int		i;

	len = ft_utf8strwlen(ws);
	i = 0;
	if ((result = ft_strnew(len)))
		while (*ws)
		{
			if (*ws <= UTF8_MAX_1BYTE)
				result[i++] = (char)*ws;
			else if (*ws <= UTF8_MAX_2BYTE)
			{
				result[i++] = (char)(0xC0 + (*ws >> 6));
				result[i++] = (char)(0x80 + (*ws & 0x3F));
			}
			else
			{
				result[i++] = (char)(0xE0 + (*ws >> 12));
				result[i++] = (char)(0x80 + ((*ws >> 6) & 0x3F));
				result[i++] = (char)(0x80 + (*ws & 0x3F));
			}
			ws++;
		}
	return (result);
}
