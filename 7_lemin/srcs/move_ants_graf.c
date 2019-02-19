/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants_graf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrot <kcarrot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 18:33:20 by kcarrot           #+#    #+#             */
/*   Updated: 2019/02/08 10:55:06 by kcarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "visual.h"

t_ant		**create_ants(size_t num)
{
	t_ant	**res;
	size_t	i;

	i = 1;
	res = (t_ant**)malloc(sizeof(t_ant*) * (num + 1));
	while (i <= num)
	{
		res[i - 1] = (t_ant*)malloc(sizeof(t_ant));
		res[i - 1]->id = 0;
		i++;
	}
	res[i - 1] = NULL;
	return (res);
}

t_ant		**gr_make_ants(int ants_c, t_path_set *paths)
{
	t_ant	**ants;
	int		i;

	ants = create_ants(ants_c);
	i = 0;
	while (i < ants_c)
	{
		assign_route(ants[i], paths);
		i++;
	}
	return (ants);
}

t_list		*gr_ants_moving(t_ant **ants)
{
	int		i;
	int		*id;
	t_list	*res;

	i = 0;
	res = NULL;
	while (ants[i])
	{
		if ((ants[i])->route->next && (ants[i])->route->next->room->state < 1)
		{
			if (!(ants[i])->id)
				(ants[i])->id = g_num++;
			id = (int*)malloc(sizeof(int) * 2);
			id[0] = ants[i]->route->room->id;
			ants[i]->route->room->state = 0;
			ants[i]->route = ants[i]->route->next;
			ants[i]->route->room->state +=
			(ants[i]->route->room->state < 0) ? 0 : 1;
			id[1] = ants[i]->route->room->id;
			ft_lstradd(&res, ft_lstnew(id, 16));
			print_move(ants[i]);
		}
		i++;
	}
	return (res);
}

t_list		*gr_get_moves(t_params *params)
{
	t_list	*res;

	res = NULL;
	if (!finish(params->ants))
	{
		res = gr_ants_moving(params->ants);
		ft_putchar('\n');
	}
	return (res);
}
