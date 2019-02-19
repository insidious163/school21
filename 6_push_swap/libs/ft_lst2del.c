/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst2del.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 02:08:25 by trhogoro          #+#    #+#             */
/*   Updated: 2019/01/31 02:09:18 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "unistd.h"

void	ft_lst2del(t_lst2 **lst2, void ptr_lstdel(void *content,
			size_t content_size))
{
	t_lst2 *temp;

	if (!lst2 || !*lst2)
		return ;
	while ((*lst2))
	{
		temp = (*lst2 == (*lst2)->next) ? 0x0 : (*lst2)->next;
		ft_lst2delone(lst2, ptr_lstdel);
		*lst2 = temp;
	}
}
