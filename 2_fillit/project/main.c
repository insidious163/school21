/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbernier <fbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 19:47:53 by trhogoro          #+#    #+#             */
/*   Updated: 2018/11/30 14:14:17 by fbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **argv)
{
	t_list *fgrs;
	t_list *dflt_fgrs;

	fgrs = 0x0;
	dflt_fgrs = 0x0;
	if (argc == 2)
	{
		if (!read_file(argv[1], &dflt_fgrs, &fgrs))
			fill_it(dflt_fgrs, &fgrs);
		ft_lstdel(&fgrs, lstdel);
		ft_lstdel(&dflt_fgrs, lstdel);
		return (0);
	}
	else if (argc < 2)
	{
		ft_putendl_fd("fillit: missing file", 2);
		ft_putendl_fd("Try './fillit your_file_with_figures'", 2);
	}
	else
	{
		ft_putendl_fd("fillit: too many files", 2);
		ft_putendl_fd("Only one file is alloweded", 2);
	}
	return (0);
}
