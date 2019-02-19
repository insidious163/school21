/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gr_draw_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 16:05:20 by trhogoro          #+#    #+#             */
/*   Updated: 2019/02/08 02:21:03 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

static t_line	*gr_get_line(t_move *move, t_list *lines)
{
	t_point3d *tmp_point;

	while (lines)
	{
		if ((((t_line *)lines->content)->a->id == move->first) &&
			(((t_line *)lines->content)->b->id == move->second))
			return (t_line *)lines->content;
		if ((((t_line *)lines->content)->b->id == move->first) &&
			(((t_line *)lines->content)->a->id == move->second))
		{
			tmp_point = ((t_line *)lines->content)->a;
			((t_line *)lines->content)->a = ((t_line *)lines->content)->b;
			((t_line *)lines->content)->b = tmp_point;
			return ((t_line *)lines->content);
		}
		lines = lines->next;
	}
	return (0x0);
}

void			gr_draw_move(t_list *moves, int i, t_params *params)
{
	t_line *line;

	while (moves)
	{
		line = gr_get_line(((t_move *)moves->content), params->lines);
		gr_draw_ant(line->a->xi + (int)(i * (line->b->xi - line->a->xi) / ITER),
			line->a->yi + (int)(i * (line->b->yi - line->a->yi) / ITER),
			params);
		moves = moves->next;
	}
}
