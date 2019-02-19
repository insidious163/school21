/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_l_hh.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 23:35:43 by trhogoro          #+#    #+#             */
/*   Updated: 2018/12/20 04:04:25 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

char		*ft_print_l_hh(t_pelem pelem, va_list *ap)
{
	char	value;
	char	*string;

	string = 0x0;
	if (ft_strchr(SPEC_INT, pelem.spec))
	{
		value = (char)va_arg(*ap, int);
		if (ft_strchr("di", pelem.spec))
			string = ft_ctoa_base(value, DEC, SIGNED);
		else if (ft_strchr("u", pelem.spec))
			string = ft_ctoa_base(value, DEC, UNSIGNED);
		else if (ft_strchr("o", pelem.spec))
			string = ft_ctoa_base(value, OCT, UNSIGNED);
		else if (ft_strchr("xX", pelem.spec))
			string = ft_ctoa_base(value, HEX, UNSIGNED);
		else if (ft_strchr("b", pelem.spec))
			string = ft_ctoa_base(value, BIN, UNSIGNED);
		return (string);
	}
	return (0x0);
}
