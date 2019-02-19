/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cr_matrix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbernier <fbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 20:12:37 by trhogoro          #+#    #+#             */
/*   Updated: 2018/11/29 22:55:57 by fbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "error.h"
#include <stdlib.h>

int		cr_matrix(t_list *fgrs, t_temp_m *m)
{
	int count;
	int i;

	if (m->matrix)
		free(m->matrix);
	if (!(count = m->size))
	{
		while (fgrs)
		{
			count += 1;
			fgrs = fgrs->next;
		}
		while (m->size * m->size < count * 4)
			m->size++;
	}
	else
		m->size++;
	if (!(m->matrix = (char *)malloc(m->size * (m->size + 1) + 1)))
		return (ft_error(E_MEMORY_ERROR));
	i = 0;
	while (i < m->size * (m->size + 1))
		(i + 1) % (m->size + 1) ? ((m->matrix)[i++] = '.')
								: ((m->matrix)[i++] = '\n');
	(m->matrix)[m->size * (m->size + 1)] = '\0';
	return ((m->index = 0));
}
