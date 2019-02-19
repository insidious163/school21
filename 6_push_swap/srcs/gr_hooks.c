/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gr_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 02:30:46 by trhogoro          #+#    #+#             */
/*   Updated: 2019/01/31 02:30:47 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "keys.h"
#include "push_swap.h"
#include <stdio.h>

int		exit_x(void)
{
	exit(0);
}

int		key_press(int keycode, t_param **params)
{
	if (keycode == KEY_ESC)
		exit_x();
	if ((*params)->cmd)
	{
		ft_apply_command(&((*params)->stack_a), &((*params)->stack_b),
				(char *)((*params)->cmd->content));
		gr_draw_picture((*params)->gr, (*params)->stack_a, (*params)->stack_b);
		(*params)->cmd = (*params)->cmd->next;
	}
	return (0);
}

int		mouse_move(int x, int y, t_param **params)
{
	(void)x;
	(void)y;
	if ((*params)->cmd)
	{
		ft_apply_command(&((*params)->stack_a), &((*params)->stack_b),
				(char *)((*params)->cmd->content));
		gr_draw_picture((*params)->gr, (*params)->stack_a, (*params)->stack_b);
		(*params)->cmd = (*params)->cmd->next;
	}
	return (0);
}
