/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 02:16:17 by trhogoro          #+#    #+#             */
/*   Updated: 2019/01/31 02:23:15 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"
#include <unistd.h>
#include <stdio.h>

static void	ft_print_result(int error_num)
{
	if (error_num == E_SUCCESS)
		ft_putendl_fd("OK", 1);
	else if (error_num == E_KO)
		ft_putendl_fd("KO", 1);
	else
		ft_putendl_fd("Error", 2);
}

int			main(int ac, char **av)
{
	t_list	*cmd;
	t_lst2	*stack_a;
	t_lst2	*stack_b;
	int		options;

	stack_a = 0x0;
	stack_b = 0x0;
	if (!(cmd = 0x0) && (ac == 1))
		return (1);
	options = rd_options(ac, av, OPTIONS_CH);
	(1 & (options >> ('h' - 'a'))) ? wr_usage_checker() : (void)0;
	rd_init_stack_a(ac, av, &stack_a);
	(ft_lst_has_equals(stack_a)) ? er_error(E_PARAMS) : (void)0;
	(read_commands(0, &cmd) == E_ERROR) ? er_error(E_READING) : (void)0;
	((options >> ('v' - 'a')) & 1) ? gr_visual(stack_a, cmd) : (void)0;
	if ((options >> ('d' - 'a')) & 1)
		wr_debug(stack_a, cmd, (options >> ('c' - 'a')) & 1);
	else
	{
		ft_apply_commands(&stack_a, &stack_b, cmd);
		ft_print_result(ft_check_result(stack_a, stack_b));
	}
	ft_lst2del(&stack_a, ptr_stackdel);
	ft_lstdel(&cmd, ptr_lstdel);
	return (0);
}
