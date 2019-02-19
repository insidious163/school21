/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlenutf8.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 02:14:34 by trhogoro          #+#    #+#             */
/*   Updated: 2018/12/23 02:16:40 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <wchar.h>

int			ft_utf8strlen(char *str)
{
	int len;
	int i;
	int in;

	len = 0;
	in = 0;
	while (str[in])
	{
		i = (((str[in] & 0xF8) == 0xF0) && str[in + 1] && ((str[in + 1] & 0xC0)
		== 0x80) && str[in + 2] && ((str[in + 2] & 0xC0) == 0x80) && str[in + 3]
		&& ((str[in + 3] & 0xC0) == 0x80)) * 4 + (((str[in] & 0xF0) == 0xE0) &&
		str[in + 1] && ((str[in + 1] & 0xC0) == 0x80) && str[in + 2] &&
		((str[in + 2] & 0xC0) == 0x80)) * 3 + (((str[in] & 0xE0) == 0xC0) &&
		str[in + 1] && ((str[in + 1] & 0xC0) == 0x80)) * 2 +
		(((str[in] & 0x80) == 0) ? 1 : 0);
		if (!i)
			return (-1);
		len++;
		in += i;
	}
	return (len);
}
