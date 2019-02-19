/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gr_apply_correction.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrot <kcarrot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 09:36:50 by trhogoro          #+#    #+#             */
/*   Updated: 2019/02/07 23:03:02 by kcarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void	gr_apply_correction(t_correction correction, t_params *params)
{
	gr_apply_color(params);
	gr_apply_scale(&(correction.sc[correction.type]), params);
	gr_apply_move(&(correction.mv[correction.type]), params);
	gr_apply_rotation(&(correction.rt[correction.type]), params);
	gr_apply_type(correction.type, params);
}
