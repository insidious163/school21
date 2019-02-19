/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 19:02:59 by trhogoro          #+#    #+#             */
/*   Updated: 2018/11/22 00:35:06 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static char	*ft_remove_spaces(char *str)
{
	while (*str)
	{
		if ((*str == '\n') || (*str == '\t') || (*str == '\v')
				|| (*str == ' ') || (*str == '\r') || (*str == '\f'))
			str++;
		else
			return (str);
	}
	return (str);
}

int			ft_atoi(const char *str)
{
	char	*temp;
	long	result;

	result = 1;
	if (!*str)
		return (0);
	temp = ft_remove_spaces((char *)str);
	if ((*temp == '-') || (*temp == '+'))
		result = ((*temp++ == '-') ? -1 : 1);
	while (*temp == '0')
		temp++;
	if ((*temp < '0') || (*temp > '9'))
		return (0);
	result *= (*temp++ - '0');
	while ((*temp >= '0') && (*temp <= '9'))
	{
		if ((result < 0) && (result * 10 - (*temp - '0') < 0))
			result = result * 10 - (*temp++ - '0');
		else if ((result >= 0) && (result * 10 + (*temp - '0') >= 0))
			result = result * 10 + (*temp++ - '0');
		else
			return (-1 * (result > 0));
	}
	return (result);
}
