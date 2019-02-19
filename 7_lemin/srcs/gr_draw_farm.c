/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gr_draw_farm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 16:30:23 by trhogoro          #+#    #+#             */
/*   Updated: 2019/02/06 16:30:24 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "visual.h"

void	gr_draw_node(t_params *params)
{
	int		r;
	int		x;
	int		y;
	t_list	*tmp;

	r = (int)(params->c.sc[params->c.type] / 4);
	tmp = params->points;
	while (tmp)
	{
		x = -r - 1;
		while (++x < r)
		{
			y = -r - 1;
			while (++y < r)
			{
				if (x * x + y * y < r * r)
				{
					gr_plot(((t_point3d *)tmp->content)->xi + x,
							((t_point3d *)tmp->content)->yi + y,
							gr_node_color((t_point3d *)tmp->content), params);
				}
			}
		}
		tmp = tmp->next;
	}
}

void	gr_draw_farm(t_params *params)
{
	t_list	*temp;

	ft_memset(params->data, 0,
			(size_t)(params->width * params->height * 4 - 1));
	temp = params->lines;
	while (temp)
	{
		gr_draw_line(params, *(((t_line *)temp->content)->a),
				*(((t_line *)temp->content)->b),
				gr_line_color(params, ((t_line *)temp->content)));
		temp = temp->next;
	}
	gr_draw_node(params);
	if (params->c.iter != -1)
	{
		if (params->moves)
			gr_draw_move(params->moves, params->c.iter, params);
	}
	mlx_clear_window(params->mlx, params->win);
	mlx_put_image_to_window(params->mlx, params->win, params->image, 0, 0);
}
