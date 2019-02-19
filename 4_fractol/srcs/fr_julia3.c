/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_julia3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 11:20:55 by trhogoro          #+#    #+#             */
/*   Updated: 2019/01/17 11:20:56 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fractol.h"
#include <unistd.h>
#include "libft.h"

void	draw_julia3(t_params *params, int start_x, int finish_x)
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
			tmp = zr * zr * zr - 3 * zi * zi * zr;
			zi = 3 * zr * zr * zi - zi * zi * zi + params->ci;
			zr = tmp + params->cr;
			if (zr * zr + zi * zi > 4)
				break ;
		}
		params->data[i++] = params->color[d];
	}
}
