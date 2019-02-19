/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 23:34:10 by trhogoro          #+#    #+#             */
/*   Updated: 2019/01/09 23:34:11 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include "keys.h"
#include "libft.h"
#include "fractol.h"
#include <unistd.h>

static void	ft_start_init(t_params *p)
{
	p->height = MAX_HEIGHT;
	p->width = MAX_WIDTH;
	p->min_x = -2;
	p->max_x = 2;
	p->min_y = -2;
	p->max_y = 2;
	p->step_x = (p->max_x - p->min_x) / p->width;
	p->step_y = (p->max_y - p->min_y) / p->height;
	p->win = mlx_new_window(p->mlx, p->width, p->height, "Fractol");
	p->image = mlx_new_image(p->mlx, p->width, p->height);
	p->data = (int *)mlx_get_data_addr(p->image, &p->bpp, &p->sl, &p->endian);
	p->ctrl = 0;
}

static void	ft_init_params(t_params **p)
{
	int i;

	i = -1;
	((*p)[0]).mlx = mlx_init();
	while ((++i < 2) && (((*p)[i]).type))
	{
		((*p)[i]).mlx = ((*p)[0]).mlx;
		((*p)[i]).threads = ((*p)[0]).threads;
		ft_start_init(&((*p)[i]));
		if ((((*p)[i]).type >= T_JULIA && ((*p)[i]).type <= T_E_JULIA_3))
		{
			((*p)[i]).draw = draw_julia;
			((*p)[i]).cr = -0.8;
			((*p)[i]).ci = 0;
		}
		if ((((*p)[i]).type == T_JULIA_4) || (((*p)[i]).type == T_E_JULIA_4))
			((*p)[i]).draw = draw_julia4;
		if ((((*p)[i]).type == T_JULIA_3) || (((*p)[i]).type == T_E_JULIA_3))
			((*p)[i]).draw = draw_julia3;
		(((*p)[i]).type == T_MANDELBROT) ? ((*p)[i]).draw = draw_mandelbrot :
		(void)0;
		(((*p)[i]).type == T_BURN) ? ((*p)[i]).draw = draw_burning : (void)0;
		(((*p)[i]).type == T_NAUT) ? ((*p)[i]).draw = draw_nautilus : (void)0;
	}
}

int			main(int argc, char **argv)
{
	t_params *params;

	params = (t_params *)malloc(2 * sizeof(t_params));
	params[0].type = 0;
	params[1].type = 0;
	ft_collect_info(&params, argc, argv);
	ft_init_params(&params);
	gr_calculate(&params[0]);
	params[1].type ? gr_calculate(&params[1]) : (void)0;
	mlx_hook(params[0].win, 2, 0, key_press, &params[0]);
	mlx_hook(params[0].win, 3, 0, key_release, &params[0]);
	mlx_hook(params[0].win, 17, 0, exit_x, 0);
	mlx_hook(params[0].win, 4, 0, mouse_press, &params[0]);
	mlx_hook(params[0].win, 6, 0, mouse_move, &params[0]);
	if (params[1].type)
	{
		mlx_hook(params[1].win, 2, 0, key_press, &params[1]);
		mlx_hook(params[1].win, 3, 0, key_release, &params[1]);
		mlx_hook(params[1].win, 17, 0, exit_x, 0);
		mlx_hook(params[1].win, 4, 0, mouse_press, &params[1]);
		mlx_hook(params[1].win, 6, 0, mouse_move, &params[1]);
	}
	mlx_loop(params[0].mlx);
	return (0);
}
