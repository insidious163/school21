/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_l_0.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 23:35:09 by trhogoro          #+#    #+#             */
/*   Updated: 2018/12/20 04:05:58 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

static char		*ft_print_l_0_percent(t_pelem *pelem)
{
	char	*str;

	str = ft_strnew(1);
	str[0] = '%';
	pelem->spec = 'c';
	return (str);
}

static char		*ft_print_l_0_efg(t_pelem *pelem, va_list *ap)
{
	char	*str;
	double	value;

	str = 0x0;
	if (ft_strchr(SPEC_DBL, pelem->spec))
	{
		value = va_arg(*ap, double);
		if ((pelem->spec == 'e') || (pelem->spec == 'E'))
			str = ft_dtoa(value, *pelem);
		else if ((pelem->spec == 'f') || (pelem->spec == 'F'))
			str = ft_dtoa(value, *pelem);
		else if ((pelem->spec == 'g') || (pelem->spec == 'G'))
			str = ft_dtoa(value, *pelem);
	}
	else
		return (ft_print_l_0_percent(pelem));
	return (str);
}

static char		*ft_print_l_0_csprefg(t_pelem *pelem, va_list *ap)
{
	char	*str;
	char	*temp;

	if (pelem->spec == 'c')
		ft_memset(str = ft_strnew(1), (char)(va_arg(*ap, int)), 1);
	else if (pelem->spec == 's')
	{
		temp = va_arg(*ap, char *);
		str = temp ? ft_strnew(ft_strlen(temp)) :
			ft_memmove(ft_strnew(6), "(null)", 6);
		temp ? ft_strcpy(str, temp) : (void *)0;
	}
	else if (pelem->spec == 'p')
		str = ft_llitoa_base(va_arg(*ap, long long int), HEX, UNSIGNED);
	else if (pelem->spec == 'r')
		str = ft_str_nonprintable(va_arg(*ap, char *));
	else
		return (ft_print_l_0_efg(pelem, ap));
	return (str);
}

char			*ft_print_l_0(t_pelem *pelem, va_list *ap)
{
	int		value;
	char	*string;

	string = 0x0;
	if (ft_strchr(SPEC_INT, pelem->spec))
	{
		value = va_arg(*ap, int);
		if (ft_strchr("di", pelem->spec))
			string = ft_itoa_base(value, DEC, SIGNED);
		else if (ft_strchr("u", pelem->spec))
			string = ft_itoa_base(value, DEC, UNSIGNED);
		else if (ft_strchr("o", pelem->spec))
			string = ft_itoa_base(value, OCT, UNSIGNED);
		else if (ft_strchr("xX", pelem->spec))
			string = ft_itoa_base(value, HEX, UNSIGNED);
		else if (ft_strchr("b", pelem->spec))
			string = ft_itoa_base(value, BIN, UNSIGNED);
		return (string);
	}
	return (ft_print_l_0_csprefg(pelem, ap));
}
