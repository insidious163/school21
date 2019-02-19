/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst2len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 02:10:53 by trhogoro          #+#    #+#             */
/*   Updated: 2019/01/31 02:11:56 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_lst2len(t_lst2 *lst)
{
	t_lst2	*last;
	size_t	len;

	if (!lst)
		return (0);
	last = lst;
	len = 1;
	while (lst->next != last)
	{
		len++;
		lst = lst->next;
	}
	return (len);
}
