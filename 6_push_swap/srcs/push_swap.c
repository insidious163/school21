/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 23:07:01 by trhogoro          #+#    #+#             */
/*   Updated: 2019/01/31 23:07:02 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

int		main(int ac, char **av)
{
	t_list	*cmd_ll;
	t_list	*cmd_qs;
	t_lst2	*stack_a;
	int		options;

	cmd_ll = 0x0;
	cmd_qs = 0x0;
	stack_a = 0x0;
	options = rd_options(ac, av, OPTIONS_PS);
	(ac == 1 || (1 & (options >> ('h' - 'a')))) ? wr_usage_push_swap() :
		(void)0;
	rd_init_stack_a(ac, av, &stack_a);
	(ft_lst_has_equals(stack_a)) ? er_error(E_PARAMS) : (void)0;
	qs_sort(ft_lst2cpy(stack_a), &cmd_qs);
	ll_sort(ft_lst2cpy(stack_a), &cmd_ll);
	ft_lst2del(&stack_a, ptr_stackdel);
	if ((options >> ('t' - 'a')) & 1)
		wr_type(cmd_ll, cmd_qs);
	ft_lstiter((ft_lstlen(cmd_ll) >= ft_lstlen(cmd_qs) ? cmd_qs : cmd_ll),
			ptr_lstprint);
	cl_clear(0x0, 0x0, &cmd_ll, &cmd_qs);
	return (0);
}
