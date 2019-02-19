/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rd_check_figure.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbernier <fbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 19:57:27 by trhogoro          #+#    #+#             */
/*   Updated: 2018/11/29 22:17:22 by fbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

static void		*cr_exmpl(int **fe, int a, int b, int c)
{
	if (!*fe)
		if (!(*fe = (int *)malloc(3 * sizeof(int))))
			return (0x0);
	(*fe)[0] = (a == 1 ? 1 : 5 + a);
	(*fe)[1] = b + 5 * (b / 4);
	(*fe)[2] = c + 5 * (c / 4);
	return ((void *)(*fe));
}

static t_list	*check_default_figures(t_list *fexmpls, int *fp)
{
	if (fp)
		free(fp);
	if (ft_lstlen(fexmpls) != 19)
		ft_lstdel(&fexmpls, *lstdel);
	return (fexmpls);
}

t_list			*default_figures_init(void)
{
	t_list	*fexmpls;
	int		*fe;

	fexmpls = 0x0;
	fe = 0x0;
	ft_lstradd(&fexmpls, ft_lstnew(cr_exmpl(&fe, 1, 5, 6), 3 * sizeof(int)));
	ft_lstradd(&fexmpls, ft_lstnew(cr_exmpl(&fe, 1, 2, 3), 3 * sizeof(int)));
	ft_lstradd(&fexmpls, ft_lstnew(cr_exmpl(&fe, 5, 10, 15), 3 * sizeof(int)));
	ft_lstradd(&fexmpls, ft_lstnew(cr_exmpl(&fe, 4, 5, 6), 3 * sizeof(int)));
	ft_lstradd(&fexmpls, ft_lstnew(cr_exmpl(&fe, 5, 6, 10), 3 * sizeof(int)));
	ft_lstradd(&fexmpls, ft_lstnew(cr_exmpl(&fe, 1, 2, 6), 3 * sizeof(int)));
	ft_lstradd(&fexmpls, ft_lstnew(cr_exmpl(&fe, 4, 5, 10), 3 * sizeof(int)));
	ft_lstradd(&fexmpls, ft_lstnew(cr_exmpl(&fe, 1, 2, 5), 3 * sizeof(int)));
	ft_lstradd(&fexmpls, ft_lstnew(cr_exmpl(&fe, 1, 6, 11), 3 * sizeof(int)));
	ft_lstradd(&fexmpls, ft_lstnew(cr_exmpl(&fe, 3, 4, 5), 3 * sizeof(int)));
	ft_lstradd(&fexmpls, ft_lstnew(cr_exmpl(&fe, 5, 10, 11), 3 * sizeof(int)));
	ft_lstradd(&fexmpls, ft_lstnew(cr_exmpl(&fe, 1, 2, 7), 3 * sizeof(int)));
	ft_lstradd(&fexmpls, ft_lstnew(cr_exmpl(&fe, 5, 9, 10), 3 * sizeof(int)));
	ft_lstradd(&fexmpls, ft_lstnew(cr_exmpl(&fe, 5, 6, 7), 3 * sizeof(int)));
	ft_lstradd(&fexmpls, ft_lstnew(cr_exmpl(&fe, 1, 5, 10), 3 * sizeof(int)));
	ft_lstradd(&fexmpls, ft_lstnew(cr_exmpl(&fe, 1, 4, 5), 3 * sizeof(int)));
	ft_lstradd(&fexmpls, ft_lstnew(cr_exmpl(&fe, 5, 6, 11), 3 * sizeof(int)));
	ft_lstradd(&fexmpls, ft_lstnew(cr_exmpl(&fe, 1, 6, 7), 3 * sizeof(int)));
	ft_lstradd(&fexmpls, ft_lstnew(cr_exmpl(&fe, 4, 5, 9), 3 * sizeof(int)));
	return (check_default_figures(fexmpls, fe));
}
