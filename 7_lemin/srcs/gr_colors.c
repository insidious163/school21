/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gr_colors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrot <kcarrot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 16:20:24 by trhogoro          #+#    #+#             */
/*   Updated: 2019/02/07 23:11:25 by kcarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

int		gr_node_color(t_point3d *node)
{
	if (node->state == END_ROOM)
		return (C_FINISH);
	if (node->state == START_ROOM)
		return (C_START);
	return (C_NODE);
}

int		gr_line_color(t_params *params, t_line *line)
{
	int		a;
	int		b;
	t_path	*path;

	if (params->c.path == (int)params->set->num_of_paths)
		return (C_LINE);
	a = line->a->id;
	b = line->b->id;
	path = params->set->paths[params->c.path];
	while (path && path->next)
	{
		if (((path->room->id == a) && (path->next->room->id == b)) ||
			((path->room->id == b) && (path->next->room->id == a)))
			return (C_PATH);
		path = path->next;
	}
	return (C_LINE);
}
