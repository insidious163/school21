/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gr_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrot <kcarrot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 16:38:55 by trhogoro          #+#    #+#             */
/*   Updated: 2019/02/07 23:41:16 by kcarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"
#include <mlx.h>

t_point3d	*gr_find_point(t_list *points, int id)
{
	while (points)
	{
		if (((t_point3d *)points->content)->id == id)
			return ((t_point3d *)points->content);
		points = points->next;
	}
	return (0x0);
}

t_list		*gr_collect_points(t_farm *farm)
{
	t_room		*rooms;
	t_list		*points;
	t_point3d	point;

	points = 0x0;
	rooms = farm->rooms;
	while (rooms)
	{
		point.state = rooms->state;
		point.id = rooms->id;
		point.x = rooms->x;
		point.y = rooms->y;
		point.z = 0;
		point.color = C_LINE;
		ft_lstadd(&points, ft_lstnew(&point, sizeof(point)));
		rooms = rooms->next;
	}
	return (points);
}

t_list		*gr_collect_lines(t_farm *farm, t_list *points)
{
	t_room	*rooms;
	t_list	*lines;
	int		i;
	t_line	line;

	lines = 0x0;
	rooms = farm->rooms;
	while (rooms)
	{
		i = 0;
		while (i < rooms->degree)
		{
			line.a = gr_find_point(points, rooms->id);
			line.b = gr_find_point(points, rooms->links[i++]->id);
			line.visible = 1;
			ft_lstadd(&lines, ft_lstnew(&line, sizeof(line)));
		}
		rooms = rooms->next;
	}
	return (lines);
}

void		gr_remove_double_line(t_list *lines)
{
	t_list *tmp;
	t_list *start;
	t_list *rmv;

	start = lines;
	tmp = start;
	while (start)
	{
		while (tmp->next)
		{
			if ((((t_line *)start->content)->a ==
				((t_line *)tmp->next->content)->b) &&
				(((t_line *)start->content)->b ==
				((t_line *)tmp->next->content)->a))
			{
				rmv = tmp->next;
				tmp->next = tmp->next->next;
				free(rmv);
				break ;
			}
			tmp = tmp->next;
		}
		start = start->next;
	}
}

t_params	*gr_init(t_farm *farm, t_ant **ants)
{
	t_params *params;

	params = (t_params *)malloc(sizeof(t_params));
	params->mlx = mlx_init();
	params->win = mlx_new_window(params->mlx, WIDTH, HEIGHT, "Lem in");
	params->width = WIDTH;
	params->height = HEIGHT;
	params->points = gr_collect_points(farm);
	params->lines = gr_collect_lines(farm, params->points);
	params->image = mlx_new_image(params->mlx, params->width, params->height);
	params->data = (int *)mlx_get_data_addr(params->image, &(params->bpp),
			&(params->sl), &(params->endian));
	params->c.type = P_PAR;
	params->moves = 0x0;
	params->ants = ants;
	gr_remove_double_line(params->lines);
	return (params);
}
