/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbernier <fbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 19:46:28 by trhogoro          #+#    #+#             */
/*   Updated: 2018/11/30 14:13:39 by fbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fillit.h"
#include <unistd.h>

int	ft_error(int errnum)
{
	if (errnum > 1)
	{
		ft_putendl("error");
		return (1);
	}
	return (errnum);
}

int	ft_ft_error_lstptr(int errnum, t_list **lst, void **ptr)
{
	ft_lstdel(lst, *lstdel);
	free(*ptr);
	return (ft_error(errnum));
}

int	ft_error_lst(int errnum, t_list **lst)
{
	ft_lstdel(lst, *lstdel);
	return (ft_error(errnum));
}

int	ft_error_ptr(int errnum, void **ptr)
{
	free(*ptr);
	return (ft_error(errnum));
}

int	ft_error_ptrfile(int errnum, void **ptr, int fd)
{
	free(*ptr);
	close(fd);
	return (ft_error(errnum));
}
