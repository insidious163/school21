/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_llitoa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 18:09:50 by trhogoro          #+#    #+#             */
/*   Updated: 2018/12/11 16:55:06 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*llitoa_10(unsigned long long int lli, char sign)
{
	size_t				len;
	unsigned long long	temp;
	char				*result;

	temp = lli;
	len = (size_t)(temp == 0);
	while (temp)
	{
		len++;
		temp /= 10;
	}
	len += (sign < 0);
	if (!(result = ft_strnew(len)))
		return (0x0);
	result[0] = (char)(lli ? '-' : '0');
	temp = lli;
	while (temp)
	{
		result[--len] = (char)('0' + temp % 10);
		temp /= 10;
	}
	return (result);
}

static char		*llitoa_2(unsigned long long int lli)
{
	size_t				len;
	unsigned long long	temp;
	char				*result;

	temp = lli;
	len = (size_t)(temp == 0);
	while (temp)
	{
		len++;
		temp /= 2;
	}
	if (!(result = ft_strnew(len)))
		return (0x0);
	result[0] = '0';
	temp = lli;
	while (temp)
	{
		result[--len] = (char)('0' + temp % 2);
		temp /= 2;
	}
	return (result);
}

static char		*llitoa_8(unsigned long long int lli)
{
	size_t				len;
	unsigned long long	temp;
	char				*result;

	temp = lli;
	len = (size_t)(temp == 0);
	while (temp)
	{
		len++;
		temp /= 8;
	}
	if (!(result = ft_strnew(len)))
		return (0x0);
	result[0] = '0';
	temp = lli;
	while (temp)
	{
		result[--len] = (char)('0' + temp % 8);
		temp /= 8;
	}
	return (result);
}

static char		*llitoa_16(unsigned long long int lli)
{
	size_t				len;
	unsigned long long	temp;
	char				*result;

	temp = lli;
	len = (size_t)(temp == 0);
	while (temp)
	{
		len++;
		temp /= 16;
	}
	if (!(result = ft_strnew(len)))
		return (0x0);
	result[0] = '0';
	temp = lli;
	while (temp)
	{
		(temp % 16 < 10) ? (result[--len] = (char)('0' + temp % 16))
						: (result[--len] = (char)('a' + temp % 16 - 10));
		temp /= 16;
	}
	return (result);
}

char			*ft_llitoa_base(long long int lli, char base, char sign)
{
	unsigned long long int temp;

	if (base == 10)
	{
		if (sign)
		{
			sign = (char)((lli < 0) ? -1 : 1);
			(lli == lli * (-1) * (-1)) ?
			(temp = (unsigned long long int)(sign * lli)) :
			(temp = (unsigned long long int)((sign * (lli + 1)) + 1));
		}
		else
			temp = (unsigned long long int)lli;
		return (llitoa_10(temp, sign));
	}
	else if (base == 8)
		return (llitoa_8((unsigned long long int)lli));
	else if (base == 16)
		return (llitoa_16((unsigned long long int)lli));
	else if (base == 2)
		return (llitoa_2((unsigned long long int)lli));
	return (0x0);
}
