/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 00:55:36 by trhogoro          #+#    #+#             */
/*   Updated: 2018/12/11 16:02:17 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	int		result;
	int		fd;

	fd = DEFAULT_FD;
	va_start(ap, format);
	result = ft_vprint(fd, (char *)format, &ap);
	va_end(ap);
	return (result);
}
