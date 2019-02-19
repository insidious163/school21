/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gr_apply_scale.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrot <kcarrot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 09:37:25 by trhogoro          #+#    #+#             */
/*   Updated: 2019/02/07 23:03:00 by kcarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

static void	scale_one(t_list *elem, void *params)
{
	t_point3d	*point;
	double		*scale;

	scale = (double *)params;
	point = (t_point3d *)(elem->content);
	point->xt = point->x * *scale;
	point->yt = point->y * *scale;
	point->zt = point->z * *scale;
}

void		gr_apply_scale(void *params, t_params *param)
{
	ft_lstforeach(param->points, params, scale_one);
}
