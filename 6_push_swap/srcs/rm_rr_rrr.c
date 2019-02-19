/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rm_rr_rrr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 02:18:27 by trhogoro          #+#    #+#             */
/*   Updated: 2019/02/01 02:18:28 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static int	qs_check_rr_rrr(t_list *elem)
{
	if ((ft_strequ((char *)(elem)->content, "ra") &&
		ft_strequ((char *)(elem)->next->content, "rra"))
		|| (ft_strequ((char *)(elem)->content, "rb") &&
		ft_strequ((char *)(elem)->next->content, "rrb"))
		|| (ft_strequ((char *)(elem)->content, "rrb") &&
		ft_strequ((char *)(elem)->next->content, "rb"))
		|| (ft_strequ((char *)(elem)->content, "rra") &&
		ft_strequ((char *)(elem)->next->content, "ra")))
		return (1);
	return (0);
}

static void	qs_remove_rr_rrr(t_list *tmp)
{
	t_list	*tmp2;

	tmp2 = tmp->next;
	tmp->next = tmp->next->next->next;
	ft_lstdelone(&(tmp2->next), ptr_lstdel);
	ft_lstdelone(&(tmp2), ptr_lstdel);
}

static int	qs_remove_rr_rrr_root(t_list **commands)
{
	t_list	*tmp;

	if (qs_check_rr_rrr(*commands))
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
		if (((char *)tmp->next->next->content)[0] != 'r')
			return (0);
		if (qs_check_rr_rrr(tmp->next))
		{
			qs_remove_rr_rrr(tmp);
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

static void	qs_remove_rr_rrr_not_root(t_list **root)
{
	t_list	*tmp;

	if (qs_check_rr_rrr((*root)->next))
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
		if (((char *)tmp->next->next->content)[0] != 'r')
		{
			*root = tmp->next->next;
			return ;
		}
		if (qs_check_rr_rrr(tmp->next))
			return (qs_remove_rr_rrr(tmp));
		tmp = tmp->next;
	}
	*root = 0x0;
}

void		rm_rr_rrr(t_list **commands_q)
{
	t_list	*root;
	int		repeat;

	repeat = 1;
	while (*commands_q && (*commands_q)->next &&
		(((char *)(*commands_q)->content)[0] == 'r') &&
		(((char *)(*commands_q)->next->content)[0] == 'r') && repeat)
		repeat = qs_remove_rr_rrr_root(commands_q);
	root = *commands_q;
	while (root && root->next && root->next->next)
	{
		if ((((char *)root->content)[0] != 'r') &&
			(((char *)root->next->content)[0] == 'r') &&
			(((char *)root->next->next->content)[0] == 'r'))
			qs_remove_rr_rrr_not_root(&root);
		else
			root = root->next;
	}
}
