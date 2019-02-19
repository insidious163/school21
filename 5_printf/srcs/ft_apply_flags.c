/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 23:16:15 by trhogoro          #+#    #+#             */
/*   Updated: 2018/12/20 04:12:19 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

static int	ft_iszero(char *value)
{
	while (*value)
	{
		if (*value != '0')
			return (0);
		value++;
	}
	return (1);
}

int			ft_apply_flag35(t_pelem p, char **v)
{
	char	*temp;
	size_t	len;

	if (!(((ft_strchr("oxX", p.spec) && F35(p))) || (p.spec == 'p')))
		return (SUCCESS);
	(!(*v)[0] && p.spec == 'o') ? free(*v) : (void)0;
	*v = ((!(*v)[0] && p.spec == 'o') ? ft_memset(ft_strnew(2), '0', 1) : *v);
	if ((ft_iszero(*v) && p.spec != 'p') ||
		((ft_strchr("o", p.spec) && (*v)[0] == '0')))
		return (SUCCESS);
	len = (size_t)ft_strlen(*v);
	(ft_strchr("o", p.spec)) ? (len += 1) : (len += 2);
	if (!(temp = (char *)malloc(len + 1)))
		return (ERROR);
	ft_strcpy(temp + len - ft_strlen(*v), *v);
	temp[0] = '0';
	if (ft_strchr("xp", p.spec))
		temp[1] = 'x';
	else if (p.spec == 'X')
		temp[1] = 'X';
	free(*v);
	*v = temp;
	return (SUCCESS);
}

int			ft_apply_flag32(t_pelem pelem, char **value)
{
	char	*temp;

	if ((ft_strchr("digfeGFE", pelem.spec)) && (!(pelem.flags[FLAG_43])) &&
		(pelem.flags[FLAG_32]) && ((*value)[0] != '-'))
	{
		if (!(temp = (char *)malloc((size_t)ft_strlen(*value) + 2)))
			return (ERROR);
		ft_strcpy(temp + 1, *value);
		temp[0] = ' ';
		free(*value);
		*value = temp;
		return (SUCCESS);
	}
	return (SUCCESS);
}

int			ft_apply_flag43(t_pelem pelem, char **value)
{
	char	*temp;

	if (ft_strchr("digfeGFE", pelem.spec) && ((*value)[0] != '-') &&
		(pelem.flags[FLAG_43]))
	{
		if (!(temp = (char *)malloc((size_t)ft_strlen(*value) + 2)))
			return (ERROR);
		ft_strcpy(temp + 1, *value);
		temp[0] = '+';
		free(*value);
		*value = temp;
		return (SUCCESS);
	}
	return (SUCCESS);
}
