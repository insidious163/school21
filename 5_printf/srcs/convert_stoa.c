/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_stoa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 18:09:26 by trhogoro          #+#    #+#             */
/*   Updated: 2018/12/11 16:55:25 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*stoa_10(unsigned short s, char sign)
{
	size_t			len;
	unsigned short	temp;
	char			*result;

	temp = s;
	len = (size_t)(temp == 0);
	while (temp)
	{
		len++;
		temp /= 10;
	}
	len += (sign < 0);
	if (!(result = ft_strnew(len)))
		return (0x0);
	result[0] = (char)(s ? '-' : '0');
	temp = s;
	while (temp)
	{
		result[--len] = (char)('0' + temp % 10);
		temp /= 10;
	}
	return (result);
}

static char		*stoa_2(unsigned short s)
{
	size_t			len;
	unsigned short	temp;
	char			*result;

	temp = s;
	len = (size_t)(temp == 0);
	while (temp)
	{
		len++;
		temp /= 2;
	}
	if (!(result = ft_strnew(len)))
		return (0x0);
	result[0] = '0';
	temp = s;
	while (temp)
	{
		result[--len] = (char)('0' + temp % 2);
		temp /= 2;
	}
	return (result);
}

static char		*stoa_8(unsigned short s)
{
	size_t			len;
	unsigned short	temp;
	char			*result;

	temp = s;
	len = (size_t)(temp == 0);
	while (temp)
	{
		len++;
		temp /= 8;
	}
	if (!(result = ft_strnew(len)))
		return (0x0);
	result[0] = '0';
	temp = s;
	while (temp)
	{
		result[--len] = (char)('0' + temp % 8);
		temp /= 8;
	}
	return (result);
}

static char		*stoa_16(unsigned short s)
{
	size_t			len;
	unsigned short	temp;
	char			*result;

	temp = s;
	len = (size_t)(temp == 0);
	while (temp)
	{
		len++;
		temp /= 16;
	}
	if (!(result = ft_strnew(len)))
		return (0x0);
	result[0] = '0';
	temp = s;
	while (temp)
	{
		(temp % 16 < 10) ? (result[--len] = (char)('0' + temp % 16))
						: (result[--len] = (char)('a' + temp % 16 - 10));
		temp /= 16;
	}
	return (result);
}

char			*ft_stoa_base(short s, char base, char sign)
{
	unsigned short	temp;

	if (base == 10)
	{
		if (sign)
		{
			sign = (char)((s < 0) ? -1 : 1);
			(s == s * (-1) * (-1)) ?
			(temp = (unsigned short)(sign * s)) :
			(temp = (unsigned short)((sign * (s + 1)) + 1));
		}
		else
			temp = (unsigned short)s;
		return (stoa_10(temp, sign));
	}
	else if (base == 8)
		return (stoa_8((unsigned short)s));
	else if (base == 16)
		return (stoa_16((unsigned short)s));
	else if (base == 2)
		return (stoa_2((unsigned short)s));
	return (0x0);
}
