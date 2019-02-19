/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 15:43:15 by trhogoro          #+#    #+#             */
/*   Updated: 2018/12/20 04:03:28 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_vprint(int fd, char *format, va_list *ap)
{
	int	printed;
	int	offset;
	int	count;

	count = 0;
	printed = 0;
	while (format[count])
	{
		if (format[count] == '%')
		{
			if ((offset = ft_format(fd, format + count, &count, ap)) < 0)
				return (printed);
			printed += offset;
		}
		else
		{
			ft_putchar_fd(format[count++], fd);
			printed++;
		}
	}
	return (printed);
}
