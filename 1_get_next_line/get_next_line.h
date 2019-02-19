/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 13:01:54 by trhogoro          #+#    #+#             */
/*   Updated: 2018/11/27 15:29:15 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"
# include <string.h>
# include <unistd.h>
# include <stdlib.h>

# define BUFF_SIZE 1024

int				get_next_line(const int fd, char **line);

typedef	struct	s_bufs
{
	int			fd;
	char		*buf;
}				t_bufs;

#endif
