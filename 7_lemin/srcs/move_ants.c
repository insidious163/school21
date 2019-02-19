/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrot <kcarrot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 12:59:48 by kcarrot           #+#    #+#             */
/*   Updated: 2019/02/08 10:48:08 by kcarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	assign_route(t_ant *ant, t_path_set *paths)
{
	size_t	i;
	int		j;
	int		min;
	int		res;

	i = 1;
	res = 0;
	min = (paths->lens)[0] + (paths->ants)[0];
	while (i < paths->num_of_paths)
	{
		j = (paths->lens)[i] + (paths->ants)[i];
		if (j < min)
		{
			min = j;
			res = i;
		}
		i++;
	}
	ant->route = (paths->paths)[res];
	if ((paths->paths)[res]->next->room->state != -2)
		(paths->ants)[res] += 1;
}

int		finish(t_ant **ants)
{
	int i;

	i = 0;
	while (ants[i])
	{
		if (ants[i]->route->next)
			return (0);
		i++;
	}
	return (1);
}

void	print_move(t_ant *ant)
{
	ft_putchar('L');
	ft_putnbr(ant->id);
	ft_putchar('-');
	ft_putstr(ant->route->room->name);
	ft_putchar(' ');
}

void	ants_moving(t_ant **ants)
{
	int	i;

	i = 0;
	while (ants[i])
	{
		if ((ants[i])->route->next && (ants[i])->route->next->room->state < 1)
		{
			if (!(ants[i])->id)
			{
				(ants[i])->id = g_num;
				g_num++;
			}
			ants[i]->route->room->state = 0;
			ants[i]->route = ants[i]->route->next;
			ants[i]->route->room->state +=
			(ants[i]->route->room->state < 0) ? 0 : 1;
			print_move(ants[i]);
		}
		i++;
	}
}

void	move_ants(int ants_c, t_path_set *paths)
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
	while (!finish(ants))
	{
		ants_moving(ants);
		ft_putchar('\n');
	}
	i = 0;
	while (i < ants_c)
		free(ants[i++]);
	free(ants);
}
