/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ll_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 11:47:32 by trhogoro          #+#    #+#             */
/*   Updated: 2019/01/31 11:47:33 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	ll_last_rotation(t_lst2 *stack_a, t_list **commands_ll)
{
	int	ra;
	int	len_a;

	ra = 0;
	while ((((t_info *)stack_a->content)->value) >
		((t_info *)stack_a->prev->content)->value)
	{
		ra++;
		ft_rotate(&stack_a, 0x0, 0);
	}
	len_a = (int)ft_lst2len(stack_a);
	ll_add_rotations(commands_ll, (ra <= len_a - ra) ? ra : -(len_a - ra), 0);
}

void	ll_sort(t_lst2 *stack_a, t_list **commands_ll)
{
	t_lst2	*stack_b;

	stack_b = 0x0;
	*commands_ll = 0x0;
	ll_find_max_line(stack_a);
	ll_fill_b(&stack_a, &stack_b, commands_ll);
	ll_push_back(&stack_a, &stack_b, commands_ll);
	rm_pa_pb(commands_ll);
	rm_rr_rrr(commands_ll);
	ll_last_rotation(stack_a, commands_ll);
	ft_lst2del(&stack_a, ptr_stackdel);
}
