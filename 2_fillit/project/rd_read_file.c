/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rd_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbernier <fbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 20:01:13 by trhogoro          #+#    #+#             */
/*   Updated: 2018/11/30 14:14:38 by fbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "error.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

static int	check_matrix(char *buf, int *diff)
{
	int count;
	int i;
	int first;

	i = -1;
	count = 0;
	first = -1;
	while (++i < FIGURE_SIZE)
	{
		if ((!((i + 1) % 5)) && (buf[i] != '\n'))
			return (ft_error(E_WRONG_LINE));
		if (((i + 1) % 5) && ((buf[i] == '#') || (buf[i] == '.')))
		{
			if ((count += (buf[i] == '#')) > 4)
				return (ft_error(E_WRONG_SYMBOL));
			if (buf[i] == '#')
				first == -1 ? (first = i) :
					(diff[count - 2] = i - first);
		}
		if ((i + 1) % 5 && ((buf[i] != '#') && (buf[i] != '.')))
			return (ft_error(E_WRONG_SYMBOL));
	}
	if (count != 4)
		return (ft_error(E_WRONG_SYMBOL));
	return (E_SUCCESS);
}

static int	add_figure(char *buf, char sym, t_list *dflt_fgr, t_list **result)
{
	int		diff[3];
	int		t;
	char	*data;

	if (check_matrix(buf, diff))
		return (E_ERROR);
	if (!(data = (char *)malloc(D_SIZE)))
		return (ft_error(E_MEMORY_ERROR));
	if ((t = ft_lstcindexof(dflt_fgr, (void *)diff, sizeof(diff), *difequ))
			> -1)
	{
		data[D_TYPE] = t;
		data[D_SYM] = sym;
		ft_lstradd(result, ft_lstnew(data, D_SIZE));
		return (ft_error_ptr(E_SUCCESS, &data));
	}
	else
		return (ft_error_ptr(E_WRONG_SYMBOL, &data));
}

int			read_file(char *filename, t_list **dflt_fgr, t_list **result)
{
	int		fd;
	int		size;
	void	*buf;
	int		count;

	if (!(*dflt_fgr = default_figures_init()))
		return (E_MEMORY_ERROR);
	if ((fd = open(filename, O_RDONLY)) < 0)
		return (ft_error(E_CANT_OPEN_FILE));
	buf = malloc(FIGURE_SIZE);
	count = 0;
	while ((++count <= 26) && (size = read(fd, buf, FIGURE_SIZE)))
	{
		if (size != FIGURE_SIZE)
			return (ft_error_ptrfile(E_READING_ERROR, &buf, fd));
		if (add_figure(buf, 'A' + count - 1, *dflt_fgr, result))
			return (ft_error_ptrfile(E_ERROR, &buf, fd));
		if ((size = read(fd, buf, 1)) && (((char *)buf)[0] != '\n'))
			return (ft_error_ptrfile(E_WRONG_SEPARATOR, &buf, fd));
		if (!size)
			return (ft_error_ptrfile(E_SUCCESS, &buf, fd));
	}
	return (ft_error_ptrfile(E_TOO_MUCH_FIGURES, &buf, fd));
}
