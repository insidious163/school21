/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 23:36:38 by trhogoro          #+#    #+#             */
/*   Updated: 2018/12/23 02:19:36 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

static void		ft_init_pelem(t_pelem *pelem)
{
	pelem->spec = 0;
	pelem->length = 0;
	pelem->width = 0;
	pelem->precision = DEFAULT_PRECISION;
	ft_memset(pelem->flags, 0, FLAGS_COUNT);
}

int				ft_apply_format(t_pelem pelem, char **value)
{
	if (!ft_strchr(SPEC_DBL, pelem.spec))
	{
		if (ft_apply_precision(pelem, value) ||
			ft_apply_flag35(pelem, value))
			return (-1);
	}
	if (ft_apply_flag32(pelem, value) ||
		ft_apply_flag43(pelem, value))
		return (-1);
	if (ft_strchr("XEG", pelem.spec))
		ft_strup(*value);
	return (ft_apply_width(pelem, value));
}

static char		*ft_value_to_print(t_pelem *pelem, va_list *ap)
{
	if (pelem->length == L_HH)
		return (ft_print_l_hh(*pelem, ap));
	if (pelem->length == L_H)
		return (ft_print_l_h(*pelem, ap));
	if (pelem->length == L_LL)
		return (ft_print_l_ll(*pelem, ap));
	if (pelem->length == L_L)
		return (ft_print_l_l(pelem, ap));
	if (pelem->length == L_L_D)
		return (ft_print_l_ldbl(*pelem, ap));
	if (pelem->length == L_Z)
		return (ft_print_l_z(*pelem, ap));
	if (pelem->length == L_J)
		return (ft_print_l_j(*pelem, ap));
	return (ft_print_l_0(pelem, ap));
}

static void		ft_read_pelem(t_pelem *pelem, int *offset, char *format,
		va_list *ap)
{
	int		l_offset;

	ft_init_pelem(pelem);
	*offset = 1;
	l_offset = 1;
	while (l_offset)
	{
		l_offset = 0;
		l_offset += ft_check_flags(format + l_offset + *offset, pelem);
		l_offset += ft_check_width(format + l_offset + *offset, pelem, ap);
		l_offset += ft_check_precision(format + l_offset + *offset, pelem, ap);
		l_offset += ft_check_len_flag(format + l_offset + *offset, pelem);
		*offset += l_offset;
		if (pelem->width < 0)
		{
			pelem->width = -(pelem->width);
			pelem->flags[FLAG_45] = 1;
		}
		if (pelem->precision < 0)
			pelem->precision = DEFAULT_PRECISION;
		if (pelem->precision != DEFAULT_PRECISION && pelem->precision != 0)
			pelem->flags[FLAG_48] = 0;
	}
}

int				ft_format(int fd, char *format, int *count, va_list *ap)
{
	t_pelem	pelem;
	int		offset;
	int		printed;
	char	*str;

	ft_read_pelem(&pelem, &offset, format, ap);
	if (!ft_check_specificator(format + offset, &pelem))
	{
		(!*(format + offset)) ? (*count) += offset : (void)0;
		if (!*(format + offset))
			return (0);
		pelem.spec = 'c';
		(str = ft_strnew(1)) ? ft_memmove(str, format + offset, 1) : (void)0;
	}
	else
		str = ft_value_to_print(&pelem, ap);
	offset++;
	if ((printed = ft_apply_format(pelem, &str)) > 0)
		((pelem.length == L_L) && (ft_strchr("cs", pelem.spec))) ?
		ft_utf8put_fd(str, fd) : ft_putnstr_fd(str, (size_t)printed, fd);
	(pelem.width >= 0) ? free(str) : (void)0;
	if (printed < 0)
		return (-1);
	*count += offset;
	return (printed);
}
