/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qs_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 23:08:05 by trhogoro          #+#    #+#             */
/*   Updated: 2019/01/31 23:08:06 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include "push_swap.h"
#include "libft.h"

static void	qs_first_push(t_lst2 **stack_a, t_lst2 **stack_b, t_list **commands)
{
	int		x;
	t_lst2	*tmp;
	int		i;
	int		ra;

	tmp = *stack_a;
	x = (int)ft_lst2len(*stack_a) / 2;
	i = x;
	ra = 0;
	while (i)
		if (((t_info *)tmp->content)->id < x)
		{
			qs_rotate_n(stack_a, ((int)ft_lst2len(*stack_a) - ra < ra) ? ra -
				(int)ft_lst2len(*stack_a) : ra, STACK_A, commands);
			qs_add_command(commands, PB);
			ft_push(stack_b, stack_a);
			ra = 0;
			i--;
			tmp = *stack_a;
		}
		else
		{
			ra++;
			tmp = tmp->next;
		}
}

static void	qs_last_push(t_lst2 **stack_a, t_lst2 **stack_b, t_list **commands)
{
	while (*stack_b)
	{
		qs_add_command(commands, PA);
		ft_push(stack_a, stack_b);
	}
	rm_pa_pb(commands);
	rm_rr_rrr(commands);
}

static void	qs_minisort(t_lst2 **stack, t_list **commands_q, t_list *mini)
{
	int order;

	order = qs_order(*stack, 0, (int)ft_lst2len(*stack) - 1);
	*commands_q = qs_set_commands(order, 0, mini);
}

void		qs_sort(t_lst2 *stack_a, t_list **commands_q)
{
	t_lst2		*stack_b;
	t_list		*cmd;
	t_xymini	param;

	param.mini = qs_initialize_mini();
	cmd = 0x0;
	qs_initialize(&stack_a, &stack_b, commands_q, &cmd);
	if (ft_lst2len(stack_a) > 4)
	{
		qs_first_push(&stack_a, &stack_b, commands_q);
		param.x = (int)ft_lst2len(stack_b);
		param.y = (int)ft_lst2len(stack_a) + (int)ft_lst2len(stack_b) - 1;
		qs_sort_a(&stack_a, &stack_b, &cmd, param);
		ft_lstradd(commands_q, cmd);
		cmd = 0x0;
		param.x = 0;
		param.y = (int)ft_lst2len(stack_b) - 1;
		qs_sort_b(&stack_a, &stack_b, &cmd, param);
		ft_lstradd(commands_q, cmd);
		qs_last_push(&stack_a, &stack_b, commands_q);
	}
	else
		qs_minisort(&stack_a, commands_q, param.mini);
	ft_lstdel(&(param.mini), ptr_lstminidel);
	ft_lst2del(&stack_a, ptr_stackdel);
}
