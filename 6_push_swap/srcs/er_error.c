/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   er_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 02:30:14 by trhogoro          #+#    #+#             */
/*   Updated: 2019/01/31 02:30:15 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"
#include "libft.h"

void	er_error(int err_num)
{
	if (err_num != E_SUCCESS)
	{
		ft_putendl("Error");
		exit(err_num);
	}
}

void	wr_usage_push_swap(void)
{
	ft_putendl("usage: ./push_swap <-h> <-t> int args");
	exit(1);
}

void	wr_usage_checker(void)
{
	ft_putendl("usage: ./checker <-h> <-d> <-c> <-v> int args");
	ft_putendl("new command for each line.");
	ft_putendl("available commands: pa pb sa sb ss ra rra rb rrb rr rrr.");
	exit(1);
}
