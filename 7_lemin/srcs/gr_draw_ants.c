/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gr_draw_ants.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrot <kcarrot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 16:03:14 by trhogoro          #+#    #+#             */
/*   Updated: 2019/02/07 23:02:55 by kcarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

static void		gr_draw_ant_small(int x, int y, t_params *params)
{
	gr_plot(x, y, C_ANT, params);
	gr_plot(x + 1, y + 1, C_ANT, params);
	gr_plot(x - 1, y + 1, C_ANT, params);
	gr_plot(x + 1, y - 1, C_ANT, params);
	gr_plot(x - 1, y - 1, C_ANT, params);
}

static void		gr_draw_ant_medium(int x, int y, t_params *params)
{
	int i;

	i = -1;
	while (++i < 64)
	{
		((ANT_MINI >> (63 - i)) & 1) ? gr_plot(x - 4 + i % 8, y - 4 + i / 8,
				C_ANT, params) : (void)0;
	}
}

static void		gr_draw_ant_large(int x, int y, t_params *params)
{
	int i;

	i = -1;
	while (++i < 64)
	{
		((ANT_LU >> (63 - i)) & 1) ? gr_plot(x - 8 + i % 8, y - 8 + i / 8,
				C_ANT, params) : (void)0;
		((ANT_RU >> (63 - i)) & 1) ? gr_plot(x + i % 8, y - 8 + i / 8,
				C_ANT, params) : (void)0;
		((ANT_LD >> (63 - i)) & 1) ? gr_plot(x - 8 + i % 8, y + i / 8,
				C_ANT, params) : (void)0;
		((ANT_RD >> (63 - i)) & 1) ? gr_plot(x + i % 8, y + i / 8,
				C_ANT, params) : (void)0;
	}
}

void			gr_draw_ant(int x, int y, t_params *params)
{
	if (params->c.sc[params->c.type] < 8)
		gr_draw_ant_small(x, y, params);
	else if (params->c.sc[params->c.type] < 24)
		gr_draw_ant_medium(x, y, params);
	else
		gr_draw_ant_large(x, y, params);
}
