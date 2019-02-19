/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_pelem.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 02:34:42 by trhogoro          #+#    #+#             */
/*   Updated: 2018/12/23 02:37:41 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_validate_pelem(t_pelem *pelem)
{
	if ((pelem->flags[FLAG_43]) && (pelem->flags[FLAG_32]))
		pelem->flags[FLAG_32] = 0;
	else if (ft_strchr("p", pelem->spec))
		pelem->length = L_0;
	else if (ft_strchr(SPEC_STR, pelem->spec))
	{
		if (pelem->length != L_L)
			pelem->length = L_0;
	}
	else if (ft_strchr(SPEC_DBL, pelem->spec))
	{
		if (pelem->length != L_L_D)
			pelem->length = L_0;
	}
}
