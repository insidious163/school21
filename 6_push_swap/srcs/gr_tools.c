/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gr_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 02:48:14 by trhogoro          #+#    #+#             */
/*   Updated: 2019/01/31 02:48:15 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <mlx.h>

void	gr_draw_rectangle(t_gr *gr, t_point a, t_point b, int color)
{
	t_point	min;
	t_point	max;
	int		y;

	min.x = (a.x < b.x) ? a.x : b.x;
	min.y = (a.y < b.y) ? a.y : b.y;
	max.x = (a.x > b.x) ? a.x : b.x;
	max.y = (a.y > b.y) ? a.y : b.y;
	while (min.x <= max.x)
	{
		y = min.y;
		while (y <= max.y)
		{
			mlx_pixel_put(gr->mlx, gr->win, min.x, y, color);
			y++;
		}
		min.x++;
	}
}

int		gr_max_abs(t_lst2 *stack_a)
{
	t_lst2	*last;
	int		result;
	int		val;

	result = 0;
	if (stack_a)
	{
		last = stack_a->prev;
		while (stack_a != last)
		{
			val = ((t_info *)stack_a->content)->value;
			val = val < 0 ? -val : val;
			result = val > result ? val : result;
			stack_a = stack_a->next;
		}
		val = ((t_info *)last->content)->value;
		val = val < 0 ? -val : val;
		result = val > result ? val : result;
	}
	return (result);
}
