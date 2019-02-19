/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_l_ll.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 23:35:55 by trhogoro          #+#    #+#             */
/*   Updated: 2018/12/11 16:05:38 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

char	*ft_print_l_ll(t_pelem pelem, va_list *ap)
{
	long long int	value;
	char			*string;

	string = 0x0;
	if (ft_strchr(SPEC_INT, pelem.spec))
	{
		value = va_arg(*ap, long long int);
		if (ft_strchr("di", pelem.spec))
			string = ft_llitoa_base(value, DEC, SIGNED);
		else if (ft_strchr("u", pelem.spec))
			string = ft_llitoa_base(value, DEC, UNSIGNED);
		else if (ft_strchr("o", pelem.spec))
			string = ft_llitoa_base(value, OCT, UNSIGNED);
		else if (ft_strchr("xX", pelem.spec))
			string = ft_llitoa_base(value, HEX, UNSIGNED);
		else if (ft_strchr("b", pelem.spec))
			string = ft_llitoa_base(value, BIN, UNSIGNED);
		return (string);
	}
	return (0x0);
}
