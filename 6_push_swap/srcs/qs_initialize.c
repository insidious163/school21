/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qs_initialize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 23:08:00 by trhogoro          #+#    #+#             */
/*   Updated: 2019/01/31 23:08:01 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>
#include "push_swap.h"
#include <stdlib.h>

static void	qs_add_mini_elem(t_list **mini, char **line)
{
	char	*tmp;
	t_mini	elem;

	tmp = *line;
	elem.order_a = ft_atoi(tmp);
	while (*tmp != ' ')
		tmp++;
	tmp++;
	elem.order_b = ft_atoi(tmp);
	while (*tmp && (*tmp != ' '))
		tmp++;
	elem.cmd = ft_strdup(tmp);
	ft_lstadd(mini, ft_lstnew(&elem, sizeof(elem)));
	free(*line);
	*line = 0x0;
}

t_list		*qs_initialize_mini(void)
{
	int		fd;
	char	*line;
	int		gnl;
	t_list	*mini;

	mini = 0x0;
	fd = open(MINI_FILE, O_RDONLY);
	if (fd < 0)
		er_error(E_READING);
	while ((gnl = ft_gnl(fd, &line)) > 0)
		qs_add_mini_elem(&mini, &line);
	free(line);
	if (gnl < 0)
		er_error(E_READING);
	return (mini);
}

static void	qs_set_id(t_lst2 *stack)
{
	t_lst2		*last;
	t_rbtree	*rbt;
	int			i;

	i = 0;
	last = stack;
	rbt = 0x0;
	ft_rbtadd(&rbt, ft_rbt_c_new(stack->content, stack->content_size),
			ptr_rbtcmp);
	stack = stack->next;
	while (stack != last)
	{
		ft_rbtadd(&rbt, ft_rbt_c_new(stack->content, stack->content_size),
				ptr_rbtcmp);
		stack = stack->next;
	}
	ft_rbtforeach_p(rbt, ptr_setid, INFIX, &i);
	ft_rbtclr(&rbt, ptr_rbtdel);
}

void		qs_initialize(t_lst2 **stack_a, t_lst2 **stack_b,
				t_list **commands_q, t_list **cmd)
{
	qs_set_id(*stack_a);
	*stack_b = 0x0;
	*commands_q = 0x0;
	*cmd = 0x0;
}
