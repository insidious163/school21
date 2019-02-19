/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ll_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 11:47:57 by trhogoro          #+#    #+#             */
/*   Updated: 2019/01/31 11:47:58 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int		ll_i_mn(int a, int b)
{
	return (a < b ? a : b);
}

int		ll_i_mx(int a, int b)
{
	return (a < b ? b : a);
}

void	ll_same_direction_rotation(t_list **commands, int a, int b)
{
	int temp;
	int i;

	i = -1;
	if (a >= 0 && b >= 0)
	{
		temp = ll_i_mn(a, b);
		while (++i < temp)
			ft_lstradd(commands, ft_lstnew(RR, ft_strlen(RR) + 1));
		temp = ll_i_mx(a, b) - temp;
		i = -1;
		while (++i < temp)
			ft_lstradd(commands, (a > b) ? ft_lstnew(RA, ft_strlen(RA) + 1) :
			ft_lstnew(RB, ft_strlen(RB) + 1));
		return ;
	}
	temp = ll_i_mn(-a, -b);
	while (++i < temp)
		ft_lstradd(commands, ft_lstnew(RRR, ft_strlen(RRR) + 1));
	temp = ll_i_mx(-a, -b) - temp;
	i = -1;
	while (++i < temp)
		ft_lstradd(commands, (a < b) ? ft_lstnew(RRA, ft_strlen(RRA) + 1) :
		ft_lstnew(RRB, ft_strlen(RRB) + 1));
}

void	ll_add_rotations(t_list **commands, int a, int b)
{
	int temp;
	int i;

	i = -1;
	if (a * b > 0)
		ll_same_direction_rotation(commands, a, b);
	else
	{
		temp = a < 0 ? -a : a;
		while (++i < temp)
			ft_lstradd(commands, (a > 0) ? ft_lstnew(RA, ft_strlen(RA) + 1) :
			ft_lstnew(RRA, ft_strlen(RRA) + 1));
		i = -1;
		temp = b < 0 ? -b : b;
		while (++i < temp)
			ft_lstradd(commands, (b > 0) ? ft_lstnew(RB, ft_strlen(RB) + 1) :
			ft_lstnew(RRB, ft_strlen(RRB) + 1));
	}
}
