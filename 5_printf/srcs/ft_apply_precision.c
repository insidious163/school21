/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_precision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 23:16:28 by trhogoro          #+#    #+#             */
/*   Updated: 2018/12/23 02:32:23 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

static int	ft_apply_precision_int(t_pelem pelem, char **value)
{
	char	*temp;
	size_t	len;

	if ((ft_strlen(*value) - ((*value)[0] == '-')) < (size_t)pelem.precision)
	{
		len = (size_t)pelem.precision + 1 + ((*value)[0] == '-');
		if (!(temp = (char *)malloc(len)))
			return (ERROR);
		ft_memset(temp, '0', len);
		ft_strcpy(temp + (len - 1 - ft_strlen(*value)), *value);
		if ((*value)[0] == '-')
		{
			temp[0] = '-';
			temp[len - 1 - ft_strlen(*value)] = '0';
		}
		free(*value);
		*value = temp;
		return (SUCCESS);
	}
	else if ((ft_strlen(*value) == 1) && ((*value)[0] == '0') &&
		(pelem.precision <= 0))
		(*value)[0] = '\0';
	return (SUCCESS);
}

static int	ft_apply_precision_str(t_pelem pelem, char **value)
{
	size_t	index;
	size_t	temp;

	temp = 0;
	if (pelem.length != L_L)
	{
		if ((int)ft_strlen(*value) > pelem.precision)
			(*value)[pelem.precision] = '\0';
	}
	else if (ft_strlen(*value) > (size_t)pelem.precision)
	{
		index = 0;
		while (index <= (size_t)pelem.precision)
		{
			temp = index;
			if (((*value)[index] & 0x80) == 0)
				index++;
			else if (((*value)[index] & 0xE0) == 0xC0)
				index += 2;
			else if (((*value)[index] & 0xF0) == 0xE0)
				index += 3;
		}
		(*value)[temp] = '\0';
	}
	return (SUCCESS);
}

static int	ft_apply_precision_ptr(t_pelem pelem, char **value)
{
	char *temp;

	if (ft_strequ("0", *value) && !pelem.precision)
	{
		*value[0] = '\0';
	}
	else if (ft_strlen(*value) < (size_t)pelem.precision)
	{
		if (!(temp = (char *)malloc((size_t)pelem.precision + 1)))
			return (ERROR);
		temp[pelem.precision] = '\0';
		ft_memset(temp, '0', (size_t)pelem.precision);
		ft_strcpy(temp + ((size_t)pelem.precision - ft_strlen(*value)), *value);
		free(*value);
		*value = temp;
		return (SUCCESS);
	}
	return (SUCCESS);
}

int			ft_apply_precision(t_pelem pelem, char **value)
{
	if (pelem.precision < 0)
		return (SUCCESS);
	if (ft_strchr(SPEC_INT, pelem.spec))
		return (ft_apply_precision_int(pelem, value));
	if (pelem.spec == 's')
		return (ft_apply_precision_str(pelem, value));
	if (pelem.spec == 'p')
		return (ft_apply_precision_ptr(pelem, value));
	return (SUCCESS);
}
