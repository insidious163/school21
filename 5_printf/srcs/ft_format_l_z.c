/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_l_z.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 03:18:10 by trhogoro          #+#    #+#             */
/*   Updated: 2018/12/16 03:40:16 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_print_l_z(t_pelem pelem, va_list *ap)
{
	ssize_t	value;
	char	*string;

	string = 0x0;
	if (ft_strchr("diuoXxb", pelem.spec))
	{
		value = va_arg(*ap, ssize_t);
		if (ft_strchr("di", pelem.spec))
			string = ft_sttoa_base(value, DEC, SIGNED);
		else if (ft_strchr("u", pelem.spec))
			string = ft_sttoa_base(value, DEC, UNSIGNED);
		else if (ft_strchr("o", pelem.spec))
			string = ft_sttoa_base(value, OCT, UNSIGNED);
		else if (ft_strchr("xX", pelem.spec))
			string = ft_sttoa_base(value, HEX, UNSIGNED);
		else if (pelem.spec == 'b')
			string = ft_sttoa_base(value, BIN, UNSIGNED);
		return (string);
	}
	return (0x0);
}
