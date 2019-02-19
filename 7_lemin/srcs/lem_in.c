/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrot <kcarrot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 10:30:18 by kcarrot           #+#    #+#             */
/*   Updated: 2019/02/08 14:07:32 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	ft_print_input(t_farm *farm)
{
	t_list *out;

	out = farm->output;
	while (out)
	{
		ft_putendl((char *)out->content);
		out = out->next;
	}
	ft_putendl("");
}

static void	ft_print_usage(void)
{
	ft_putendl("usage: ./lemin <-v> <-d> <-h> < map");
	ft_putendl("-v -visual mode");
	ft_putendl("-d -debug mode");
	ft_putendl("-h -print usage");
	exit(0);
}

static int	end_of_main(t_farm *farm, t_room *start, t_room *end, int opt)
{
	int			num_of_paths;
	t_path_set	*set;

	num_of_paths = MIN(MIN((int)farm->ants_count, start->degree), end->degree);
	ft_print_input(farm);
	set = ft_start_bfs(farm, num_of_paths, ((opt >> ('v' - 'a')) & 1));
	if (!set)
		ft_error_output(farm, "No possible solutions");
	((opt >> ('d' - 'a')) & 1) ? ft_print_debug(set) : (void)0;
	ft_farm_destroyer(farm);
	return (0);
}

void		set_start_end(t_farm *farm, t_room **start,
			t_room **end, t_room *tmp)
{
	int		i;

	i = -1;
	while (++i < (int)farm->rooms_count)
	{
		if (farm->rooms->name == farm->start)
			*start = farm->rooms;
		farm->rooms = farm->rooms->next;
	}
	farm->rooms = tmp;
	i = -1;
	while (++i < (int)farm->rooms_count)
	{
		if (farm->rooms->name == farm->end)
			*end = farm->rooms;
		farm->rooms = farm->rooms->next;
	}
	farm->rooms = tmp;
}

int			main(int ac, char **av)
{
	t_farm		*farm;
	t_room		*start;
	t_room		*end;
	t_room		*tmp;
	int			opt;

	opt = rd_options(ac, av, "vdh");
	if ((opt >> ('h' - 'a')) & 1)
		ft_print_usage();
	farm = ft_init_farm();
	tmp = farm->rooms;
	set_start_end(farm, &start, &end, tmp);
	return (end_of_main(farm, start, end, opt));
}
