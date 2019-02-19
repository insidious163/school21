/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_it.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbernier <fbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 20:04:59 by trhogoro          #+#    #+#             */
/*   Updated: 2018/11/30 14:14:09 by fbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fillit.h"
#include "error.h"

static int	is_push_disable(t_temp_m m, int figure[3], char letter)
{
	int i;
	int j;
	int fi;
	int fj;
	int k;

	if (m.matrix[m.index] != '.')
		return (1);
	i = (m.index + 1) / (m.size + 1);
	j = (m.index) % (m.size + 1);
	k = 3;
	while (k--)
	{
		fi = (figure[k] + 2) / 10;
		fj = figure[k] - fi * 10;
		if ((fj + j >= m.size) || (fj + j < 0) || ((fi + i) >= m.size) ||
			(m.matrix[m.index + fj + fi * (m.size + 1)] != '.'))
			return (1);
	}
	k = 3;
	while (k--)
		m.matrix[m.index + figure[k] - (((figure[k] + 2) / 10)) * 10 +
			((figure[k] + 2) / 10) * (m.size + 1)] = letter;
	m.matrix[m.index] = letter;
	return (0);
}

static int	push_figure(t_list **elem, t_temp_m *matrix, int figure[3])
{
	t_list *new_elem;

	if (!is_push_disable(*matrix, figure, ((char *)(*elem)->content)[D_SYM]))
	{
		new_elem = (*elem)->next;
		ft_lstdelone(elem, lstdel);
		*elem = new_elem;
		return (0);
	}
	return (1);
}

static void	pop_figure(t_list **elem, t_temp_m *matrix, char *data)
{
	int i;

	i = -1;
	while (matrix->matrix[++i])
	{
		if (matrix->matrix[i] == data[D_SYM])
			matrix->matrix[i] = '.';
	}
	ft_lstadd(elem, ft_lstnew((void *)data, D_SIZE));
}

static void	fill_m(t_temp_m *matrix, char **sol,
		t_list *dflt_fgrs, t_list **fgrs)
{
	int		*figure;
	char	data[2];
	int		index;

	if (!(index = 0) && *fgrs)
	{
		figure = (int *)(ft_lstindex(dflt_fgrs,
				((char *)(*fgrs)->content)[D_TYPE]))->content;
		data[0] = (((char *)(*fgrs)->content))[D_TYPE];
		data[1] = ((char *)((*fgrs)->content))[D_SYM];
		while ((index++ < matrix->size * (matrix->size + 1) - 4) && (!(*sol)))
		{
			matrix->index = index - 1;
			if (!push_figure(fgrs, matrix, figure))
			{
				fill_m(matrix, sol, dflt_fgrs, fgrs);
				if (!(*fgrs))
				{
					*sol = ft_strnew(matrix->size * (matrix->size + 1) + 1);
					ft_strcpy(*sol, matrix->matrix);
				}
				pop_figure(fgrs, matrix, data);
			}
		}
	}
}

int			fill_it(t_list *dflt_fgrs, t_list **fgrs)
{
	t_temp_m	matrix;
	char		*solution;

	matrix.size = 0;
	matrix.matrix = 0x0;
	solution = 0x0;
	while (!solution)
	{
		if (cr_matrix(*fgrs, &matrix))
			return (E_ERROR);
		fill_m(&matrix, &solution, dflt_fgrs, fgrs);
	}
	ft_putstr(solution);
	free(solution);
	free(matrix.matrix);
	return (E_SUCCESS);
}
