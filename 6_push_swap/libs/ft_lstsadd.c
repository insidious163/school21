/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsadd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 02:15:20 by trhogoro          #+#    #+#             */
/*   Updated: 2019/01/31 02:15:30 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstsadd(t_list **alst, t_list *new,
		int (*cmp)(t_list *lst1, t_list *lst2))
{
	t_list *temp;

	if (!alst || !cmp)
		return ;
	if (!*alst)
	{
		*alst = new;
		return ;
	}
	temp = *alst;
	if (cmp(*alst, new) >= 0)
		return (ft_lstadd(alst, new));
	while (temp->next && cmp(temp->next, new) < 0)
		temp = temp->next;
	if (!temp->next)
		temp->next = new;
	else
	{
		new->next = temp->next;
		temp->next = new;
	}
}
