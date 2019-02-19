/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gr_thread.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 22:53:38 by trhogoro          #+#    #+#             */
/*   Updated: 2019/01/09 22:53:39 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <mlx.h>
#include "libft.h"

static void	*thread_func(void *thread_data)
{
	t_thread_info	*info;

	info = (t_thread_info *)thread_data;
	info->params->draw(info->params, info->start_x, info->finish_x);
	return (0x0);
}

void		gr_treadable(t_params *params)
{
	int				i;
	pthread_t		*threads;
	t_thread_info	*thread_info;

	threads = (pthread_t *)malloc(params->threads * sizeof(pthread_t));
	thread_info = (t_thread_info *)malloc(params->threads
			* sizeof(t_thread_info));
	i = -1;
	while (++i < params->threads)
	{
		thread_info[i].params = params;
		thread_info[i].start_x = i * params->width / params->threads;
		thread_info[i].finish_x = (i + 1) * params->width / params->threads;
		pthread_create(&(threads[i]), 0x0, thread_func, &thread_info[i]);
	}
	i = -1;
	while (++i < params->threads)
		pthread_join(threads[i], 0x0);
	free(thread_info);
	free(threads);
}

void		gr_nontreadable(t_params *params)
{
	t_point pt_a;
	t_point pt_b;

	pt_a.x = -1;
	pt_a.y = 0;
	pt_b.x = 1;
	pt_b.y = 0;
	ft_memset(params->data, 0, sizeof(int) * params->height * params->width);
	if (params->type == T_DRAG)
		draw_dragon(params, pt_a, pt_b, 1);
	if (params->type == T_KOCH)
		draw_koch(params, pt_a, pt_b, 2);
}

void		gr_calculate(t_params *params)
{
	if (params->type <= T_NAUT)
		gr_treadable(params);
	else
		gr_nontreadable(params);
	mlx_clear_window(params->mlx, params->win);
	mlx_put_image_to_window(params->mlx, params->win, params->image, 0, 0);
}
