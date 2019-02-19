/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_itoa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 05:27:46 by trhogoro          #+#    #+#             */
/*   Updated: 2018/12/11 16:53:57 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*itoa_10(unsigned int i, char sign)
{
	size_t			len;
	unsigned int	temp;
	char			*result;

	temp = i;
	len = (size_t)(temp == 0);
	while (temp)
	{
		len++;
		temp /= 10;
	}
	len += (sign < 0);
	if (!(result = ft_strnew(len)))
		return (0x0);
	result[0] = (char)(i ? '-' : '0');
	temp = i;
	while (temp)
	{
		result[--len] = (char)('0' + temp % 10);
		temp /= 10;
	}
	return (result);
}

static char		*itoa_2(unsigned int i)
{
	size_t			len;
	unsigned int	temp;
	char			*result;

	temp = i;
	len = (size_t)(temp == 0);
	while (temp)
	{
		len++;
		temp /= 2;
	}
	if (!(result = ft_strnew(len)))
		return (0x0);
	result[0] = '0';
	temp = i;
	while (temp)
	{
		result[--len] = (char)('0' + temp % 2);
		temp /= 2;
	}
	return (result);
}

static char		*itoa_8(unsigned int i)
{
	size_t			len;
	unsigned int	temp;
	char			*result;

	temp = i;
	len = (size_t)(temp == 0);
	while (temp)
	{
		len++;
		temp /= 8;
	}
	if (!(result = ft_strnew(len)))
		return (0x0);
	result[0] = '0';
	temp = i;
	while (temp)
	{
		result[--len] = (char)('0' + temp % 8);
		temp /= 8;
	}
	return (result);
}

static char		*itoa_16(unsigned int i)
{
	size_t			len;
	unsigned int	temp;
	char			*result;

	temp = i;
	len = (size_t)(temp == 0);
	while (temp)
	{
		len++;
		temp /= 16;
	}
	if (!(result = ft_strnew(len)))
		return (0x0);
	result[0] = '0';
	temp = i;
	while (temp)
	{
		(temp % 16 < 10) ? (result[--len] = (char)('0' + temp % 16))
						: (result[--len] = (char)('a' + temp % 16 - 10));
		temp /= 16;
	}
	return (result);
}

char			*ft_itoa_base(int i, char base, char sign)
{
	unsigned int	temp;

	if (base == 10)
	{
		if (sign)
		{
			sign = (char)((i < 0) ? -1 : 1);
			(i == i * (-1) * (-1)) ?
			(temp = (unsigned int)(sign * i)) :
			(temp = (unsigned int)((sign * (i + 1)) + 1));
		}
		else
			temp = (unsigned int)i;
		return (itoa_10(temp, sign));
	}
	else if (base == 8)
		return (itoa_8((unsigned int)i));
	else if (base == 16)
		return (itoa_16((unsigned int)i));
	else if (base == 2)
		return (itoa_2((unsigned int)i));
	return (0x0);
}
