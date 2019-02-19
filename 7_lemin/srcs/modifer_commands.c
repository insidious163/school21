/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifer_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrot <kcarrot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 10:30:24 by kcarrot           #+#    #+#             */
/*   Updated: 2019/02/08 13:37:45 by kcarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_start_mod(t_farm *farm)
{
	char	*data;

	data = NULL;
	if (farm->start != NULL)
		ft_error_output(farm, "Double ##start modifer");
	get_next_line(0, &data);
	if (ft_is_comment(data))
		ft_error_output(farm, "After modifer must be valid line");
	if (ft_read_room(farm, data) != 3)
		ft_error_output(farm, "Wrong format for read room");
	farm->start = farm->rooms->name;
	farm->rooms->state = START_ROOM;
	free(data);
}

void	ft_end_mod(t_farm *farm)
{
	char	*data;

	data = NULL;
	if (farm->end != NULL)
		ft_error_output(farm, "Double ##end modifer");
	get_next_line(0, &data);
	if (ft_is_comment(data))
		ft_error_output(farm, "After modifer must be valid line");
	if (ft_read_room(farm, data) != 3)
		ft_error_output(farm, "Wrong format for read room");
	farm->end = farm->rooms->name;
	farm->rooms->state = END_ROOM;
	free(data);
}

void	ft_restart_mod(t_farm *farm)
{
	char	*data;
	t_room	*ptr;

	data = NULL;
	get_next_line(0, &data);
	if (ft_is_comment(data))
		ft_error_output(farm, "After modifer must be valid line");
	if (ft_read_room(farm, data) != 3)
		ft_error_output(farm, "Wrong format for read room");
	ptr = farm->rooms;
	while (ptr)
	{
		if (ptr->state == START_ROOM)
			ptr->state = 0;
		ptr = ptr->next;
	}
	farm->start = farm->rooms->name;
	farm->rooms->state = START_ROOM;
	free(data);
}

void	ft_reend_mod(t_farm *farm)
{
	char	*data;
	t_room	*ptr;

	data = NULL;
	get_next_line(0, &data);
	if (ft_is_comment(data))
		ft_error_output(farm, "After modifer must be valid line");
	if (ft_read_room(farm, data) != 3)
		ft_error_output(farm, "Wrong format for read room");
	ptr = farm->rooms;
	while (ptr)
	{
		if (ptr->state == END_ROOM)
			ptr->state = 0;
		ptr = ptr->next;
	}
	farm->end = farm->rooms->name;
	farm->rooms->state = END_ROOM;
	free(data);
}
