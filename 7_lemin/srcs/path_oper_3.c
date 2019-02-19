/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_oper_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrot <kcarrot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 10:49:26 by kcarrot           #+#    #+#             */
/*   Updated: 2019/02/08 10:55:37 by kcarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

size_t	ft_num_paths(t_ps *ps)
{
	t_ps	*tmp;
	size_t	len;

	len = 0;
	tmp = ps;
	while (ps)
	{
		len++;
		ps = ps->next;
	}
	ps = tmp;
	return (len);
}

size_t	ft_path_len(t_path *path)
{
	size_t	len;
	t_path	*head;

	head = path;
	len = 0;
	while (path)
	{
		len++;
		path = path->next;
	}
	path = head;
	return (len);
}

int		ft_check_path(t_path *path, int id)
{
	t_path	*head;
	int		res;

	res = 1;
	head = path;
	while (path)
	{
		if (path->room->id == id)
			res = 0;
		path = path->next;
	}
	path = head;
	return (res);
}
