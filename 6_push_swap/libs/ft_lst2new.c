/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst2new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 02:12:07 by trhogoro          #+#    #+#             */
/*   Updated: 2019/01/31 02:12:26 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_lst2	*ft_lst2new(void *content, size_t size)
{
	t_lst2 *elem;

	if (!(elem = (t_lst2 *)malloc(sizeof(t_lst2))))
		return (0x0);
	if (content && size)
	{
		if (!(elem->content = malloc(size)))
		{
			free(elem);
			return (0x0);
		}
		ft_memmove(elem->content, content, size);
		elem->content_size = size;
	}
	else
	{
		elem->content_size = 0;
		elem->content = 0x0;
	}
	elem->next = 0x0;
	elem->prev = 0x0;
	return (elem);
}
