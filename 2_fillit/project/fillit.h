/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 20:17:42 by trhogoro          #+#    #+#             */
/*   Updated: 2018/11/22 20:28:44 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_FILLIT_H
# define FILLIT_FILLIT_H

# include <string.h>
# include "libft.h"

# define FIGURE_SIZE 20
# define D_TYPE 0
# define D_SYM 1
# define D_SIZE 2

typedef	struct	s_temp_m
{
	char	*matrix;
	int		index;
	int		size;
}				t_temp_m;

int				cr_matrix(t_list *fgrs, t_temp_m *m);
t_list			*default_figures_init();
int				read_file(char *filename, t_list **default_figures,
					t_list **figures);
int				fill_it(t_list *dflt_fgrs, t_list **fgrs);
int				lstequ(t_list *e1, t_list *e2);
void			lstdel(void *content, size_t content_size);
int				difequ(t_list *where, t_list *what);
int				dtequ(t_list *where, t_list *what);
#endif
