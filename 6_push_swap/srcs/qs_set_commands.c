/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qs_set_commands.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 23:08:20 by trhogoro          #+#    #+#             */
/*   Updated: 2019/01/31 23:08:21 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "push_swap.h"

static char	*qs_minisort(int order_a, int order_b, t_list *qs_mini)
{
	while (qs_mini)
	{
		if ((((t_mini *)qs_mini->content)->order_a == order_a)
			&& (((t_mini *)qs_mini->content)->order_b == order_b))
			return (((t_mini *)qs_mini->content)->cmd);
		qs_mini = qs_mini->next;
	}
	return (0x0);
}

static char	**qs_get_cmds(int order_a, int order_b)
{
	char	**cmds;

	cmds = 0x0;
	if (!order_a)
	{
		order_b == 123 ? cmds = ft_strsplit("sb rb sb rrb sb", ' ') : (void)0;
		order_b == 132 ? cmds = ft_strsplit("sb rb sb rrb", ' ') : (void)0;
		order_b == 213 ? cmds = ft_strsplit("rb sb rrb sb", ' ') : (void)0;
		order_b == 231 ? cmds = ft_strsplit("sb", ' ') : (void)0;
		order_b == 312 ? cmds = ft_strsplit("rb sb rrb", ' ') : (void)0;
		order_b == 12 ? cmds = ft_strsplit("sb", ' ') : (void)0;
	}
	else
	{
		order_a == 21 ? cmds = ft_strsplit("sa", ' ') : (void)0;
		order_a == 132 ? cmds = ft_strsplit("ra sa rra", ' ') : (void)0;
		order_a == 213 ? cmds = ft_strsplit("sa", ' ') : (void)0;
		order_a == 231 ? cmds = ft_strsplit("ra sa rra sa", ' ') : (void)0;
		order_a == 312 ? cmds = ft_strsplit("sa ra sa rra", ' ') : (void)0;
		order_a == 321 ? cmds = ft_strsplit("sa ra sa rra sa", ' ') : (void)0;
	}
	return (cmds);
}

t_list		*qs_set_commmands1(int order_a, int order_b)
{
	char	**cmds;
	t_list	*result;
	int		i;

	cmds = qs_get_cmds(order_a, order_b);
	result = 0x0;
	i = 0;
	while (cmds && cmds[i])
	{
		qs_add_command(&result, cmds[i]);
		free(cmds[i++]);
	}
	(cmds) ? free(cmds) : (void)0;
	return (result);
}

t_list		*qs_set_commands(int order_a, int order_b, t_list *mini)
{
	char	*str;
	char	**cmds;
	int		i;
	t_list	*result;

	str = qs_minisort(order_a, order_b, mini);
	cmds = ft_strsplit(str, ' ');
	result = 0x0;
	i = 0;
	while (cmds && cmds[i])
	{
		qs_add_command(&result, cmds[i]);
		free(cmds[i++]);
	}
	cmds ? free(cmds) : (void)0;
	return (result);
}

int			qs_order(t_lst2 *stack_a, int x, int y)
{
	int i;
	int order;

	order = 0;
	i = y - x + 1;
	while (i--)
	{
		order = order * 10 + ((t_info *)stack_a->content)->id - x + 1;
		stack_a = stack_a->next;
	}
	return (order);
}
