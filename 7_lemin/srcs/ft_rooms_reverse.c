/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rooms_reverse.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrot <kcarrot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 14:36:25 by kcarrot           #+#    #+#             */
/*   Updated: 2019/02/08 10:29:55 by kcarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_rooms_reverse(t_room **rooms)
{
	t_room	*prev;
	t_room	*current;
	t_room	*next;

	if (rooms && *rooms)
	{
		prev = NULL;
		current = *rooms;
		next = NULL;
		while (current != NULL)
		{
			next = current->next;
			current->next = prev;
			prev = current;
			current = next;
		}
		*rooms = prev;
	}
}
