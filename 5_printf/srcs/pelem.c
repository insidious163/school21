/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pelem.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 00:50:17 by trhogoro          #+#    #+#             */
/*   Updated: 2018/12/11 16:43:50 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_set_flags(t_pelem *pelem, t_list *elem)
{
	char	last_flag;
	char	*content;
	size_t	index;

	content = (char *)elem->content;
	last_flag = 0;
	while (*content)
	{
		if ((ft_strchr(FLAGS, *content)) && (*content != last_flag))
		{
			last_flag = *content;
			index = ft_strchr(FLAGS, *content) - FLAGS;
			pelem->flags[index] = 1;
		}
		else
			return (1);
	}
	return (0);
}

static int	ft_set_width(t_pelem *pelem, t_list *elem)
{
	char	*content;
	size_t	index;

	content = (char *)elem->content;
	while (*content && ((!ft_isdigit(*content)) || (*content == '0')))
		content++;
	if (*content)
	{
		index = content - (char *)elem->content;
		while (*content)
		{
			if (ft_isdigit(*content))
				pelem->width = 10 * pelem->width + *content - '0';
			else
				return (1);
		}
		((char *)elem->content)[index] = '\0';
	}
	return (ft_set_flags(pelem, elem));
}

static int	ft_set_precision(t_pelem *pelem, t_list *elem)
{
	char	*content;
	size_t	index;

	content = (char *)elem->content;
	if (ft_strchr(content, '.'))
	{
		index = ft_strchr(content, '.') - content;
		while (content[++index])
		{
			if (ft_isdigit(content[index]))
				pelem->precision = pelem->precision * 10 + content[index] - '0';
			else
				return (1);
		}
		((char *)(elem->content))[index] = '\0';
	}
	return (ft_set_width(pelem, elem));
}

static int	ft_set_length(t_pelem *pelem, t_list *elem)
{
	char	*content;
	int		len;

	content = (char *)elem->content;
	len = ft_strlen(content);
	if (len > 1)
	{
		if (content[len - 1] == 'l')
			((len > 2) && (content[len - 2] == 'l')) ? (pelem->length = L_LL)
				: (pelem->length = L_L);
		else if (content[len - 1] == 'h')
			((len > 2) && (content[len - 2] == 'h')) ? (pelem->length = L_HH)
				: (pelem->length = L_H);
	}
	if (pelem->length != 0)
		((char *)(elem->content))[len - 1] = '\0';
	if ((pelem->length == L_HH) || (pelem->length == L_LL))
		((char *)(elem->content))[len - 2] = '\0';
	return (ft_set_precision(pelem, elem));
}

int			ft_set_pelem(t_pelem *pelem, t_list *elem)
{
	size_t	size;
	char	*content;

	content = (char *)elem->content;
	size = elem->content_size;
	if (!ft_strchr(SPEC, (content[size - 1])))
		return (1);
	pelem->spec = (content)[size - 1];
	(content)[size - 1] = '\0';
	return (ft_set_length(pelem, elem));
}
