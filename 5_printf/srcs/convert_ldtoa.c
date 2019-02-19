/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_ldtoa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 03:46:47 by trhogoro          #+#    #+#             */
/*   Updated: 2018/12/11 16:54:10 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "dbl_2.h"

char			*ft_ldtoa(long double val, t_pelem pelem)
{
	t_double		dbl2;
	t_double_d		dbl10;
	t_double_d		dbl10_g;

	pelem.precision = ((pelem.precision == -1) ? 6 : pelem.precision);
	dbl2 = ft_convert_ldouble(val);
	if (ft_check_dbl2(dbl2))
		return (ft_check_dbl2(dbl2));
	dbl10 = ft_dbld_create(dbl2, LONG_DOUBLE_YES);
	if (!dbl10.int_part || !dbl10.frc_part)
		return (ft_clear_t_double_d(dbl10));
	if (pelem.spec == 'f')
		return (ft_dtoa_f(dbl10, pelem, 0));
	if (pelem.spec == 'e')
		return (ft_dtoa_e(dbl10, pelem));
	if (pelem.spec != 'g')
		return (0x0);
	dbl10_g = ft_dbld_create(dbl2, LONG_DOUBLE_YES);
	if (!dbl10_g.int_part || !dbl10_g.frc_part)
	{
		ft_clear_t_double_d(dbl10);
		return (ft_clear_t_double_d(dbl10_g));
	}
	return (ft_dtoa_g(dbl10, dbl10_g, pelem));
}
