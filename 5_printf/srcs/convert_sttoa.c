/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_sttoa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 03:27:08 by trhogoro          #+#    #+#             */
/*   Updated: 2018/12/20 04:13:51 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*sttoa_10(size_t st, char sign)
{
	size_t	len;
	size_t	temp;
	char	*result;

	temp = st;
	len = (size_t)(temp == 0);
	while (temp)
	{
		len++;
		temp /= 10;
	}
	len += (sign < 0);
	if (!(result = ft_strnew(len)))
		return (0x0);
	result[0] = (char)(st ? '-' : '0');
	temp = st;
	while (temp)
	{
		result[--len] = (char)('0' + temp % 10);
		temp /= 10;
	}
	return (result);
}

static char		*sttoa_2(size_t st)
{
	size_t	len;
	size_t	temp;
	char	*result;

	temp = st;
	len = (size_t)(temp == 0);
	while (temp)
	{
		len++;
		temp /= 2;
	}
	if (!(result = ft_strnew(len)))
		return (0x0);
	result[0] = '0';
	temp = st;
	while (temp)
	{
		result[--len] = (char)('0' + temp % 2);
		temp /= 2;
	}
	return (result);
}

static char		*sttoa_8(size_t st)
{
	size_t	len;
	size_t	temp;
	char	*result;

	temp = st;
	len = (size_t)(temp == 0);
	while (temp)
	{
		len++;
		temp /= 8;
	}
	if (!(result = ft_strnew(len)))
		return (0x0);
	result[0] = '0';
	temp = st;
	while (temp)
	{
		result[--len] = (char)('0' + temp % 8);
		temp /= 8;
	}
	return (result);
}

static char		*sttoa_16(size_t st)
{
	size_t	len;
	size_t	temp;
	char	*result;

	temp = st;
	len = (size_t)(temp == 0);
	while (temp)
	{
		len++;
		temp /= 16;
	}
	if (!(result = ft_strnew(len)))
		return (0x0);
	result[0] = '0';
	temp = st;
	while (temp)
	{
		result[--len] = (temp % 16 < 10) ? ((char)('0' + temp % 16))
			: ((char)('a' + temp % 16 - 10));
		temp /= 16;
	}
	return (result);
}

char			*ft_sttoa_base(ssize_t st, char base, char sign)
{
	size_t	temp;

	if (base == 10)
	{
		if (sign)
		{
			sign = (char)((st < 0) ? -1 : 1);
			(st == st * (-1) * (-1)) ?
			(temp = (size_t)(sign * st)) :
			(temp = (size_t)((sign * (st + 1)) + 1));
		}
		else
			temp = (size_t)st;
		return (sttoa_10(temp, sign));
	}
	else if (base == 8)
		return (sttoa_8((size_t)st));
	else if (base == 16)
		return (sttoa_16((size_t)st));
	else if (base == 2)
		return (sttoa_2((size_t)st));
	return (0x0);
}
