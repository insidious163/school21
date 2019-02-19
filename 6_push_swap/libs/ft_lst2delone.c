/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst2delone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 02:10:25 by trhogoro          #+#    #+#             */
/*   Updated: 2019/01/31 02:10:41 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include "unistd.h"

void	ft_lst2delone(t_lst2 **elem, void ptr_lstdel(void *content,
			size_t content_size))
{
	if (!elem || !*elem)
		return ;
	if ((*elem)->next != *elem)
	{
		(*elem)->next->prev = (*elem)->prev;
		(*elem)->prev->next = (*elem)->next;
	}
	if ((*elem)->content_size)
	{
		ptr_lstdel((*elem)->content, (*elem)->content_size);
	}
	free(*elem);
	*elem = 0x0;
}
