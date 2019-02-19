/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 23:03:20 by trhogoro          #+#    #+#             */
/*   Updated: 2019/01/31 23:03:21 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "push_swap.h"

void	ptr_lstprint(t_list *lst)
{
	ft_putendl(lst->content);
}

void	ptr_lstdel(void *content, size_t content_size)
{
	if (content_size && content)
		free(content);
}

void	ptr_stackdel(void *content, size_t content_size)
{
	if (content_size && content)
		free(content);
}

void	ptr_lstminidel(void *content, size_t content_size)
{
	if (content_size && content)
	{
		free(((t_mini *)content)->cmd);
		free(content);
	}
}

int		ptr_valuecmp(t_list *elem1, t_list *elem2)
{
	int a;
	int b;

	a = ((t_info *)elem1->content)->value;
	b = ((t_info *)elem2->content)->value;
	if (a < b)
		return (-1);
	if (a == b)
		return (0);
	return (1);
}
