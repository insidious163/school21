/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gr_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 11:23:55 by trhogoro          #+#    #+#             */
/*   Updated: 2019/01/17 11:23:56 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_defaults(t_params *params)
{
	params->min_x = -2;
	params->max_x = 2;
	params->min_y = -2;
	params->max_y = 2;
	params->step_x = (params->max_x - params->min_x) / params->width;
	params->step_y = (params->max_y - params->min_y) / params->height;
}

double	ft_abs_d(double value)
{
	return (value < 0 ? -value : value);
}

int		is_visible(t_point pt_a, t_point pt_b, t_params *params)
{
	double	r2;

	r2 = 4 * ((pt_b.x - pt_a.x) * (pt_b.x - pt_a.x) +
		(pt_b.y - pt_a.y) * (pt_b.y - pt_a.y));
	if (pt_a.x <= params->max_x && pt_a.x >= params->min_x &&
		pt_a.y <= params->max_y && pt_a.y >= params->min_y)
		return (1);
	if ((pt_a.x <= params->max_x && pt_a.x >= params->min_x) &&
		((((pt_a.y - params->min_y) * (pt_a.y - params->min_y) <= r2) ||
		((pt_a.y - params->max_y) * (pt_a.y - params->max_y) <= r2))))
		return (1);
	if ((pt_a.y <= params->max_y && pt_a.y >= params->min_y) &&
		(((pt_a.x - params->min_x) * (pt_a.x - params->min_x) <= r2) ||
		((pt_a.x - params->max_x) * (pt_a.x - params->max_x) <= r2)))
		return (1);
	if (((pt_a.x - params->min_x) * (pt_a.x - params->min_x) +
		(pt_a.x - params->min_y) * (pt_a.x - params->min_y) <= r2) ||
		((pt_a.x - params->min_x) * (pt_a.x - params->min_x) +
		(pt_a.x - params->max_y) * (pt_a.x - params->max_y) <= r2) ||
		((pt_a.x - params->max_x) * (pt_a.x - params->max_x) +
		(pt_a.x - params->min_y) * (pt_a.x - params->min_y) <= r2) ||
		((pt_a.x - params->max_x) * (pt_a.x - params->max_x) +
		(pt_a.x - params->max_y) * (pt_a.x - params->max_y) <= r2))
		return (1);
	return (0);
}

void	ft_calc_ints(t_point *pt_a, t_point *pt_b, t_params *params)
{
	pt_a->xi = (int)((pt_a->x - params->min_x) / params->step_x);
	pt_a->yi = (int)((pt_a->y - params->min_y) / params->step_y);
	pt_b->xi = (int)((pt_b->x - params->min_x) / params->step_x);
	pt_b->yi = (int)((pt_b->y - params->min_y) / params->step_y);
}
