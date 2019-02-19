/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_rbt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 23:05:03 by trhogoro          #+#    #+#             */
/*   Updated: 2019/01/31 23:05:04 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int		ptr_rbtcmp(t_rbtree *node1, t_rbtree *node2)
{
	int value1;
	int value2;

	value1 = ((t_info *)node1->content)->value;
	value2 = ((t_info *)node2->content)->value;
	if (value1 > value2)
		return (1);
	else if (value1 < value2)
		return (-1);
	return (0);
}

void	ptr_setid(t_rbtree *elem, void *param)
{
	((t_info *)elem->content)->id = *(unsigned int *)param;
	(*(unsigned int *)param)++;
}

void	ptr_rbtdel(t_rbtree *elem)
{
	(void)elem;
}
