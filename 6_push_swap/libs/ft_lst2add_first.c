/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst2add_first.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 02:08:06 by trhogoro          #+#    #+#             */
/*   Updated: 2019/01/31 02:08:16 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst2add_first(t_lst2 **root, t_lst2 *elem)
{
	if (!root || !elem)
		return ;
	if (!*root)
	{
		elem->next = elem;
		elem->prev = elem;
		*root = elem;
	}
	else
	{
		elem->next = *root;
		elem->prev = (*root)->prev;
		elem->prev->next = elem;
		elem->next->prev = elem;
		*root = elem;
	}
}
