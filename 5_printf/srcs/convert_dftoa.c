/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_dftoa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 18:08:51 by trhogoro          #+#    #+#             */
/*   Updated: 2018/12/11 16:59:11 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dbl_2.h"
#include "ft_printf.h"
#include <stdlib.h>

char		*ft_dtoa_f(t_double_d d, t_pelem pelem, char is_g)
{
	size_t	len;
	char	*result;
	int		extra;
	char	*temp;

	(is_g && d.int_part[0] == '0') ? pelem.precision++ : (void)(0);
	if (!(temp = ft_strjoin(d.int_part, d.frc_part)))
		return (ft_clear_t_double_d(d));
	extra = ft_round_double(temp, ft_strlen(d.int_part) + pelem.precision);
	len = d.sign + extra + IL(d) + PR(pelem) + (PR(pelem) != 0);
	(!(result = ft_strnew(len))) ? free(temp) : (void)0;
	if (!result)
		return (ft_clear_t_double_d(d));
	ft_memset(result, '0', len);
	result[0] = '-';
	result[(int)d.sign] = (char)(extra + '0');
	ft_memmove(result + d.sign + extra, temp, ft_strlen(d.int_part));
	if (pelem.precision != 0)
		result[d.sign + ft_strlen(d.int_part) + extra] = '.';
	if (pelem.precision != 0)
		ft_memmove(result + d.sign + extra + IL(d) + 1, temp + IL(d), (PR(pelem)
		< (int)ft_strlen(temp + IL(d)) ? PR(pelem) : ft_strlen(temp + IL(d))));
	free(temp);
	ft_clear_t_double_d(d);
	return (result);
}
