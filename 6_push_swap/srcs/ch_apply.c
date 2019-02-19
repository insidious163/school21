/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_apply.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 02:16:10 by trhogoro          #+#    #+#             */
/*   Updated: 2019/01/31 02:18:37 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	ft_lst_has_equals(t_lst2 *stack_a)
{
	t_list	*sorted;
	t_lst2	*last;
	t_list	*temp;
	int		result;

	sorted = 0x0;
	if (stack_a == stack_a->next)
		return (0);
	last = stack_a->prev;
	while (stack_a != last)
	{
		ft_lstsadd(&sorted, ft_lstnew(stack_a->content, stack_a->content_size),
				ptr_valuecmp);
		stack_a = stack_a->next;
	}
	temp = sorted;
	result = 0;
	while (temp && temp->next)
	{
		if (!ptr_valuecmp(temp, temp->next))
			result = 1;
		temp = temp->next;
	}
	ft_lstdel(&sorted, ptr_lstdel);
	return (result);
}

int	ft_check_result(t_lst2 *stack_a, t_lst2 *stack_b)
{
	t_lst2 *last;

	if (stack_b)
		return (E_KO);
	last = stack_a->prev;
	if (stack_a->next == stack_a)
		return (E_SUCCESS);
	while (stack_a != last)
	{
		if ((*(int*)stack_a->content) > (*(int*)stack_a->next->content))
			return (E_KO);
		stack_a = stack_a->next;
	}
	return (E_SUCCESS);
}

int	ft_apply_command(t_lst2 **stack_a, t_lst2 **stack_b, char *cmd)
{
	int done;

	done = 0;
	(ft_strequ(cmd, SA)) ? done = ft_swap(stack_a, 0x0) : (void)0;
	(ft_strequ(cmd, SB)) ? done = ft_swap(0x0, stack_b) : (void)0;
	(ft_strequ(cmd, SS)) ? done = ft_swap(stack_a, stack_b) : (void)0;
	(ft_strequ(cmd, PA)) ? done = ft_push(stack_a, stack_b) : (void)0;
	(ft_strequ(cmd, PB)) ? done = ft_push(stack_b, stack_a) : (void)0;
	(ft_strequ(cmd, RA)) ? done = ft_rotate(stack_a, 0x0, 0) : (void)0;
	(ft_strequ(cmd, RB)) ? done = ft_rotate(0x0, stack_b, 0) : (void)0;
	(ft_strequ(cmd, RR)) ? done = ft_rotate(stack_a, stack_b, 0) : (void)0;
	(ft_strequ(cmd, RRA)) ? done = ft_rotate(stack_a, 0x0, 1) : (void)0;
	(ft_strequ(cmd, RRB)) ? done = ft_rotate(0x0, stack_b, 1) : (void)0;
	(ft_strequ(cmd, RRR)) ? done = ft_rotate(stack_a, stack_b, 1) : (void)0;
	return (done);
}

int	ft_apply_commands(t_lst2 **stack_a, t_lst2 **stack_b, t_list *commands)
{
	char *cmd;

	if (!stack_a || !stack_b)
		return (E_PARAMS);
	while (commands)
	{
		cmd = (char *)commands->content;
		ft_apply_command(stack_a, stack_b, cmd);
		commands = commands->next;
	}
	return (ft_check_result(*stack_a, *stack_b));
}
