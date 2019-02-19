/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wr_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 02:42:02 by trhogoro          #+#    #+#             */
/*   Updated: 2019/02/01 02:42:02 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void		ft_color_clean(t_lst2 *stack_a, t_lst2 *stack_b)
{
	t_lst2	*last_a;
	t_lst2	*last_b;

	if (stack_a)
	{
		last_a = stack_a->prev;
		((t_info *)last_a->content)->color = 0;
		while (stack_a != last_a)
		{
			((t_info *)stack_a->content)->color = 0;
			stack_a = stack_a->next;
		}
	}
	if (stack_b)
	{
		last_b = stack_b->prev;
		((t_info *)last_b->content)->color = 0;
		while (stack_b != last_b)
		{
			((t_info *)stack_b->content)->color = 0;
			stack_b = stack_b->next;
		}
	}
}

static void	ft_color_swap(t_lst2 *stack_a, t_lst2 *stack_b)
{
	if (stack_a)
	{
		((t_info *)stack_a->content)->color = 1;
		((t_info *)stack_a->next->content)->color = 1;
	}
	if (stack_b)
	{
		((t_info *)stack_b->content)->color = 1;
		((t_info *)stack_b->next->content)->color = 1;
	}
}

static void	ft_color_push(t_lst2 *to)
{
	if (to)
	{
		((t_info *)to->content)->color = 1;
	}
}

static void	ft_color_rotate(t_lst2 *stack_a, t_lst2 *stack_b, int reverse)
{
	if (stack_a)
		(reverse ? ((t_info *)stack_a->content) :
			((t_info *)stack_a->prev->content))->color = 1;
	if (stack_b)
		(reverse ? ((t_info *)stack_b->content) :
			((t_info *)stack_b->prev->content))->color = 1;
}

void		ft_apply_color(t_lst2 **stack_a, t_lst2 **stack_b, char *cmd)
{
	ft_color_clean(*stack_a, *stack_b);
	(ft_strequ(cmd, SA)) ? ft_color_swap(*stack_a, 0x0) : (void)0;
	(ft_strequ(cmd, SB)) ? ft_color_swap(0x0, *stack_b) : (void)0;
	(ft_strequ(cmd, SS)) ? ft_color_swap(*stack_a, *stack_b) : (void)0;
	(ft_strequ(cmd, PA)) ? ft_color_push(*stack_a) : (void)0;
	(ft_strequ(cmd, PB)) ? ft_color_push(*stack_b) : (void)0;
	(ft_strequ(cmd, RA)) ? ft_color_rotate(*stack_a, 0x0, 0) : (void)0;
	(ft_strequ(cmd, RB)) ? ft_color_rotate(0x0, *stack_b, 0) : (void)0;
	(ft_strequ(cmd, RR)) ? ft_color_rotate(*stack_a, *stack_b, 0) : (void)0;
	(ft_strequ(cmd, RRA)) ? ft_color_rotate(*stack_a, 0x0, 1) : (void)0;
	(ft_strequ(cmd, RRB)) ? ft_color_rotate(0x0, *stack_b, 1) : (void)0;
	(ft_strequ(cmd, RRR)) ? ft_color_rotate(*stack_a, *stack_b, 1) : (void)0;
}
