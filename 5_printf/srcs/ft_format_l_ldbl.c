/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_l_ldbl.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 23:35:21 by trhogoro          #+#    #+#             */
/*   Updated: 2018/12/11 16:06:05 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dbl_2.h"
#include <stdlib.h>

char	*ft_print_l_ldbl(t_pelem pelem, va_list *ap)
{
	char		*str;
	long double	value;

	str = 0x0;
	if (ft_strchr(SPEC_DBL, pelem.spec))
	{
		value = va_arg(*ap, long double);
		if (pelem.spec == 'e')
			str = ft_ldtoa(value, pelem);
		else if (pelem.spec == 'f')
			str = ft_ldtoa(value, pelem);
		else if (pelem.spec == 'g')
			str = ft_ldtoa(value, pelem);
		return (str);
	}
	return (0x0);
}
