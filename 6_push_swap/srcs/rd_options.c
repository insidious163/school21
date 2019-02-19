/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rd_options.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 02:14:57 by trhogoro          #+#    #+#             */
/*   Updated: 2019/02/01 02:14:58 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	read_option(char *option, int *options, char *available)
{
	int bit;

	if (!option || !options || (ft_strlen(option) < 2))
		return (er_error(E_PARAMS));
	option++;
	while (*option)
	{
		if (!ft_strchr(available, *option))
			return (er_error(E_PARAMS));
		bit = 1 << (*option - 'a');
		if (!(*options & bit))
			*options += bit;
		option++;
	}
}

int		rd_options(int ac, char **av, char *available)
{
	int i;
	int options;

	i = 1;
	options = 0;
	if (ac == 1)
		options += (1 << ('h' - 'a'));
	while ((i < ac) && (av[i][0] == '-') && (ft_strlen(av[i]) > 1) &&
		(ft_isalpha(av[i][1])))
	{
		read_option(av[i++], &options, available);
	}
	return (options);
}
