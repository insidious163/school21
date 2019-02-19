/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_l_j.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 03:21:32 by trhogoro          #+#    #+#             */
/*   Updated: 2018/12/20 04:03:58 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

char		*ft_print_l_j(t_pelem pelem, va_list *ap)
{
	intmax_t	value;
	char		*string;

	string = 0x0;
	if (ft_strchr(SPEC_INT, pelem.spec))
	{
		value = va_arg(*ap, intmax_t);
		if (ft_strchr("di", pelem.spec))
			string = ft_imtoa_base(value, DEC, SIGNED);
		else if (ft_strchr("u", pelem.spec))
			string = ft_imtoa_base(value, DEC, UNSIGNED);
		else if (ft_strchr("o", pelem.spec))
			string = ft_imtoa_base(value, OCT, UNSIGNED);
		else if (ft_strchr("xX", pelem.spec))
			string = ft_imtoa_base(value, HEX, UNSIGNED);
		else if (pelem.spec == 'b')
			string = ft_imtoa_base(value, BIN, UNSIGNED);
		return (string);
	}
	return (0x0);
}
