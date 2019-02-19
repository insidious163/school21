/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbtforeach_p.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 22:12:54 by trhogoro          #+#    #+#             */
/*   Updated: 2019/01/31 02:14:29 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_rbtforeach_pre(t_rbtree *root,
		void (*f)(t_rbtree *elem, void *params), void *params)
{
	if (root->content)
		f(root, params);
	if (root->left->content)
		ft_rbtforeach_pre(root->left, f, params);
	if (root->right->content)
		ft_rbtforeach_pre(root->right, f, params);
}

static void	ft_rbtforeach_in(t_rbtree *root,
		void (*f)(t_rbtree *elem, void *params), void *params)
{
	if (root->left->content)
		ft_rbtforeach_in(root->left, f, params);
	if (root->content)
		f(root, params);
	if (root->right->content)
		ft_rbtforeach_in(root->right, f, params);
}

static void	ft_rbtforeach_post(t_rbtree *root,
		void (*f)(t_rbtree *elem, void *params), void *params)
{
	if (root->left->content)
		ft_rbtforeach_post(root->left, f, params);
	if (root->right->content)
		ft_rbtforeach_post(root->right, f, params);
	if (root->content)
		f(root, params);
}

void		ft_rbtforeach_p(t_rbtree *root,
		void (*f)(t_rbtree *elem, void *params), int order, void *params)
{
	if (!root || !f)
		return ;
	if (order == PREFIX)
	{
		ft_rbtforeach_pre(root, f, params);
	}
	else if (order == INFIX)
	{
		ft_rbtforeach_in(root, f, params);
	}
	else if (order == POSTFIX)
	{
		ft_rbtforeach_post(root, f, params);
	}
}
