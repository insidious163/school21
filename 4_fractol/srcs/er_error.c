/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   er_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 22:52:23 by trhogoro          #+#    #+#             */
/*   Updated: 2019/01/09 22:52:23 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fractol.h"
#include <stdlib.h>

void	er_error(int error_number)
{
	if (error_number == E_NUM_PARAMS)
		ft_putendl_fd(USAGE, 2);
	if (error_number == E_NUM_COL_FILE)
		ft_putendl_fd(E_MSG_COL_FILE, 2);
	if (error_number == E_NUM_TREAD)
		ft_putendl_fd(E_MSG_THREAD, 2);
	exit(error_number);
}
