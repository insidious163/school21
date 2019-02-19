/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbernier <fbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 20:28:50 by trhogoro          #+#    #+#             */
/*   Updated: 2018/11/30 14:07:46 by fbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_ERROR_H
# define FILLIT_ERROR_H

# define E_SUCCESS 0
# define E_ERROR 1
# define E_CANT_OPEN_FILE 2
# define E_READING_ERROR 3
# define E_WRONG_SEPARATOR 4
# define E_WRONG_SYMBOL 5
# define E_WRONG_LINE 6
# define E_MEMORY_ERROR 7
# define E_TOO_MUCH_FIGURES 8

# include "libft.h"

int	ft_error(int errnum);
int	ft_ft_error_lstptr(int errnum, t_list *lst, void *ptr);
int	ft_error_lst(int errnum, t_list *lst);
int	ft_error_ptr(int errnum, void *ptr);
int	ft_error_ptrfile(int errnum, void *ptr, int fd);
#endif
