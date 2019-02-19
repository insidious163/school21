/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gr_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrot <kcarrot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 17:06:08 by trhogoro          #+#    #+#             */
/*   Updated: 2019/02/07 23:42:14 by kcarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "visual.h"

static void	init_correction(t_correction *c, int type)
{
	int i;

	c->type = type;
	i = 0;
	while (i < 3)
	{
		c->mv[i].x = 0;
		c->mv[i].y = 0;
		c->mv[i].z = 0;
		c->rt[i].x = 0;
		c->rt[i].y = 0;
		c->rt[i].z = 0;
		c->sc[i] = 1;
		i++;
	}
	c->path = 0;
	c->iter = -1;
}

int			gr_run(t_farm *farm, t_path_set *set, t_ant **ants)
{
	t_params *params;

	params = gr_init(farm, ants);
	params->set = set;
	init_correction(&(params->c), P_PAR);
	params->c.path = (int)set->num_of_paths;
	gr_set_start_settings_con(params);
	gr_set_start_settings_iso(params);
	gr_set_start_settings_par(params);
	gr_apply_correction(params->c, params);
	gr_draw_farm(params);
	mlx_hook(params->win, 2, 0, key_hook, params);
	mlx_hook(params->win, 17, 0, exit_x, 0);
	mlx_loop(params->mlx);
	return (0);
}
