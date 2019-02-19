/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 02:24:31 by trhogoro          #+#    #+#             */
/*   Updated: 2019/01/31 02:24:32 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_rotate(t_lst2 **lst_a, t_lst2 **lst_b, char reverse)
{
	int done;

	done = 0;
	if (!reverse)
	{
		if ((lst_a && *lst_a) || (lst_b && *lst_b))
			done = 1;
		if (lst_a && *lst_a)
			*lst_a = (*lst_a)->next;
		if (lst_b && *lst_b)
			*lst_b = (*lst_b)->next;
	}
	else
	{
		if ((lst_a && *lst_a) || (lst_b && *lst_b))
			done = 1;
		if (lst_a && *lst_a)
			*lst_a = (*lst_a)->prev;
		if (lst_b && *lst_b)
			*lst_b = (*lst_b)->prev;
	}
	return (done);
}
