/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qs_sort_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 23:08:27 by trhogoro          #+#    #+#             */
/*   Updated: 2019/01/31 23:08:28 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static int	qs_first_step_sort_a(t_lst2 **stack_a, t_lst2 **stack_b,
		t_list **commands, t_xymini p)
{
	t_list *cmd;

	if (p.x == p.y)
		return (1);
	if (((t_info *)qs_elem_y(*stack_a, p.y - p.x)->content)->id == p.y)
	{
		p.y = p.y - 1;
		qs_sort_a(stack_a, stack_b, commands, p);
		return (1);
	}
	if (p.y - p.x < 3)
	{
		if ((cmd = qs_set_commmands1(qs_order(*stack_a, p.x, p.y), 0)))
		{
			ft_apply_commands(stack_a, stack_b, cmd);
			ft_lstradd(commands, cmd);
		}
	}
	else
		return (0);
	return (1);
}

static void	qs_less_than_8(t_lst2 **stack_a, t_lst2 **stack_b,
		t_list **commands, t_xymini p)
{
	int		t;
	t_list	*cmd;

	t = (p.y + p.x + 1) / 2;
	ft_lstradd(commands, qs_push_b(stack_a, stack_b, p.x, t - 1));
	cmd = qs_set_commands(qs_order(*stack_a, t, p.y),
		qs_order(*stack_b, p.x, t - 1), p.mini);
	ft_apply_commands(stack_a, stack_b, cmd);
	ft_lstradd(commands, cmd);
	ft_lstradd(commands, qs_push_a(stack_a, stack_b, p.x, t - 1));
}

void		qs_sort_a(t_lst2 **stack_a, t_lst2 **stack_b, t_list **commands,
			t_xymini p)
{
	int		t;
	int		x;

	if (qs_first_step_sort_a(stack_a, stack_b, commands, p))
		return ;
	if (p.y - p.x < 8)
	{
		qs_less_than_8(stack_a, stack_b, commands, p);
	}
	else
	{
		t = (p.y + p.x + 1) / 2;
		ft_lstradd(commands, qs_push_b(stack_a, stack_b, p.x, t - 1));
		x = p.x;
		p.x = t;
		qs_sort_a(stack_a, stack_b, commands, p);
		p.x = x;
		p.y = t - 1;
		qs_sort_b(stack_a, stack_b, commands, p);
		ft_lstradd(commands, qs_push_a(stack_a, stack_b, p.x, t - 1));
	}
}
