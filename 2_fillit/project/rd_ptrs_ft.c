/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rd_ptrs_ft.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbernier <fbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 19:48:50 by trhogoro          #+#    #+#             */
/*   Updated: 2018/11/30 14:14:25 by fbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fillit.h"

int		lstequ(t_list *e1, t_list *e2)
{
	if (!e1 || !e2)
		return (-1);
	if (((e1->content_size) == (e2->content_size)) &&
		(ft_memequ(e1->content, e2->content, e1->content_size)))
		return (1);
	return (0);
}

void	lstdel(void *content, size_t content_size)
{
	if (content_size && content)
		free(content);
}

int		difequ(t_list *where, t_list *what)
{
	int *new;
	int result;

	if (!where || !what)
		return (-1);
	if (!(new = (int*)malloc(3 * sizeof(int))))
		return (-1);
	new[0] = (((int *)what->content)[0] == 1 ?
			1 : (5 + ((int *)what->content)[0]));
	new[1] = ((int *)what->content)[1] + 5 * (((int *)what->content)[1] / 4);
	new[2] = ((int *)what->content)[2] + 5 * (((int *)what->content)[2] / 4);
	result = ft_memequ(new, where->content, 3 * sizeof(int));
	free(new);
	return (result);
}

int		dtequ(t_list *where, t_list *what)
{
	if (!where || !what)
		return (-1);
	if (!where->content || !what->content)
		return (-1);
	return (((char *)where->content)[D_TYPE] ==
			((char *)what->content)[D_TYPE]);
}
