/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_detoa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 18:08:44 by trhogoro          #+#    #+#             */
/*   Updated: 2018/12/11 16:59:20 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dbl_2.h"
#include "ft_printf.h"
#include <stdlib.h>

static char		*dtoa_e2(t_double_d d, t_pelem pelem, char **temp, int exp)
{
	int		len;
	char	*result;

	len = d.sign + PR(pelem) + 5 + (PR(pelem) != 0) + (exp > 99) + (exp < -99);
	if (!(result = ft_strnew((size_t)len)))
	{
		free(*temp);
		*temp = 0x0;
		return (ft_clear_t_double_d(d));
	}
	ft_memset(result, '0', (size_t)len);
	result[0] = (char)(d.sign ? '-' : '0');
	return (result);
}

static void		dtoa_e3(t_double_d d, char *temp, int exp)
{
	*temp++ = 'e';
	*temp++ = (char)((exp < 0) ? '-' : '+');
	exp = (exp < 0) ? -exp : exp;
	*temp++ = (char)('0' + (exp >= 100 ? exp / 100 : exp / 10));
	*temp++ = (char)('0' + (exp >= 100 ? (exp / 10) % 10 : exp % 10));
	*temp = (char)((exp >= 100) ? '0' + exp % 10 : '\0');
	ft_clear_t_double_d(d);
}

static int		dtoa_e4(t_double_d d, char **temp, int *exp)
{
	if (!((*temp) = ft_strjoin(d.int_part, d.frc_part)))
	{
		ft_clear_t_double_d(d);
		return (0);
	}
	*exp = 0;
	while ((*temp)[-(*exp)] == '0')
		(*exp)--;
	return (1);
}

char			*ft_dtoa_e(t_double_d d, t_pelem pelem)
{
	char	*temp;
	int		extra;
	char	*result;
	int		exp;
	int		index;

	if (!(dtoa_e4(d, &temp, &exp)))
		return (0x0);
	extra = ft_round_double(temp, -exp + pelem.precision + 1);
	exp = (int)(!exp ? ft_strlen(d.int_part) - 1 : exp);
	if (!(result = dtoa_e2(d, pelem, &temp, exp)))
		return (0x0);
	index = 0;
	while (!extra && (temp[index] == '0'))
		index++;
	if (temp[index])
		result[(int)d.sign] = (char)(extra ? '1' : temp[index]);
	if (temp[index])
		ft_memmove(result + d.sign + 2, temp + index + 1, pelem.precision);
	else
		exp = 0;
	(pelem.precision) ? result[d.sign + 1] = '.' : (void)0;
	free(temp);
	dtoa_e3(d, result + d.sign + 1 + PR(pelem) + (PR(pelem) != 0), exp);
	return (result);
}
