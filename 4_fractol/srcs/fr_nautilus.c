/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_nautilus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 11:21:20 by trhogoro          #+#    #+#             */
/*   Updated: 2019/01/17 11:21:21 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fractol.h"

static void	draw_elem(t_params *params, double dbl[9], int start_x, int y)
{
	int d;

	d = -1;
	while (++d <= DEPTH / 4)
	{
		if (dbl[P_CR] <= dbl[P_XMAX] && dbl[P_CR] >= dbl[P_XMIN] &&
			dbl[P_CI] >= dbl[P_YMIN] && dbl[P_CI] <= dbl[P_YMAX])
			params->data[start_x + y * params->width] += 1;
		dbl[P_XMIN] = (dbl[P_XMAX] + dbl[P_XMIN]) / 2;
		if (dbl[P_CR] <= dbl[P_XMAX] && dbl[P_CR] >= dbl[P_XMIN] &&
			dbl[P_CI] >= dbl[P_YMIN] && dbl[P_CI] <= dbl[P_YMAX])
			params->data[start_x + y * params->width] += 1;
		dbl[P_YMIN] = (dbl[P_YMAX] + dbl[P_YMIN]) / 2;
		if (dbl[P_CR] <= dbl[P_XMAX] && dbl[P_CR] >= dbl[P_XMIN] &&
			dbl[P_CI] >= dbl[P_YMIN] && dbl[P_CI] <= dbl[P_YMAX])
			params->data[start_x + y * params->width] += 1;
		dbl[P_XMAX] = (dbl[P_XMAX] + dbl[P_XMIN]) / 2;
		if (dbl[P_CR] <= dbl[P_XMAX] && dbl[P_CR] >= dbl[P_XMIN] &&
			dbl[P_CI] >= dbl[P_YMIN] && dbl[P_CI] <= dbl[P_YMAX])
			params->data[start_x + y * params->width] += 1;
		dbl[P_YMAX] = (dbl[P_YMAX] + dbl[P_YMIN]) / 2;
		if (dbl[P_CR] <= dbl[P_XMAX] && dbl[P_CR] >= dbl[P_XMIN] &&
			dbl[P_CI] >= dbl[P_YMIN] && dbl[P_CI] <= dbl[P_YMAX])
			params->data[start_x + y * params->width] += 1;
	}
}

void		draw_nautilus(t_params *params, int start_x, int finish_x)
{
	int		y;
	double	dbl[9];

	start_x -= 1;
	while (++start_x < finish_x)
	{
		dbl[P_CR] = params->min_x + params->step_x * start_x;
		y = -1;
		while (++y < params->height)
		{
			params->data[start_x + y * params->width] = 0;
			dbl[P_CI] = params->min_y + params->step_y * y;
			dbl[P_XMIN] = -2;
			dbl[P_XMAX] = 2;
			dbl[P_YMIN] = -2;
			dbl[P_YMAX] = 2;
			draw_elem(params, dbl, start_x, y);
			params->data[start_x + y * params->width] =
				params->color[params->data[start_x + y * params->width]];
		}
	}
}
