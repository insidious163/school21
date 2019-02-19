/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wr_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 02:42:13 by trhogoro          #+#    #+#             */
/*   Updated: 2019/02/01 02:42:14 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	wr_type(t_list *cmd_ll, t_list *cmd_qs)
{
	ft_putstr("Count of operations for long line sort : ");
	ft_putnbr(ft_lstlen(cmd_ll));
	ft_putendl(".");
	ft_putstr("Count of operations for quick sort : ");
	ft_putnbr(ft_lstlen(cmd_qs));
	ft_putendl(".");
}
