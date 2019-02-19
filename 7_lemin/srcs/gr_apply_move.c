/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gr_apply_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrot <kcarrot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 09:37:09 by trhogoro          #+#    #+#             */
/*   Updated: 2019/02/07 23:05:50 by kcarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"
#include <math.h>

static void	move_one(t_list *elem, void *xyz)
{
	t_point3d	*point;
	t_xyz		*params;

	params = (t_xyz *)xyz;
	point = (t_point3d *)(elem->content);
	point->xt = params->x + point->xt;
	point->yt = params->y + point->yt;
	point->zt = params->z + point->zt;
}

void		gr_apply_move(void *params, t_params *param)
{
	ft_lstforeach(param->points, params, move_one);
}
