/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ll_find_max_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 11:47:23 by trhogoro          #+#    #+#             */
/*   Updated: 2019/01/31 11:47:26 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static int	sr_get_d(t_lst2 *last, t_lst2 *stack_a, int num)
{
	int	value;
	int	d;

	d = 1;
	value = ((t_info *)stack_a->content)->value;
	stack_a = stack_a->prev;
	while (stack_a != last)
	{
		if ((((t_info *)stack_a->content)->value < value) &&
			((t_info *)stack_a->content)->d[num] >= d)
			d = ((t_info *)stack_a->content)->d[num] + 1;
		stack_a = stack_a->prev;
	}
	return (d);
}

static void	sr_set_remove_flags(t_lst2 *stack_a, int num, int d)
{
	t_lst2	*temp;

	while (((t_info *)stack_a->content)->d[num] != d)
	{
		stack_a = stack_a->prev;
	}
	temp = stack_a;
	((t_info *)stack_a->content)->to_remove = FALSE;
	stack_a = stack_a->prev;
	d--;
	while (stack_a != temp)
	{
		if (((t_info *)stack_a->content)->d[num] == d)
		{
			((t_info *)stack_a->content)->to_remove = FALSE;
			d--;
		}
		else
			((t_info *)stack_a->content)->to_remove = TRUE;
		stack_a = stack_a->prev;
	}
}

static void	sr_max_line(t_lst2 *st_a, int *num, int *d)
{
	t_lst2	*s;
	int		max_d;

	s = st_a;
	((t_info *)s->content)->d[!*num] = 1;
	max_d = 1;
	st_a = st_a->next;
	while (st_a != s)
	{
		((t_info *)st_a->content)->d[!*num] = sr_get_d(s->prev, st_a, !*num);
		if (((t_info *)st_a->content)->d[!*num] > max_d)
			max_d++;
		st_a = st_a->next;
	}
	if (max_d > *d)
	{
		*d = max_d;
		*num = !*num;
	}
}

void		ll_find_max_line(t_lst2 *stack_a)
{
	int		len;
	t_lst2	*last;
	int		d;
	int		num;

	len = (int)ft_lst2len(stack_a);
	if (len <= 1)
		return ;
	num = FIRST;
	last = stack_a;
	d = 0;
	sr_max_line(stack_a, &num, &d);
	stack_a = stack_a->next;
	if (len < 500)
		while (stack_a != last)
		{
			sr_max_line(stack_a, &num, &d);
			stack_a = stack_a->next;
		}
	if (len != d)
		sr_set_remove_flags(stack_a, num, d);
}
