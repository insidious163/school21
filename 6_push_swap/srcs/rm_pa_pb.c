/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rm_pa_pb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 02:18:21 by trhogoro          #+#    #+#             */
/*   Updated: 2019/02/01 02:18:22 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static int	qs_check_pa_pb(t_list *elem)
{
	if ((ft_strequ((char *)(elem)->content, "pa") &&
		ft_strequ((char *)(elem)->next->content, "pb")) ||
		(ft_strequ((char *)(elem)->content, "pb") &&
		ft_strequ((char *)(elem)->next->content, "pa")))
		return (1);
	return (0);
}

static void	qs_remove_pa_pb(t_list *tmp)
{
	t_list	*tmp2;

	tmp2 = tmp->next;
	tmp->next = tmp->next->next->next;
	ft_lstdelone(&(tmp2->next), ptr_lstdel);
	ft_lstdelone(&(tmp2), ptr_lstdel);
}

static int	qs_remove_pa_pb_root(t_list **commands)
{
	t_list	*tmp;

	if (qs_check_pa_pb(*commands))
	{
		tmp = (*commands)->next->next;
		ft_lstdelone(&((*commands)->next), ptr_lstdel);
		ft_lstdelone(commands, ptr_lstdel);
		*commands = tmp;
		return (1);
	}
	tmp = *commands;
	while (tmp && tmp->next && tmp->next->next)
	{
		if (((char *)tmp->next->next->content)[0] != 'p')
			return (0);
		if (qs_check_pa_pb(tmp->next))
		{
			qs_remove_pa_pb(tmp);
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

static void	qs_remove_pa_pb_not_root(t_list **root)
{
	t_list	*tmp;

	if (qs_check_pa_pb((*root)->next))
	{
		tmp = (*root)->next;
		(*root)->next = (*root)->next->next->next;
		ft_lstdelone(&(tmp->next), ptr_lstdel);
		ft_lstdelone(&tmp, ptr_lstdel);
		return ;
	}
	tmp = *root;
	while (tmp && tmp->next && tmp->next->next)
	{
		if (((char *)tmp->next->next->content)[0] != 'p')
		{
			*root = tmp->next->next;
			return ;
		}
		if (qs_check_pa_pb(tmp->next))
			return (qs_remove_pa_pb(tmp));
		tmp = tmp->next;
	}
	*root = 0x0;
}

void		rm_pa_pb(t_list **commands_q)
{
	t_list	*root;
	int		repeat;

	repeat = 1;
	while (*commands_q && (*commands_q)->next &&
		(((char *)(*commands_q)->content)[0] == 'p') &&
		(((char *)(*commands_q)->next->content)[0] == 'p') && repeat)
	{
		repeat = qs_remove_pa_pb_root(commands_q);
	}
	root = *commands_q;
	while (root && root->next && root->next->next)
	{
		if ((((char *)root->content)[0] != 'p') &&
			(((char *)root->next->content)[0] == 'p') &&
			(((char *)root->next->next->content)[0] == 'p'))
			qs_remove_pa_pb_not_root(&root);
		else
			root = root->next;
	}
}
