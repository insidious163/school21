/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_oper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrot <kcarrot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 10:30:49 by kcarrot           #+#    #+#             */
/*   Updated: 2019/02/08 10:55:35 by kcarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_path	*ft_complete_path(t_path *path, t_room *room)
{
	t_path	*new_node;
	t_path	*head;

	head = path;
	if (!path)
	{
		new_node = (t_path*)malloc(sizeof(t_path));
		new_node->room = room;
		new_node->next = NULL;
		path = new_node;
	}
	else
	{
		while (path->next)
			path = path->next;
		new_node = (t_path*)malloc(sizeof(t_path));
		new_node->room = room;
		new_node->next = NULL;
		path->next = new_node;
		path = head;
	}
	return (path);
}

t_ps	*ft_new_path(t_ps *ps, t_path *path)
{
	t_ps	*new_node;
	t_ps	*head;

	head = ps;
	if (!ps)
	{
		new_node = (t_ps*)malloc(sizeof(t_ps));
		new_node->path = path;
		new_node->next = NULL;
		ps = new_node;
	}
	else
	{
		while (ps->next)
			ps = ps->next;
		new_node = (t_ps*)malloc(sizeof(t_ps));
		new_node->path = path;
		new_node->next = NULL;
		ps->next = new_node;
		ps = head;
	}
	return (ps);
}

t_path	*ft_copy_path(t_path *path)
{
	t_path	*new_path;

	new_path = NULL;
	while (path)
	{
		new_path = ft_complete_path(new_path, path->room);
		path = path->next;
	}
	return (new_path);
}

t_room	*ft_pop_path(t_path **path)
{
	t_path	*tmp;
	t_room	*res;

	if (*path == NULL)
		return (NULL);
	tmp = *path;
	*path = (*path)->next;
	res = tmp->room;
	free(tmp);
	tmp = NULL;
	return (res);
}

t_path	*ft_pop_path_line(t_ps **line)
{
	t_ps	*tmp;
	t_path	*res;

	if (*line == NULL)
		return (NULL);
	tmp = *line;
	*line = (*line)->next;
	res = tmp->path;
	free(tmp);
	tmp = NULL;
	return (res);
}
