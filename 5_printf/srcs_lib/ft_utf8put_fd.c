/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pututf8_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 02:17:28 by trhogoro          #+#    #+#             */
/*   Updated: 2018/12/23 02:17:53 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_utf8put_fd(char const *str, int fd)
{
	while (*str)
	{
		if ((*str & 0xF0) == 0xE0)
		{
			write(fd, str, 3);
			str += 3;
		}
		else if ((*str & 0xE0) == 0xC0)
		{
			write(fd, str, 2);
			str += 2;
		}
		else
		{
			write(fd, str, 1);
			str++;
		}
	}
}
