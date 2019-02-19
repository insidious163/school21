/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 22:52:36 by trhogoro          #+#    #+#             */
/*   Updated: 2019/01/09 22:52:37 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "libft.h"
#include "fractol.h"

void	draw_mandelbrot(t_params *params, int start_x, int finish_x)
{
	int		y;
	int		d;
	double	dbl[5];

	start_x -= 1;
	while (++start_x < finish_x)
	{
		dbl[P_CR] = params->min_x + params->step_x * start_x;
		y = -1;
		while (++y < params->height && (d = -1))
		{
			dbl[P_CI] = params->min_y + params->step_y * y;
			dbl[P_ZI] = 0;
			dbl[P_ZR] = 0;
			while (++d <= DEPTH)
			{
				dbl[P_TMP] = dbl[P_ZR] * dbl[P_ZR] - dbl[P_ZI] * dbl[P_ZI];
				dbl[P_ZI] = 2 * dbl[P_ZR] * dbl[P_ZI] + dbl[P_CI];
				dbl[P_ZR] = dbl[P_TMP] + dbl[P_CR];
				if (dbl[P_ZR] * dbl[P_ZR] + dbl[P_ZI] * dbl[P_ZI] > 4)
					break ;
			}
			params->data[start_x + y * params->width] = params->color[d];
		}
	}
}
