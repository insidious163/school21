/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_pelem.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 23:31:13 by trhogoro          #+#    #+#             */
/*   Updated: 2018/12/23 02:34:56 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_check_flags(char *format, t_pelem *pelem)
{
	int	offset;
	int	index;

	offset = 0;
	while (*(format + offset) && ft_strchr(FLAGS, *(format + offset)))
	{
		index = (int)((ft_strchr(FLAGS, *(format + offset))) - FLAGS);
		pelem->flags[index] = 1;
		offset++;
	}
	if (pelem->flags[FLAG_43])
		pelem->flags[FLAG_32] = 0;
	return (offset);
}

int		ft_check_width(char *format, t_pelem *pelem, va_list *ap)
{
	int offset;

	offset = 0;
	if (*format == '*')
	{
		pelem->width = va_arg(*ap, int);
		return (1);
	}
	if (ft_isdigit(*format) && (*format != '0'))
	{
		pelem->width = 0;
		while (ft_isdigit(*(format + offset)))
		{
			pelem->width = pelem->width * 10 + *(format + offset) - '0';
			offset++;
		}
	}
	return (offset);
}

int		ft_check_precision(char *format, t_pelem *pelem, va_list *ap)
{
	int offset;

	if (*format != '.')
		return (0);
	pelem->precision = 0;
	offset = 1;
	if (*(format + offset) == '*')
	{
		pelem->precision = va_arg(*ap, int);
		return (2);
	}
	while (ft_isdigit(*(format + offset)))
	{
		pelem->precision = pelem->precision * 10 + *(format + offset) - '0';
		offset++;
	}
	return (offset);
}

int		ft_check_len_flag(char *format, t_pelem *pelem)
{
	char len;

	len = 0;
	if (*format)
	{
		(*format == 'h') ? len = L_H : (void)0;
		if ((*format == 'h') && (*(format + 1) == 'h'))
			len = L_HH;
		(*format == 'l') ? len = L_L : (void)0;
		if ((*format == 'l') && (*(format + 1) == 'l'))
			len = L_LL;
		if (*format == 'L')
			len = L_L_D;
		if (*format == 'j')
			len = L_J;
		if (*format == 'z')
			len = L_Z;
		if (len > pelem->length)
			pelem->length = len;
		if ((len == L_HH) || (len == L_LL))
			return (2);
		if (len != 0)
			return (1);
	}
	return (0);
}

int		ft_check_specificator(char *format, t_pelem *pelem)
{
	if (*format && ft_strchr(SPEC, *format))
	{
		pelem->spec = *format;
		ft_validate_pelem(pelem);
		return (1);
	}
	if (*format && ft_strchr(SPEC_UP, *format))
	{
		pelem->spec = (char)(*format + 'a' - 'A');
		if (pelem->length != L_LL)
			pelem->length = L_L;
		ft_validate_pelem(pelem);
		return (1);
	}
	return (0);
}
