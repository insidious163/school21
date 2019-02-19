/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_nptoa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 18:52:14 by trhogoro          #+#    #+#             */
/*   Updated: 2018/12/05 18:52:16 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_str_nonprintable(char *str)
{
	size_t	len;
	char	*result;

	len = ft_strlen(str);
	result = str;
	while (*result)
	{
		if (!ft_isprint(*result++))
			len += 3;
	}
	result = (char *)malloc(len);
	while (*str)
	{
		if (ft_isprint(*str))
			*result++ = *str++;
		else
		{
			*result++ = '\\';
			*result++ = (char)('0' + (*str / 100));
			*result++ = (char)('0' + ((*str / 10) % 10));
			*result++ = (char)('0' + (*str++ % 10));
		}
	}
	return (result);
}
