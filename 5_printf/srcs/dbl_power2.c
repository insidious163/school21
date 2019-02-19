/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbl_power2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 22:38:12 by trhogoro          #+#    #+#             */
/*   Updated: 2018/12/11 16:09:57 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "dbl_2.h"

static char	*ft_strpower2pos(size_t p)
{
	long long int	value;
	char			*val1;
	char			*val2;
	char			*result;

	if (p <= 63)
	{
		value = 1;
		while ((p--))
			value = value << 1;
		return (ft_llitoa_base(value, 10, 0));
	}
	if (!(val1 = ft_strpower2pos(p / 2)))
		return (0x0);
	if (!(val2 = ft_strpower2pos(p / 2 + p % 2)))
	{
		free(val1);
		return (0x0);
	}
	result = ft_strmltint(val1, val2);
	free(val1);
	free(val2);
	return (result);
}

static char	*ft_strpower2neglow(size_t p)
{
	char			*result;
	long long int	value;
	size_t			i;
	char			*llitoa;

	value = 1;
	i = p;
	while (i--)
		value *= 5;
	llitoa = ft_llitoa_base(value, 10, 0);
	if ((result = ft_strnew(p)))
	{
		ft_memset(result, '0', p);
		ft_memmove(result + (p - ft_strlen(llitoa)), llitoa, ft_strlen(llitoa));
	}
	free(llitoa);
	return (result);
}

static char	*ft_strpower2neg(size_t p)
{
	char			*result;
	char			*val1;
	char			*val2;

	if (p <= MAX_POWER5)
	{
		return (ft_strpower2neglow(p));
	}
	if (!(val1 = ft_strpower2neg(p / 2)))
		return (0x0);
	if (!(val2 = ft_strpower2neg(p / 2 + p % 2)))
	{
		free(val1);
		return (0x0);
	}
	result = ft_strmltfrc(val1, val2);
	free(val1);
	free(val2);
	return (result);
}

char		*ft_strpower2(int p)
{
	if (p >= 0)
		return (ft_strpower2pos((size_t)p));
	else
		return (ft_strpower2neg((size_t)(-p)));
}
