/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbl_10.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 03:44:59 by trhogoro          #+#    #+#             */
/*   Updated: 2018/12/11 16:57:47 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dbl_2.h"
#include <stdlib.h>

static char					*dbld_frc(int x, unsigned long long mantisa)
{
	char	*power2;
	char	*result;
	char	*mantisa_str;
	char	*temp;
	size_t	i;

	if (!(power2 = ft_strpower2(x)))
		return (0x0);
	if (!(mantisa_str = ft_llitoa_base(mantisa, DEC, 0)))
	{
		free(power2);
		return (0x0);
	}
	temp = ft_strmltfrc(mantisa_str, power2);
	result = ft_strnew(ft_strlen(temp) - ft_strlen(mantisa_str));
	ft_strcpy(result, temp + ft_strlen(mantisa_str));
	free(temp);
	free(power2);
	free(mantisa_str);
	i = ft_strlen(result) - 1;
	while (result[i] == '0' && i > 0)
		result[i--] = '\0';
	return (result);
}

static char					*dbld_int(int x, unsigned long long mantisa)
{
	char *power2;
	char *result;
	char *mantisa_str;

	if (!(power2 = ft_strpower2(x)))
		return (0x0);
	if (!(mantisa_str = ft_llitoa_base(mantisa, DEC, 0)))
	{
		free(power2);
		return (0x0);
	}
	result = ft_strmltint(power2, mantisa_str);
	free(power2);
	free(mantisa_str);
	return (result);
}

static unsigned long long	ft_masked_mantisa(int x, unsigned long long mantisa)
{
	unsigned long long	masked_mantisa;
	int					y;

	masked_mantisa = 0;
	y = x;
	while (y++)
	{
		masked_mantisa = masked_mantisa << 1;
		masked_mantisa += 1;
	}
	masked_mantisa = masked_mantisa & mantisa;
	return (masked_mantisa);
}

t_double_d					ft_dbld_create(t_double dbl, char isld)
{
	int					x;
	t_double_d			result;

	result.is_nan = dbl.is_nan;
	result.is_inf = dbl.is_inf;
	result.sign = dbl.sign;
	x = dbl.exponent - ((isld) ? (DBL_MAXEXP_L + 64) : (DBL_MAXEXP + 52));
	if (x >= 0)
	{
		result.int_part = dbld_int(x, dbl.mantisa);
		result.frc_part = ft_strcpy(ft_strnew(1), "0");
	}
	else if (x >= ((isld) ? -64 : -52))
	{
		result.int_part = dbld_int(0, dbl.mantisa >> -x);
		result.frc_part = dbld_frc(x, ft_masked_mantisa(x, dbl.mantisa));
	}
	else
	{
		result.int_part = ft_strcpy(ft_strnew(1), "0");
		result.frc_part = dbld_frc(x, dbl.mantisa);
	}
	return (result);
}
