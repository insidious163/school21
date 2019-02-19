/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gr_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 23:13:02 by trhogoro          #+#    #+#             */
/*   Updated: 2019/01/09 23:13:03 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdlib.h>
#include "keys.h"

int		exit_x(void)
{
	exit(0);
}

int		key_press(int keycode, t_params *params)
{
	double move;

	if (keycode == KEY_ESC)
		exit_x();
	if ((keycode == KEY_UP) || (keycode == KEY_DOWN))
		move = (params->max_y - params->min_y) / 5;
	if ((keycode == KEY_LEFT) || (keycode == KEY_RIGHT))
		move = (params->max_x - params->min_x) / 5;
	(keycode == KEY_DOWN) ? params->min_y -= move : (void)0;
	(keycode == KEY_DOWN) ? params->max_y -= move : (void)0;
	(keycode == KEY_UP) ? params->min_y += move : (void)0;
	(keycode == KEY_UP) ? params->max_y += move : (void)0;
	(keycode == KEY_RIGHT) ? params->min_x -= move : (void)0;
	(keycode == KEY_RIGHT) ? params->max_x -= move : (void)0;
	(keycode == KEY_LEFT) ? params->min_x += move : (void)0;
	(keycode == KEY_LEFT) ? params->max_x += move : (void)0;
	(keycode == KEY_CTRL_L) ? params->ctrl = 1 : (void)0;
	(keycode == KEY_SPACE) ? set_defaults(params) : (void)0;
	gr_calculate(params);
	return (0);
}

int		key_release(int keycode, t_params *params)
{
	(keycode == KEY_CTRL_L) ? params->ctrl = 0 : (void)0;
	return (0);
}

int		mouse_move(int x, int y, void *param)
{
	t_params *params;

	params = (t_params *)param;
	if (params->ctrl && (params->type == T_E_JULIA ||
		params->type == T_E_JULIA_4 || params->type == T_E_JULIA_3))
	{
		if ((y <= params->height) && (x >= 0) && (y >= 0) &&
			(x <= params->width))
		{
			params->cr = 2 * (((double)params->width / 2 - x) /
				params->width);
			params->ci = 2 * (((double)params->height / 2 - y) /
				params->height);
			gr_calculate(params);
		}
	}
	return (0);
}

int		mouse_press(int btn, int x, int y, void *param)
{
	t_params *p;

	p = (t_params *)param;
	if ((btn != 4) && (btn != 5))
		return (0);
	if ((y <= p->height) && (x >= 0) && (y >= 0) && (x <= p->width))
	{
		p->step_x = (p->max_x - p->min_x) * ((btn == 4) ? 0.5 : 2) / p->width;
		p->step_y = (p->max_y - p->min_y) * ((btn == 4) ? 0.5 : 2) / p->height;
		p->min_x = p->min_x + p->step_x * ((btn == 4) ? x : -x / 2);
		p->min_y = p->min_y + p->step_y * ((btn == 4) ? y : -y / 2);
		p->max_x = p->min_x + p->step_x * p->width;
		p->max_y = p->min_y + p->step_y * p->height;
		gr_calculate(p);
	}
	return (0);
}
