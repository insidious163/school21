/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qs_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 23:08:49 by trhogoro          #+#    #+#             */
/*   Updated: 2019/01/31 23:08:50 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void			qs_add_command(t_list **commands, char *cmd)
{
	ft_lstradd(commands, ft_lstnew(cmd, ft_strlen(cmd) + 1));
}

static void		qs_rotate_na(t_lst2 **stack, int n, t_list **commands)
{
	if (n < 0)
		while (n++)
		{
			qs_add_command(commands, RRA);
			ft_rotate(stack, 0x0, 1);
		}
	else
		while (n--)
		{
			qs_add_command(commands, RA);
			ft_rotate(stack, 0x0, 0);
		}
}

static void		qs_rotate_nb(t_lst2 **stack, int n, t_list **commands)
{
	if (n < 0)
		while (n++)
		{
			qs_add_command(commands, RRB);
			ft_rotate(0x0, stack, 1);
		}
	else
		while (n--)
		{
			qs_add_command(commands, RB);
			ft_rotate(0x0, stack, 0);
		}
}

void			qs_rotate_n(t_lst2 **stack, int n, int stack_id,
		t_list **commands)
{
	if (n)
	{
		if (stack_id == STACK_A)
			qs_rotate_na(stack, n, commands);
		else
			qs_rotate_nb(stack, n, commands);
	}
}

t_lst2			*qs_elem_y(t_lst2 *stack, int i)
{
	while (i--)
	{
		stack = stack->next;
	}
	return (stack);
}
