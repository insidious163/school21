/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strwlenutf8.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 02:07:33 by trhogoro          #+#    #+#             */
/*   Updated: 2018/12/23 02:08:45 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>
#include "libft.h"

size_t		ft_utf8strwlen(wchar_t *wstr)
{
	size_t len;

	len = 0;
	while (*wstr)
	{
		if (*wstr > UTF8_MAX_3BYTE)
			len += 4;
		else if (*wstr > UTF8_MAX_2BYTE)
			len += 3;
		else if (*wstr > UTF8_MAX_1BYTE)
			len += 2;
		else
			len += 1;
		wstr++;
	}
	return (len);
}
