/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrot <kcarrot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 10:28:16 by kcarrot           #+#    #+#             */
/*   Updated: 2019/02/08 13:51:47 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static	void	ft_free_room(t_room *room)
{
	free(room->name);
	free(room->links);
	free(room);
}

void			ft_room_delete(t_room **rooms, t_room *room)
{
	t_room	*prev;

	if (rooms && *rooms && room)
	{
		if (*rooms == room)
		{
			*rooms = (*rooms)->next;
			ft_free_room(room);
		}
		else
		{
			prev = *rooms;
			while (prev->next != room)
				prev = prev->next;
			if (prev == NULL)
				return ;
			prev->next = room->next;
			free(room);
		}
	}
}

void			ft_rooms_destroyer(t_room **room)
{
	t_room	*tmp;

	if (room && *room)
	{
		while (*room)
		{
			tmp = (*room)->next;
			ft_free_room(*room);
			*room = tmp;
		}
		*room = NULL;
	}
}

void			ptr_del(void *content, size_t size)
{
	if (size)
		free(content);
}

void			ft_farm_destroyer(t_farm *farm)
{
	if (farm)
	{
		if (farm->rooms)
			ft_rooms_destroyer(&(farm->rooms));
		if (farm->ants)
			free(farm->ants);
		ft_lstdel(&(farm->output), ptr_del);
		free(farm);
	}
}
