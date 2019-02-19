/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 15:46:15 by trhogoro          #+#    #+#             */
/*   Updated: 2018/12/11 16:17:47 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

int		ft_print(int fd, const char *format, ...)
{
	va_list	ap;
	int		result;

	va_start(ap, format);
	result = ft_vprint(fd, (char *)format, &ap);
	va_end(ap);
	return (result);
}
