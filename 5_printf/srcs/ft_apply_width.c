/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 23:16:43 by trhogoro          #+#    #+#             */
/*   Updated: 2018/12/23 02:30:20 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

static int	ft_apply_width_str(t_pelem pelem, char **value)
{
	char	*temp;

	if (pelem.width > (int)ft_strlen(*value))
	{
		if (!(temp = (char *)malloc((size_t)pelem.width + 1)))
			return (-1);
		if (pelem.flags[FLAG_45])
		{
			ft_strcpy(temp, *value);
			ft_memset(temp + ft_strlen(*value), ' ',
					(size_t)pelem.width - ft_strlen(*value));
			temp[pelem.width] = '\0';
		}
		else
		{
			ft_strcpy(temp + pelem.width - ft_strlen(*value), *value);
			ft_memset(temp, ((F48(pelem)) ? '0' : ' '), (size_t)pelem.width -
				ft_strlen(*value));
		}
		free(*value);
		*value = temp;
		return ((int)ft_strlen(*value));
	}
	return ((int)ft_strlen(*value));
}

static int	ft_apply_width_dbl(t_pelem pelem, char **value)
{
	char *temp;

	if (pelem.width <= (int)ft_strlen(*value))
		return ((int)ft_strlen(*value));
	if (!(temp = (char *)malloc((size_t)pelem.width + 1)))
		return (-1);
	if (pelem.flags[FLAG_45])
	{
		ft_strcpy(temp, *value);
		ft_memset(temp + ft_strlen(*value), ' ', (size_t)pelem.width -
			ft_strlen(*value));
		temp[pelem.width] = '\0';
	}
	else
	{
		ft_strcpy(temp + pelem.width - ft_strlen(*value), *value);
		temp[0] = (*value)[0];
		ft_memset(temp + ((F43(pelem) || F32(pelem)) && F48(pelem) &&
		(pelem.precision == -1)), ((F48(pelem)) ? '0' : ' '),
		pelem.width - ft_strlen(*value));
	}
	free(*value);
	*value = temp;
	return ((int)ft_strlen(*value));
}

static void	ft_apply_width_int2(t_pelem p, char **value, char **temp)
{
	ft_strcpy((*temp) + p.width - ft_strlen(*value), *value);
	if (F35(p) && ft_strchr("xX", p.spec) && F48(p))
	{
		ft_memmove(*temp, *value, 2);
		ft_memset((*temp) + 1 + ((*value)[1] == 'x' || (*value)[1] == 'X'), '0',
			p.width - ft_strlen(*value));
	}
	else
	{
		(*temp)[0] = (*value)[0];
		ft_memset((*temp) + ((F43(p) || F32(p) || (*value)[0] == '-') && F48(p)
		&& (PR(p) == -1)), ((F48(p) && PR(p) == -1) ? '0' : ' '), p.width -
		ft_strlen(*value));
	}
}

static int	ft_apply_width_int(t_pelem p, char **value)
{
	char *temp;

	if (p.width > (int)ft_strlen(*value))
	{
		if (!(temp = (char *)malloc((size_t)p.width + 1)))
			return (-1);
		if (F45(p))
		{
			ft_strcpy(temp, *value);
			ft_memset(temp + ft_strlen(*value), ' ', (size_t)p.width -
			ft_strlen(*value));
			temp[p.width] = '\0';
		}
		else
		{
			ft_apply_width_int2(p, value, &temp);
		}
		free(*value);
		*value = temp;
		return ((int)ft_strlen(*value));
	}
	return ((int)ft_strlen(*value));
}

int			ft_apply_width(t_pelem pelem, char **value)
{
	if (pelem.spec == 'p')
	{
		pelem.spec = 'x';
		pelem.flags[FLAG_35] = 1;
	}
	if (ft_strchr("diuoxXb", pelem.spec))
		return (ft_apply_width_int(pelem, value));
	if (ft_strchr("c", pelem.spec) && (*value[0] == 0))
		return (ft_apply_width_eol(pelem, value));
	if (ft_strchr("csrk", pelem.spec))
		return (ft_apply_width_str(pelem, value));
	if (ft_strchr("fFeEgG", pelem.spec))
		return (ft_apply_width_dbl(pelem, value));
	return (-1);
}
