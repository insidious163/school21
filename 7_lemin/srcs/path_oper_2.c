/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_oper_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrot <kcarrot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 10:49:26 by kcarrot           #+#    #+#             */
/*   Updated: 2019/02/08 11:56:44 by kcarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_print_debug(t_path_set *path)
{
	t_path	*head;
	size_t	i;

	if (!path || !path->paths)
		return ;
	ft_putchar('\n');
	i = 0;
	while (i < path->num_of_paths)
	{
		head = (path->paths)[i];
		ft_putstr("Path: ");
		while (head)
		{
			ft_putstr(head->room->name);
			ft_putchar(' ');
			head = head->next;
		}
		ft_putchar('\n');
		i++;
	}
}

void	ft_path_destroyer(t_path *path)
{
	t_path	*tmp;

	while (path)
	{
		tmp = path;
		path = path->next;
		tmp->next = NULL;
		free(tmp);
	}
}

void	ft_ps_destroyer(t_ps *ps)
{
	t_ps	*tmp;

	while (ps)
	{
		tmp = ps;
		ps = ps->next;
		tmp->next = NULL;
		free(tmp);
	}
}
