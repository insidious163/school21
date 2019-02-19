/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gr_apply_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 15:56:51 by trhogoro          #+#    #+#             */
/*   Updated: 2019/02/06 15:56:52 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void	gr_set_colors(t_path *path, t_params *params)
{
	t_list		*points;
	t_path		*nodes;
	t_point3d	*point;

	points = params->points;
	while (points)
	{
		point = ((t_point3d *)points->content);
		point->color = C_LINE;
		if (path && (point->state == START_ROOM || point->state == END_ROOM))
			point->color = C_PATH;
		else
		{
			nodes = path;
			while (nodes)
			{
				if (nodes->room->id == point->id)
					point->color = C_PATH;
				nodes = nodes->next;
			}
		}
		points = points->next;
	}
}

void	gr_apply_color(t_params *params)
{
	t_path *path;

	params->c.path = (params->c.path) % ((int)params->set->num_of_paths + 1);
	path = params->c.path == (int)params->set->num_of_paths ? 0x0 :
			params->set->paths[params->c.path];
	gr_set_colors(path, params);
}
