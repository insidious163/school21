/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_l_h.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 23:35:30 by trhogoro          #+#    #+#             */
/*   Updated: 2018/12/20 03:59:17 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

char		*ft_print_l_h(t_pelem pelem, va_list *ap)
{
	short	value;
	char	*string;

	string = 0x0;
	if (ft_strchr(SPEC_INT, pelem.spec))
	{
		value = (short)va_arg(*ap, int);
		if (ft_strchr("di", pelem.spec))
			string = ft_stoa_base(value, DEC, SIGNED);
		else if (ft_strchr("u", pelem.spec))
			string = ft_stoa_base(value, DEC, UNSIGNED);
		else if (ft_strchr("o", pelem.spec))
			string = ft_stoa_base(value, OCT, UNSIGNED);
		else if (ft_strchr("xX", pelem.spec))
			string = ft_stoa_base(value, HEX, UNSIGNED);
		else if (ft_strchr("b", pelem.spec))
			string = ft_stoa_base(value, BIN, UNSIGNED);
		return (string);
	}
	return (0x0);
}
