/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst2cpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 02:09:43 by trhogoro          #+#    #+#             */
/*   Updated: 2019/01/31 02:10:17 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_lst2	*ft_lst2cpy(t_lst2 *lst2)
{
	t_lst2 *result;
	t_lst2 *tmp;

	if (!lst2)
		return (0x0);
	result = ft_lst2new(lst2->content, lst2->content_size);
	result->next = result;
	result->prev = result;
	tmp = lst2->next;
	while (tmp != lst2)
	{
		ft_lst2add_last(&result, ft_lst2new(tmp->content, tmp->content_size));
		tmp = tmp->next;
	}
	return (result);
}
