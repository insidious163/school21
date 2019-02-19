/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_width_eol.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 04:12:35 by trhogoro          #+#    #+#             */
/*   Updated: 2018/12/20 04:12:43 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

int		ft_apply_width_eol(t_pelem pelem, char **value)
{
	char	*temp;

	if (pelem.width == 0)
		pelem.width = 1;
	if (!(temp = (char *)malloc((size_t)pelem.width)))
		return (-1);
	if (pelem.flags[FLAG_45])
	{
		temp[0] = '\0';
		ft_memset(temp + 1, ' ', (size_t)pelem.width);
	}
	else
	{
		ft_memset(temp, F48(pelem) ? '0' : ' ', (size_t)pelem.width - 1);
		temp[pelem.width - 1] = '\0';
	}
	free(*value);
	*value = temp;
	return (pelem.width);
}
