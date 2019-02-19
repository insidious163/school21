/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rd_read_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 02:15:02 by trhogoro          #+#    #+#             */
/*   Updated: 2019/02/01 02:15:03 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

static int	is_it_command(char *command)
{
	if ((ft_strequ(command, SA)) ||
		(ft_strequ(command, SB)) ||
		(ft_strequ(command, SS)) ||
		(ft_strequ(command, PA)) ||
		(ft_strequ(command, PB)) ||
		(ft_strequ(command, RA)) ||
		(ft_strequ(command, RB)) ||
		(ft_strequ(command, RR)) ||
		(ft_strequ(command, RRA)) ||
		(ft_strequ(command, RRB)) ||
		(ft_strequ(command, RRR)))
		return (1);
	return (0);
}

int			read_commands(int fd, t_list **commands)
{
	char *line;

	line = 0x0;
	while (ft_gnl(fd, &line))
	{
		if (is_it_command(line))
		{
			ft_lstradd(commands, ft_lstnew(line, ft_strlen(line) + 1));
			free(line);
		}
		else
		{
			free(line);
			ft_lstdel(commands, ptr_lstdel);
			return (E_ERROR);
		}
	}
	free(line);
	return (E_SUCCESS);
}
