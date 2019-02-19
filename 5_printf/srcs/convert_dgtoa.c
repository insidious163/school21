/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_dgtoa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 18:08:58 by trhogoro          #+#    #+#             */
/*   Updated: 2018/12/11 16:59:32 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dbl_2.h"
#include "ft_printf.h"
#include <stdlib.h>

static char		*remove_extra_digits(char *e, int prec)
{
	char *result;

	result = e;
	while ((*e == '0') || (*e == '.') || (*e == '-') || (*e == '+'))
		e++;
	while (prec-- && *e != '\0')
	{
		if (*e == '.')
			prec++;
		e++;
	}
	*e = '\0';
	return (result);
}

char			*ft_dtoa_g(t_double_d d, t_double_d dg, t_pelem pelem)
{
	char	*e;
	int		len;
	int		exp;

	pelem.precision = (!pelem.precision ? 0 : pelem.precision - 1);
	e = ft_dtoa_e(d, pelem);
	len = ft_strlen(e);
	while (e[len] != 'e')
		len--;
	exp = ft_atoi(e + len + 1);
	if ((exp < -4) || (exp >= pelem.precision))
		ft_clear_t_double_d(dg);
	else
	{
		free(e);
		e = ft_dtoa_f(dg, pelem, 1);
		remove_extra_digits(e, pelem.precision + 1);
	}
	len = ft_strlen(e);
	if (len > pelem.precision)
		while (e[--len] == '0')
			e[len] = '\0';
	if (e[len] == '.')
		e[len] = '\0';
	return (e);
}
