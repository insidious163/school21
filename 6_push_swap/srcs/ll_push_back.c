/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ll_push_back.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 11:47:51 by trhogoro          #+#    #+#             */
/*   Updated: 2019/01/31 11:47:52 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static char		is_good_position(t_lst2 *stack, int value)
{
	int	temp;
	int	prev;

	temp = ((t_info *)stack->content)->value;
	prev = ((t_info *)stack->prev->content)->value;
	if (((value < temp) && ((temp < prev) || (value > prev)))
		|| ((value > prev) && (temp < prev)))
		return (TRUE);
	return (FALSE);
}

static t_list	*sr_rotate_a_r(t_lst2 **stack_a, t_lst2 **stack_b)
{
	t_list	*result;
	int		len_a;
	int		value;
	int		ra;

	result = 0x0;
	while (*stack_b)
	{
		value = ((t_info *)(*stack_b)->content)->value;
		len_a = (int)ft_lst2len(*stack_a);
		ra = 0;
		while (is_good_position(*stack_a, value) == FALSE)
		{
			ra++;
			ft_rotate(stack_a, 0x0, 0);
		}
		ll_add_rotations(&result, (ra <= len_a - ra) ? ra : -(len_a - ra), 0);
		ft_lstradd(&result, ft_lstnew(PA, ft_strlen(PA) + 1));
		ft_push(stack_a, stack_b);
	}
	return (result);
}

void			ll_push_back(t_lst2 **stack_a, t_lst2 **stack_b,
		t_list **commands)
{
	t_list *back;

	if (!*stack_b)
		return ;
	back = sr_rotate_a_r(stack_a, stack_b);
	ft_lstradd(commands, back);
}
