/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_dragon.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 11:21:36 by trhogoro          #+#    #+#             */
/*   Updated: 2019/01/17 11:21:38 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fractol.h"
#include <unistd.h>
#include "libft.h"
#include <math.h>

void	draw_dragon(t_params *params, t_point pt_a, t_point pt_b, int depth)
{
	t_point	pt_c;

	if (is_visible(pt_a, pt_b, params) ||
		is_visible(pt_b, pt_a, params))
	{
		ft_calc_ints(&pt_a, &pt_b, params);
		if (((pt_a.xi < pt_b.xi - 1) || (pt_a.xi > pt_b.xi + 1) ||
			(pt_a.yi < pt_b.yi - 1) || (pt_a.yi > pt_b.yi + 1)))
		{
			gr_draw_line(params, pt_a, pt_b, params->color[depth]);
			if (depth < DEPTH)
			{
				pt_c.x = ((pt_b.x - pt_a.x) - (pt_b.y - pt_a.y)) / 2 + pt_a.x;
				pt_c.y = ((pt_b.x - pt_a.x) + (pt_b.y - pt_a.y)) / 2 + pt_a.y;
				draw_dragon(params, pt_a, pt_c, depth + 1);
				draw_dragon(params, pt_b, pt_c, depth + 1);
			}
		}
	}
}
