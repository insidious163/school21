/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 02:24:36 by trhogoro          #+#    #+#             */
/*   Updated: 2019/01/31 02:24:36 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_swap(t_lst2 **lst_a, t_lst2 **lst_b)
{
	int done;

	if ((done = (lst_a && *lst_a && (*lst_a)->next != (*lst_a))))
	{
		(*lst_a)->prev->next = (*lst_a)->next;
		(*lst_a)->next = (*lst_a)->next->next;
		(*lst_a)->next->prev->prev = (*lst_a)->prev;
		(*lst_a)->prev = (*lst_a)->prev->next;
		(*lst_a)->next->prev = *lst_a;
		(*lst_a)->prev->next = *lst_a;
		*lst_a = (*lst_a)->prev;
	}
	if (lst_b && *lst_b && (*lst_b)->next != (*lst_b))
	{
		(*lst_b)->prev->next = (*lst_b)->next;
		(*lst_b)->next = (*lst_b)->next->next;
		(*lst_b)->next->prev->prev = (*lst_b)->prev;
		(*lst_b)->prev = (*lst_b)->prev->next;
		(*lst_b)->next->prev = *lst_b;
		(*lst_b)->prev->next = *lst_b;
		*lst_b = (*lst_b)->prev;
		done = 1;
	}
	return (done);
}
