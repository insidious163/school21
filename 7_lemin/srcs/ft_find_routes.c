/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_routes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrot <kcarrot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 16:16:33 by kcarrot           #+#    #+#             */
/*   Updated: 2019/02/08 11:59:07 by kcarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		free_matrix(unsigned char **cross_m, size_t num)
{
	size_t i;

	i = 0;
	while (i < num)
	{
		free(cross_m[i]);
		i++;
	}
	free(cross_m);
}

static void		clear_all(unsigned char **matrix, int *arr, t_path_set *set)
{
	free_matrix(matrix, set->num_of_paths);
	free(arr);
	free(set->lens);
	free(set->ants);
	free(set->paths);
}

static int		find_num(int *best)
{
	int i;

	i = 0;
	while (best[i] != -1)
		i++;
	return (i);
}

static void		find_path_loop(t_path_set *res, t_path_set *set, int *best)
{
	size_t	j;

	j = 0;
	while (j < res->num_of_paths)
	{
		(res->paths)[j] = (set->paths)[best[j]];
		(res->lens)[j] = (set->lens)[best[j]];
		(res->ants)[j] = 0;
		j++;
	}
	(res->paths)[j] = NULL;
}

t_path_set		*find_paths(t_farm *farm, t_path_set *set, int nop, int sign)
{
	int					*best;
	t_path_set			*res;
	unsigned char		**cross_m;
	t_ant				**ants;

	if (!set)
		return (NULL);
	cross_m = make_cross_matrix(set->paths, set->num_of_paths);
	best = find_best_path(farm->ants_count, set, cross_m);
	res = (t_path_set*)malloc(sizeof(t_path_set));
	res->num_of_paths = find_num(best);
	res->paths = (t_path**)malloc(sizeof(t_path*) * (res->num_of_paths + 1));
	res->lens = (size_t*)malloc(sizeof(size_t) * res->num_of_paths);
	res->ants = (size_t*)malloc(sizeof(size_t) * res->num_of_paths);
	find_path_loop(res, set, best);
	if ((int)res->num_of_paths >= nop && !sign)
		move_ants(farm->ants_count, res);
	else if ((int)res->num_of_paths >= nop && sign)
	{
		ants = gr_make_ants(farm->ants_count, res);
		gr_run(farm, res, ants);
	}
	clear_all(cross_m, best, set);
	return (res);
}
