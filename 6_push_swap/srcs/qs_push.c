/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qs_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 23:08:12 by trhogoro          #+#    #+#             */
/*   Updated: 2019/01/31 23:08:13 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static int	qs_push_b_loop(t_lst2 **st_a, t_lst2 **st_b, int i[5],
		t_list **push)
{
	t_lst2	*stack;

	stack = *st_a;
	while (i[I_I])
	{
		if (((t_info *)(stack->content))->id <= i[I_Y] &&
			((t_info *)(stack->content))->id >= i[I_X])
		{
			qs_rotate_n(st_a, ((int)ft_lst2len(*st_a) - i[I_R] < i[I_R]) ?
			i[I_R] - (int)ft_lst2len(*st_a) : i[I_R], STACK_A, push);
			qs_add_command(push, PB);
			ft_push(st_b, st_a);
			i[I_R] = 0;
			stack = *st_a;
			i[I_I]--;
		}
		else
		{
			i[I_R]++;
			i[I_RR]++;
			stack = stack->next;
		}
	}
	return (i[I_RR]);
}

t_list		*qs_push_b(t_lst2 **stack_a, t_lst2 **stack_b, int x, int y)
{
	int		i[5];
	t_list	*push;
	char	empty;

	push = 0x0;
	i[I_X] = x;
	i[I_Y] = y;
	i[I_R] = 0;
	i[I_RR] = 0;
	i[I_I] = y - x + 1;
	i[I_RR] = qs_push_b_loop(stack_a, stack_b, i, &push);
	empty = (*stack_b == 0x0);
	if (!empty)
		qs_rotate_n(stack_a, ((int)ft_lst2len(*stack_a) - i[I_RR] < i[I_RR])
		? (int)ft_lst2len(*stack_a) - i[I_RR] : -i[I_RR], STACK_A, &push);
	return (push);
}

static int	qs_push_a_loop(t_lst2 **st_a, t_lst2 **st_b, int i[5],
		t_list **push)
{
	t_lst2 *stack;

	stack = *st_b;
	while (i[I_I])
	{
		if (((t_info *)(stack->content))->id <= i[I_Y] &&
			((t_info *)(stack->content))->id >= i[I_X])
		{
			qs_rotate_n(st_b, ((int)ft_lst2len(*st_b) - i[I_R] < i[I_R]) ?
			i[I_R] - (int)ft_lst2len(*st_b) : i[I_R], STACK_B, push);
			qs_add_command(push, PA);
			ft_push(st_a, st_b);
			i[I_R] = 0;
			stack = *st_b;
			i[I_I]--;
		}
		else
		{
			i[I_R]++;
			i[I_RR]++;
			stack = stack->next;
		}
	}
	return (i[I_RR]);
}

t_list		*qs_push_a(t_lst2 **stack_a, t_lst2 **stack_b, int x, int y)
{
	t_list	*push;
	int		i[5];
	char	empty;

	push = 0x0;
	i[I_I] = y - x + 1;
	i[I_R] = 0;
	i[I_RR] = 0;
	i[I_X] = x;
	i[I_Y] = y;
	empty = (*stack_a == 0x0);
	i[I_RR] = qs_push_a_loop(stack_a, stack_b, i, &push);
	if (!empty)
		qs_rotate_n(stack_b, ((int)ft_lst2len(*stack_b) - i[I_RR] < i[I_RR]) ?
		(int)ft_lst2len(*stack_b) - i[I_RR] : -i[I_RR], STACK_B, &push);
	return (push);
}
