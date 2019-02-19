/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ll_fill_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 11:47:16 by trhogoro          #+#    #+#             */
/*   Updated: 2019/01/31 11:47:17 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static int	sr_get_ra(t_lst2 *stack_a, int *value)
{
	t_lst2	*temp;
	int		ra;

	if (((t_info *)stack_a->content)->to_remove == TRUE)
	{
		*value = ((t_info *)stack_a->content)->value;
		return (0);
	}
	ra = 1;
	temp = stack_a->next;
	while (temp != stack_a)
	{
		if (((t_info *)temp->content)->to_remove == TRUE)
		{
			*value = ((t_info *)temp->content)->value;
			return (ra);
		}
		ra++;
		temp = temp->next;
	}
	return (-1);
}

static int	sr_get_rb(t_lst2 *stack_b, int val)
{
	int		rb;
	t_lst2	*t;

	t = stack_b;
	if (((val < ((t_info *)t->content)->value) && (((((t_info *)t->content)->
		value < ((t_info *)t->prev->content)->value)) || (val >
		((t_info *)t->prev->content)->value))) || ((val > ((t_info *)t->prev->
		content)->value) && ((((t_info *)t->content)->value <
		((t_info *)t->prev->content)->value))))
		return (0);
	rb = 1;
	t = t->next;
	while (t != stack_b)
	{
		if (((val < ((t_info *)t->content)->value) && (((((t_info *)t->
			content)->value < ((t_info *)t->prev->content)->value)) ||
			(val > ((t_info *)t->prev->content)->value))) || ((val >
			((t_info *)t->prev->content)->value) && ((((t_info *)t->content)->
			value < ((t_info *)t->prev->content)->value))))
			return (rb);
		rb++;
		t = t->next;
	}
	return (-1);
}

void		ll_fill_b(t_lst2 **stack_a, t_lst2 **stack_b, t_list **commands)
{
	int		i[5];
	t_list	*push_elem;

	push_elem = 0x0;
	while (((i[IA] = sr_get_ra(*stack_a, &(i[VAL]))) >= 0))
	{
		i[LB] = (int)ft_lst2len(*stack_b);
		i[IB] = (i[LB] <= 1) ? 0 : sr_get_rb(*stack_b, (i[VAL]));
		if ((ll_i_mx(i[IA], i[IB]) < ll_i_mx((i[LA] = (int)ft_lst2len(*stack_a))
			- i[IA], i[LB] - i[IB])) && (ll_i_mx(i[IA], i[IB]) < ll_i_mn(i[LA]
			- i[IA] + i[IB], i[LB] - i[IB] + i[IA])))
			ll_add_rotations(&push_elem, i[IA], i[IB]);
		else if (ll_i_mx(i[LA] - i[IA], i[LB] - i[IB]) <
			ll_i_mn(i[LA] - i[IA] + i[IB], i[LB] - i[IB] + i[IA]))
			ll_add_rotations(&push_elem, -(i[LA] - i[IA]), -(i[LB] - i[IB]));
		else if (i[LA] - i[IA] + i[IB] < i[LB] - i[IB] + i[IA])
			ll_add_rotations(&push_elem, -(i[LA] - i[IA]), i[IB]);
		else
			ll_add_rotations(&push_elem, i[IA], -(i[LB] - i[IB]));
		ft_apply_commands(stack_a, stack_b, push_elem);
		ft_push(stack_b, stack_a);
		ft_lstradd(commands, push_elem);
		ft_lstradd(commands, ft_lstnew(PB, ft_strlen(PB) + 1));
		push_elem = 0x0;
	}
}
