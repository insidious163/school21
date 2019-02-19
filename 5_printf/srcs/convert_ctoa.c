/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_ctoa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 03:11:31 by trhogoro          #+#    #+#             */
/*   Updated: 2018/12/11 16:53:23 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ctoa_10(unsigned char c, char sign)
{
	size_t			len;
	unsigned char	temp;
	char			*result;

	temp = c;
	len = (size_t)(temp == 0);
	while (temp)
	{
		len++;
		temp /= 10;
	}
	len += (sign < 0);
	if (!(result = ft_strnew(len)))
		return (0x0);
	result[0] = (char)(c ? '-' : '0');
	temp = c;
	while (temp)
	{
		result[--len] = (char)('0' + temp % 10);
		temp /= 10;
	}
	return (result);
}

static char		*ctoa_2(unsigned char c)
{
	size_t			len;
	unsigned char	temp;
	char			*result;

	temp = c;
	len = (size_t)(temp == 0);
	while (temp)
	{
		len++;
		temp /= 2;
	}
	if (!(result = ft_strnew(len)))
		return (0x0);
	result[0] = '0';
	temp = c;
	while (temp)
	{
		result[--len] = (char)('0' + temp % 2);
		temp /= 2;
	}
	return (result);
}

static char		*ctoa_8(unsigned char c)
{
	size_t			len;
	unsigned char	temp;
	char			*result;

	temp = c;
	len = (size_t)(temp == 0);
	while (temp)
	{
		len++;
		temp /= 8;
	}
	if (!(result = ft_strnew(len)))
		return (0x0);
	result[0] = '0';
	temp = c;
	while (temp)
	{
		result[--len] = (char)('0' + temp % 8);
		temp /= 8;
	}
	return (result);
}

static char		*ctoa_16(unsigned char c)
{
	size_t			len;
	unsigned char	temp;
	char			*result;

	temp = c;
	len = (size_t)(temp == 0);
	while (temp)
	{
		len++;
		temp /= 16;
	}
	if (!(result = ft_strnew(len)))
		return (0x0);
	result[0] = '0';
	temp = c;
	while (temp)
	{
		(temp % 16 < 10) ? (result[--len] = (char)('0' + temp % 16))
						: (result[--len] = (char)('a' + temp % 16 - 10));
		temp /= 16;
	}
	return (result);
}

char			*ft_ctoa_base(char c, char base, char sign)
{
	unsigned char temp;

	if (base == 10)
	{
		if (sign)
		{
			sign = (char)((c < 0) ? -1 : 1);
			(c == c * (-1) * (-1)) ?
			(temp = (unsigned char)(sign * c)) :
			(temp = (unsigned char)((sign * (c + 1)) + 1));
		}
		else
			temp = (unsigned char)c;
		return (ctoa_10(temp, sign));
	}
	else if (base == 8)
		return (ctoa_8((unsigned char)c));
	else if (base == 16)
		return (ctoa_16((unsigned char)c));
	else if (base == 2)
		return (ctoa_2((unsigned char)c));
	return (0x0);
}
