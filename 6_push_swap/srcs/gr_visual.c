/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gr_visual.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 02:32:34 by trhogoro          #+#    #+#             */
/*   Updated: 2019/01/31 02:32:35 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include "push_swap.h"
#include <mlx.h>
#include <unistd.h>

static void	gr_draw_value(t_gr *gr, int value, int n, int is_right)
{
	t_point	a;
	t_point	b;
	int		val;

	val = value < 0 ? -value : value;
	a.y = (n * (gr)->step_y);
	b.y = (n + 1) * ((gr)->step_y) - 1;
	a.x = (is_right) * (*gr).width / 2 +
			(int)(((*gr).width) * (1 - (double)(val) / (*gr).max_x) / 4);
	b.x = a.x + (*gr).width * val / (2 * (*gr).max_x) - 1;
	gr_draw_rectangle(gr, a, b, value < 0 ? 0xFF0000 : 0xFF00);
}

static void	gr_draw_stack(t_gr *gr, t_lst2 *stack, int stack_id)
{
	t_lst2	*last;
	int		n;

	if (stack && (last = stack->prev))
	{
		n = 0;
		while (stack != last)
		{
			gr_draw_value(gr, ((t_info *)stack->content)->value, n++, stack_id);
			stack = stack->next;
		}
		gr_draw_value(gr, ((t_info *)stack->content)->value, n, stack_id);
	}
}

void		gr_draw_picture(t_gr *gr, t_lst2 *stack_a, t_lst2 *stack_b)
{
	t_point	a;
	t_point	b;

	a.x = 0;
	a.y = 0;
	b.x = gr->width / 2 - 1;
	b.y = gr->height - 1;
	mlx_clear_window(gr->mlx, gr->win);
	gr_draw_rectangle(gr, a, b, 0xFFFFFF);
	gr_draw_stack(gr, stack_a, STACK_A);
	gr_draw_stack(gr, stack_b, STACK_B);
}

static void	gr_initialize(t_gr **gr, t_lst2 *stack_a, int len)
{
	if (len > HEIGHT)
		er_error(E_VISUAL);
	*gr = (t_gr *)malloc(sizeof(t_gr));
	(*gr)->mlx = mlx_init();
	(*gr)->height = (HEIGHT / len) * len;
	(*gr)->width = (*gr)->height;
	(*gr)->step_y = HEIGHT / len;
	(*gr)->max_x = gr_max_abs(stack_a);
	(*gr)->win = mlx_new_window((*gr)->mlx, (*gr)->width, (*gr)->height,
								"PUSH SWAP");
}

void		gr_visual(t_lst2 *stack_a, t_list *cmd)
{
	int		len;
	t_lst2	*stack_b;
	t_gr	*gr;
	t_param	*param;

	stack_b = 0x0;
	len = (int)ft_lst2len(stack_a);
	if (!cmd || !stack_a)
		exit(0);
	gr_initialize(&gr, stack_a, len);
	gr_draw_picture(gr, stack_a, stack_b);
	param = (t_param *)malloc(sizeof(t_param));
	param->gr = gr;
	param->stack_a = stack_a;
	param->stack_b = stack_b;
	param->cmd = cmd;
	mlx_hook(gr->win, 2, 0, key_press, &param);
	mlx_hook(gr->win, 6, 0, mouse_move, &param);
	mlx_hook(gr->win, 17, 0, exit_x, 0);
	mlx_loop(gr->mlx);
}
