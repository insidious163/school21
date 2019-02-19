/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbl_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 22:44:56 by trhogoro          #+#    #+#             */
/*   Updated: 2018/12/11 16:57:22 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dbl_2.h"
#include <stdlib.h>

void	*ft_clear2ptrs(char *val1, char *val2, char *result)
{
	if (val1)
		free(val1);
	if (val2)
		free(val2);
	return (result);
}

char	*ft_check_dbl2(t_double dbl2)
{
	if (dbl2.is_nan)
		return (ft_strcpy(ft_strnew(3), "NaN"));
	if (dbl2.is_inf && dbl2.sign)
		return (ft_strcpy(ft_strnew(4), "-inf"));
	if (dbl2.is_inf && !dbl2.sign)
		return (ft_strcpy(ft_strnew(3), "inf"));
	return (0x0);
}

int		ft_round_double(char *value, int index)
{
	int		extra;
	char	*temp;

	extra = 0;
	if (ft_strlen(value) < (size_t)index)
		return (0);
	if (value[index] == '5')
	{
		temp = value + index + 1;
		while (*temp++)
			extra = (*temp != '0' ? 1 : extra);
	}
	else
		extra = value[index] > '5';
	while (extra && (--index >= 0))
	{
		value[index] = (char)(value[index] == '9' ? '0' : value[index] + 1);
		extra = (value[index] == '0');
	}
	return (extra);
}

void	*ft_clear_t_double_d(t_double_d val)
{
	if (val.frc_part)
		free(val.frc_part);
	if (val.int_part)
		free(val.int_part);
	return (0x0);
}
