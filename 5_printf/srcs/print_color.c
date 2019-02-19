/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 00:53:19 by trhogoro          #+#    #+#             */
/*   Updated: 2018/12/20 03:44:48 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

static int	ft_change_color(int fd, int color)
{
	char	*str;
	size_t	len;
	char	*value;

	if (color >= 0)
	{
		len = ((color >= 100) ? 3 : (size_t)(color >= 10) + 1);
		len = len + ft_strlen(CLR_PREFIX) + ft_strlen(CLR_SUFFIX);
		if (!(str = (char *)malloc(len + 1)))
			return (-1);
		ft_strcpy(str, CLR_PREFIX);
		if (!(value = ft_ctoa_base((char)color, 10, 0)))
		{
			free(str);
			return (-1);
		}
		ft_strcat(str, value);
		free(value);
		ft_strcat(str, CLR_SUFFIX);
		ft_putstr_fd(str, fd);
		free(str);
		return ((int)len);
	}
	ft_putstr_fd(CLR_DEFAULT, fd);
	return (ft_strlen(CLR_DEFAULT));
}

static int	ft_is_it_color(int fd, char *format)
{
	char	c;
	int		color;

	c = *(format + 1);
	if ((c >= '0') && (c <= '9'))
		color = 16 * (c - '0');
	else if ((c >= 'A') && (c <= 'F'))
		color = 16 * (c - 'A' + 10);
	else
		return (-1);
	c = *(format + 2);
	if ((c >= '0') && (c <= '9'))
		color += (c - '0');
	else if ((c >= 'A') && (c <= 'F'))
		color += (c - 'A' + 10);
	else if ((color == 0) && (c == '}'))
		return (ft_change_color(fd, -1));
	else
		return (-1);
	if (*(format + 3) == '}')
		return (ft_change_color(fd, color));
	return (-1);
}

void		ft_check_color(int fd, char *format, int *count, int *printed)
{
	int offset;

	if ((offset = ft_is_it_color(fd, format + *count)) == -1)
	{
		ft_putchar_fd(format[*count], fd);
		(*count)++;
	}
	else
	{
		offset = (int)(ft_strlen(CLR_DEFAULT) ? (*count += 3) : (*count += 4));
		*printed += offset;
	}
}
