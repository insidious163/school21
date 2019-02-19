/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strjoin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 19:39:18 by trhogoro          #+#    #+#             */
/*   Updated: 2018/11/20 06:14:27 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		len;
	char	*result;

	if (!s1 || !s2)
		return (0x0);
	len = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	result = (char *)malloc(len + 1);
	if (result)
	{
		i = 0;
		while (*s1++)
			result[i++] = *(s1 - 1);
		while (*s2++)
			result[i++] = *(s2 - 1);
		result[i] = '\0';
	}
	return (result);
}
