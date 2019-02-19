/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gr_params.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 12:51:41 by trhogoro          #+#    #+#             */
/*   Updated: 2019/01/17 12:51:42 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fractol.h"

static int	ft_set_type(t_params *params, char *type)
{
	if (ft_strequ(type, "j"))
		(params)->type = T_JULIA;
	else if (ft_strequ(type, "m"))
		(params)->type = T_MANDELBROT;
	else if (ft_strequ(type, "b"))
		(params)->type = T_BURN;
	else if (ft_strequ(type, "e"))
		(params)->type = T_E_JULIA;
	else if (ft_strequ(type, "j4"))
		(params)->type = T_JULIA_4;
	else if (ft_strequ(type, "e4"))
		(params)->type = T_E_JULIA_4;
	else if (ft_strequ(type, "j3"))
		(params)->type = T_JULIA_3;
	else if (ft_strequ(type, "e3"))
		(params)->type = T_E_JULIA_3;
	else if (ft_strequ(type, "n"))
		(params)->type = T_NAUT;
	else if (ft_strequ(type, "d"))
		(params)->type = T_DRAG;
	else if (ft_strequ(type, "k"))
		(params)->type = T_KOCH;
	else
		return (E_NUM_PARAMS);
	return (E_SUCCESS);
}

int			ft_get_thread(char *str, t_params **param)
{
	if (ft_strequ(str, "2"))
		return ((*param)[0].threads = 2);
	if (ft_strequ(str, "4"))
		return ((*param)[0].threads = 4);
	if (ft_strequ(str, "8"))
		return ((*param)[0].threads = 8);
	if (ft_strequ(str, "16"))
		return ((*param)[0].threads = 16);
	if (ft_strequ(str, "32"))
		return ((*param)[0].threads = 32);
	return (0);
}

void		ft_thread_param(t_params **param, int argc, char **argv, int *i)
{
	if (ft_strequ(argv[*i], "-t"))
	{
		if (argc > *i + 1)
		{
			if (!ft_get_thread(argv[*i + 1], param))
				return (er_error(E_NUM_TREAD));
		}
		else
			return (er_error(E_NUM_PARAMS));
		*i += 2;
	}
	else
		(*param)[0].threads = DEFAULT_THREADS;
}

void		ft_color_param(t_params **param, int argc, char **argv, int *i)
{
	if (ft_strequ(argv[1], "-c"))
	{
		if (argc > 2)
		{
			if (ft_get_colors(argv[2], param))
				return (er_error(E_NUM_COL_FILE));
		}
		else
			return (er_error(E_NUM_PARAMS));
		*i = 3;
	}
	else if (ft_get_colors(COLORS_FILE, param))
		return (er_error(E_NUM_COL_FILE));
}

void		ft_collect_info(t_params **param, int argc, char **argv)
{
	int i;

	i = 1;
	ft_color_param(param, argc, argv, &i);
	ft_thread_param(param, argc, argv, &i);
	if ((argc <= i) || (ft_set_type(&((*param)[0]), argv[i]) == E_NUM_PARAMS))
		return (er_error(E_NUM_PARAMS));
	if (argc == ++i)
		return ;
	if (ft_set_type(&((*param)[1]), argv[i]) == E_NUM_PARAMS)
		return (er_error(E_NUM_PARAMS));
	ft_memmove((void *)((*param)[1].color), (void *)((*param)[0].color), 1024);
	if (argc != ++i)
		return (er_error(E_NUM_PARAMS));
}
