/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_koch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 11:21:12 by trhogoro          #+#    #+#             */
/*   Updated: 2019/01/17 11:21:13 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

void	draw_koch(t_params *params, t_point pt_a, t_point pt_b, int depth)
{
	t_point c;
	t_point d;
	t_point e;

	if (is_visible(pt_a, pt_b, params) || is_visible(pt_b, pt_a, params))
	{
		ft_calc_ints(&pt_a, &pt_b, params);
		if (((pt_a.xi < pt_b.xi - 1) || (pt_a.xi > pt_b.xi + 1) ||
			(pt_a.yi < pt_b.yi - 1) || (pt_a.yi > pt_b.yi + 1)))
		{
			gr_draw_line(params, pt_a, pt_b, params->color[depth]);
			if (depth > DEPTH)
				return ;
			c.x = (2 * pt_a.x + pt_b.x) / 3;
			c.y = (2 * pt_a.y + pt_b.y) / 3;
			e.x = (pt_a.x + 2 * pt_b.x) / 3;
			e.y = (pt_a.y + 2 * pt_b.y) / 3;
			d.x = c.x + (e.x - c.x) / 2 - (e.y - c.y) * sqrt(3) / 2;
			d.y = c.y + (e.x - c.x) * sqrt(3) / 2 + (e.y - c.y) / 2;
			draw_koch(params, pt_a, c, depth + 1);
			draw_koch(params, c, d, depth + 1);
			draw_koch(params, d, e, depth + 1);
			draw_koch(params, e, pt_b, depth + 1);
		}
	}
}
