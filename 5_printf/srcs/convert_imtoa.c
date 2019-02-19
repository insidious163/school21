/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_imtoa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 20:13:15 by trhogoro          #+#    #+#             */
/*   Updated: 2018/12/16 03:43:10 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*imtoa_10(uintmax_t im, char sign)
{
	size_t		len;
	uintmax_t	temp;
	char		*result;

	temp = im;
	len = (size_t)(temp == 0);
	while (temp)
	{
		len++;
		temp /= 10;
	}
	len += (sign < 0);
	if (!(result = ft_strnew(len)))
		return (0x0);
	result[0] = (im ? '-' : '0');
	temp = im;
	while (temp)
	{
		result[--len] = (char)('0' + temp % 10);
		temp /= 10;
	}
	return (result);
}

static char		*imtoa_2(uintmax_t im)
{
	size_t		len;
	uintmax_t	temp;
	char		*result;

	temp = im;
	len = (size_t)(temp == 0);
	while (temp)
	{
		len++;
		temp /= 2;
	}
	if (!(result = ft_strnew(len)))
		return (0x0);
	result[0] = '0';
	temp = im;
	while (temp)
	{
		result[--len] = (char)('0' + temp % 2);
		temp /= 2;
	}
	return (result);
}

static char		*imtoa_8(uintmax_t im)
{
	size_t		len;
	uintmax_t	temp;
	char		*result;

	temp = im;
	len = (size_t)(temp == 0);
	while (temp)
	{
		len++;
		temp /= 8;
	}
	if (!(result = ft_strnew(len)))
		return (0x0);
	result[0] = '0';
	temp = im;
	while (temp)
	{
		result[--len] = (char)('0' + temp % 8);
		temp /= 8;
	}
	return (result);
}

static char		*imtoa_16(uintmax_t im)
{
	size_t		len;
	uintmax_t	temp;
	char		*result;

	temp = im;
	len = (size_t)(temp == 0);
	while (temp)
	{
		len++;
		temp /= 16;
	}
	if (!(result = ft_strnew(len)))
		return (0x0);
	result[0] = '0';
	temp = im;
	while (temp)
	{
		result[--len] = (temp % 16 < 10) ? ((char)('0' + temp % 16))
						: (char)('a' + temp % 16 - 10);
		temp /= 16;
	}
	return (result);
}

char			*ft_imtoa_base(intmax_t im, char base, char sign)
{
	uintmax_t	temp;

	if (base == 10)
	{
		if (sign)
		{
			sign = (im < 0) ? -1 : 1;
			(im == im * (-1) * (-1)) ?
			(temp = (uintmax_t)(sign * im)) :
			(temp = (uintmax_t)((sign * (im + 1)) + 1));
		}
		else
			temp = (uintmax_t)im;
		return (imtoa_10(temp, sign));
	}
	else if (base == 8)
		return (imtoa_8((uintmax_t)im));
	else if (base == 16)
		return (imtoa_16((uintmax_t)im));
	else if (base == 2)
		return (imtoa_2((uintmax_t)im));
	return (0x0);
}
