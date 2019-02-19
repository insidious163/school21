/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_litoa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 18:09:36 by trhogoro          #+#    #+#             */
/*   Updated: 2018/12/11 16:54:40 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*litoa_10(unsigned long int li, char sign)
{
	size_t				len;
	unsigned long int	temp;
	char				*result;

	temp = li;
	len = (size_t)(temp == 0);
	while (temp)
	{
		len++;
		temp /= 10;
	}
	len += (sign < 0);
	if (!(result = ft_strnew(len)))
		return (0x0);
	result[0] = (char)(li ? '-' : '0');
	temp = li;
	while (temp)
	{
		result[--len] = (char)('0' + temp % 10);
		temp /= 10;
	}
	return (result);
}

static char		*litoa_2(unsigned long int li)
{
	size_t				len;
	unsigned long int	temp;
	char				*result;

	temp = li;
	len = (size_t)(temp == 0);
	while (temp)
	{
		len++;
		temp /= 2;
	}
	if (!(result = ft_strnew(len)))
		return (0x0);
	result[0] = '0';
	temp = li;
	while (temp)
	{
		result[--len] = (char)('0' + temp % 2);
		temp /= 2;
	}
	return (result);
}

static char		*litoa_8(unsigned long int li)
{
	size_t				len;
	unsigned long int	temp;
	char				*result;

	temp = li;
	len = (size_t)(temp == 0);
	while (temp)
	{
		len++;
		temp /= 8;
	}
	if (!(result = ft_strnew(len)))
		return (0x0);
	result[0] = '0';
	temp = li;
	while (temp)
	{
		result[--len] = (char)('0' + temp % 8);
		temp /= 8;
	}
	return (result);
}

static char		*litoa_16(unsigned long int li)
{
	size_t				len;
	unsigned long int	temp;
	char				*result;

	temp = li;
	len = (size_t)(temp == 0);
	while (temp)
	{
		len++;
		temp /= 16;
	}
	if (!(result = ft_strnew(len)))
		return (0x0);
	result[0] = '0';
	temp = li;
	while (temp)
	{
		(temp % 16 < 10) ? (result[--len] = (char)('0' + temp % 16))
						: (result[--len] = (char)('a' + temp % 16 - 10));
		temp /= 16;
	}
	return (result);
}

char			*ft_litoa_base(long int li, char base, char sign)
{
	unsigned long int temp;

	if (base == 10)
	{
		if (sign)
		{
			sign = (char)((li < 0) ? -1 : 1);
			(li == li * (-1) * (-1)) ?
			(temp = (unsigned long int)(sign * li)) :
			(temp = (unsigned long int)((sign * (li + 1)) + 1));
		}
		else
			temp = (unsigned long int)li;
		return (litoa_10(temp, sign));
	}
	else if (base == 8)
		return (litoa_8((unsigned long int)li));
	else if (base == 16)
		return (litoa_16((unsigned long int)li));
	else if (base == 2)
		return (litoa_2((unsigned long int)li));
	return (0x0);
}
