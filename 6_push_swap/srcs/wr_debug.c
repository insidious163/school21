/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wr_debug.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 02:42:07 by trhogoro          #+#    #+#             */
/*   Updated: 2019/02/01 02:42:08 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <unistd.h>

static void	ft_print_value(int val, int is_color)
{
	char	field[15];
	int		i;
	char	minus;

	minus = (val < 0);
	ft_memset(field, ' ', 14);
	i = 14;
	field[14] = '\0';
	field[13] = '0';
	while (i--)
	{
		if (val)
		{
			field[i] = (char)('0' + (val < 0 ? -(val % 10) : (val % 10)));
			val = val / 10;
		}
		else if (minus)
		{
			field[i] = '-';
			minus = 0;
		}
	}
	is_color ? write(1, PRINT_RED, ft_strlen(PRINT_RED)) : (void)0;
	ft_putstr(field);
	is_color ? write(1, PRINT_ZERO, ft_strlen(PRINT_ZERO)) : (void)0;
}

static void	ft_debug(t_lst2 *stack_a, t_lst2 *stack_b, char *cmd)
{
	t_lst2	*start_a;
	t_lst2	*start_b;
	char	space[15];

	cmd ? ft_putendl(cmd) : ft_putendl("START");
	ft_memset(space, ' ', 14);
	space[14] = '\0';
	start_a = stack_a;
	start_b = stack_b;
	while (stack_a || stack_b)
	{
		stack_a ? ft_print_value(((t_info *)stack_a->content)->value,
				((t_info *)stack_a->content)->color) : ft_putstr(space);
		stack_b ? ft_print_value(((t_info *)stack_b->content)->value,
				((t_info *)stack_b->content)->color) : ft_putstr(space);
		ft_putchar('\n');
		stack_a = stack_a ? stack_a->next : 0x0;
		stack_b = stack_b ? stack_b->next : 0x0;
		(start_a == stack_a) ? stack_a = 0x0 : (void)0;
		(start_b == stack_b) ? stack_b = 0x0 : (void)0;
	}
	ft_putchar('\n');
}

void		wr_debug(t_lst2 *stack_a, t_list *cmd, int is_color)
{
	t_lst2	*stack_b;
	int		done;

	stack_b = 0x0;
	ft_color_clean(stack_a, 0x0);
	ft_debug(stack_a, 0x0, 0x0);
	while (cmd)
	{
		done = ft_apply_command(&stack_a, &stack_b, (char *)cmd->content);
		(is_color && done) ?
			ft_apply_color(&stack_a, &stack_b, (char *)cmd->content) : (void)0;
		ft_debug(stack_a, stack_b, (char *)cmd->content);
		cmd = cmd->next;
	}
}
