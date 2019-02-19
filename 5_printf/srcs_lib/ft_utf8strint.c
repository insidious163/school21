/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchrutf8.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 02:16:59 by trhogoro          #+#    #+#             */
/*   Updated: 2018/12/23 02:17:13 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>
#include "libft.h"

static void	ft_utf8strint34(char **temp, wint_t wc)
{
	char *result;

	result = *temp;
	if (wc <= UTF8_MAX_3BYTE)
	{
		if ((wc >= 0xD800) && (wc < 0xE000))
		{
			wc = 0xD800;
		}
		result[0] = (char)(0xE0 + (wc >> 12));
		result[1] = (char)(0x80 + ((wc >> 6) & 0x3F));
		result[2] = (char)(0x80 + (wc & 0x3F));
		result[3] = '\0';
	}
	else
	{
		result[0] = (char)(0xF0 + ((wc >> 18) & 0x07));
		result[1] = (char)(0x80 + ((wc >> 12) & 0x3F));
		result[2] = (char)(0x80 + ((wc >> 6) & 0x3F));
		result[3] = (char)(0x80 + (wc & 0x3F));
		result[4] = '\0';
	}
}

char		*ft_utf8strint(wint_t wc)
{
	char *result;

	if (wc <= UTF8_MAX_1BYTE)
		result = ft_strnew(2);
	else
		result = (wc <= UTF8_MAX_2BYTE) ? ft_strnew(3) : ft_strnew(4);
	if (!result)
		return (0x0);
	if (wc <= UTF8_MAX_1BYTE)
	{
		result[0] = (char)wc;
		result[1] = '\0';
	}
	else if (wc <= UTF8_MAX_2BYTE)
	{
		result[0] = (char)(0xC0 + (wc >> 6));
		result[1] = (char)(0x80 + (wc & 0x3F));
		result[2] = '\0';
	}
	else
		ft_utf8strint34(&result, wc);
	return (result);
}
