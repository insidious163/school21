/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl_clear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 02:16:24 by trhogoro          #+#    #+#             */
/*   Updated: 2019/01/31 02:23:52 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	cl_clear(t_lst2 **stack_a, t_lst2 **stack_b, t_list **cmd_ll,
		t_list **cmd_qs)
{
	stack_a ? ft_lst2del(stack_a, ptr_lstdel) : (void)0;
	stack_b ? ft_lst2del(stack_b, ptr_lstdel) : (void)0;
	cmd_ll ? ft_lstdel(cmd_ll, ptr_lstdel) : (void)0;
	cmd_qs ? ft_lstdel(cmd_qs, ptr_lstdel) : (void)0;
}
