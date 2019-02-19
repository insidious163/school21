/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_l_l.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 00:14:45 by trhogoro          #+#    #+#             */
/*   Updated: 2018/12/23 02:25:13 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
#include <wchar.h>

static char		*ft_print_l_l_cs(t_pelem *pelem, va_list *ap)
{
	wchar_t		*ws;
	wchar_t		wc;
	char		*str;

	str = 0x0;
	if (pelem->spec == 'c')
	{
		wc = va_arg(*ap, wint_t);
		str = ft_utf8strint(wc);
		if (!str[0])
			pelem->length = L_0;
	}
	if (pelem->spec == 's')
	{
		ws = va_arg(*ap, wchar_t*);
		if (ws)
			str = ft_utf8strstr(ws);
		else
		{
			str = ft_memmove(ft_strnew(6), "(null)", 6);
			pelem->length = L_0;
		}
	}
	return (str);
}

static char		*ft_print_l_l_efgcs(t_pelem *pelem, va_list *ap)
{
	if (ft_strchr(SPEC_DBL, pelem->spec))
	{
		pelem->length = L_0;
		return (ft_print_l_0(pelem, ap));
	}
	else
		return (ft_print_l_l_cs(pelem, ap));
}

char			*ft_print_l_l(t_pelem *pelem, va_list *ap)
{
	long int	value;
	char		*string;

	string = 0x0;
	if (ft_strchr(SPEC_INT, pelem->spec))
	{
		value = va_arg(*ap, long int);
		if (ft_strchr("di", pelem->spec))
			string = ft_litoa_base(value, DEC, SIGNED);
		else if (ft_strchr("u", pelem->spec))
			string = ft_litoa_base(value, DEC, UNSIGNED);
		else if (ft_strchr("o", pelem->spec))
			string = ft_litoa_base(value, OCT, UNSIGNED);
		else if (ft_strchr("xX", pelem->spec))
			string = ft_litoa_base(value, HEX, UNSIGNED);
		else if (ft_strchr("b", pelem->spec))
			string = ft_litoa_base(value, BIN, UNSIGNED);
		return (string);
	}
	return (ft_print_l_l_efgcs(pelem, ap));
}
