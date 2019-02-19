/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_julia.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 22:52:44 by trhogoro          #+#    #+#             */
/*   Updated: 2019/01/09 22:52:45 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fractol.h"
#include <unistd.h>
#include "libft.h"

void	draw_julia(t_params *params, int start_x, int finish_x)
{
	int		d;
	double	tmp;
	double	zi;
	double	zr;
	int		i;

	i = start_x * params->height;
	while (i < finish_x * params->height - 1)
	{
		zr = params->min_x + params->step_x * (i % params->width);
		zi = params->min_y + params->step_y * (i / params->width);
		d = -1;
		while (++d <= DEPTH)
		{
			tmp = zr * zr - zi * zi;
			zi = 2 * zr * zi + params->ci;
			zr = tmp + params->cr;
			if (zr * zr + zi * zi > 4)
				break ;
		}
		params->data[i++] = params->color[d];
	}
}
