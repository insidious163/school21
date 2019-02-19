/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 02:24:14 by trhogoro          #+#    #+#             */
/*   Updated: 2019/01/31 02:24:23 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_set_elem(t_lst2 **elem, t_lst2 *lst_to)
{
	if (!lst_to)
	{
		(*elem)->next = *elem;
		(*elem)->prev = *elem;
	}
	else
	{
		(*elem)->next = lst_to;
		(*elem)->prev = lst_to->prev;
	}
}

int			ft_push(t_lst2 **lst_to, t_lst2 **lst_from)
{
	t_lst2 *elem;

	if (!lst_to || !lst_from || !*lst_from)
		return (0);
	elem = *lst_from;
	if ((*lst_from)->next == *lst_from)
		*lst_from = 0x0;
	else
	{
		(*lst_from)->next->prev = (*lst_from)->prev;
		(*lst_from)->prev->next = (*lst_from)->next;
		*lst_from = (*lst_from)->next;
	}
	ft_set_elem(&elem, *lst_to);
	elem->next->prev = elem;
	elem->prev->next = elem;
	*lst_to = elem;
	return (1);
}
