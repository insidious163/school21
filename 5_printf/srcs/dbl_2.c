/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbl_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 03:17:36 by trhogoro          #+#    #+#             */
/*   Updated: 2018/12/11 16:57:37 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dbl_2.h"

t_double		ft_convert_double(double value)
{
	t_double result;

	result.mantisa = (unsigned long long)(*(long int *)&value & MASK_MANTISA);
	result.exponent = (short)(*(long int *)&value >> 52);
	result.sign = (char)((result.exponent & MASK_SIGN) ? 1 : 0);
	result.exponent = (short)(result.exponent & MASK_EXPONENT);
	result.is_norm = (char)(result.exponent ? 1 : 0);
	if (result.is_norm)
		result.mantisa = result.mantisa | DBL_MANTISA_HIGH_BIT;
	result.is_inf = 0;
	result.is_nan = 0;
	if (result.exponent == MASK_INF)
	{
		if (!result.mantisa)
			result.is_inf = 1;
		else
			result.is_nan = 1;
	}
	return (result);
}

t_double		ft_convert_ldouble(long double value)
{
	t_double result;

	result.mantisa = (*(unsigned long long int *)&value);
	result.exponent = (*(short *)((void *)&value + sizeof(long int)));
	result.sign = (char)((result.exponent & MASK_SIGN_L) ? 1 : 0);
	result.exponent = (short)(result.exponent & MASK_EXPONENT_L);
	result.is_norm = (char)((result.mantisa & MASK_BIT63) ? 1 : 0);
	result.is_inf = 0;
	result.is_nan = 0;
	if (result.exponent == MASK_EXPONENT_L)
	{
		if (!(result.mantisa & MASK_BIT_0_61))
			result.is_inf = 1;
		else
			result.is_nan = 1;
	}
	return (result);
}
