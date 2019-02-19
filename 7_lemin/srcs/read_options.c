/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_options.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrot <kcarrot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 16:25:21 by kcarrot           #+#    #+#             */
/*   Updated: 2019/02/08 12:19:19 by kcarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	er_error(char *err)
{
	ft_putendl(err);
}

void	read_option(char *option, int *options, char *available)
{
	int bit;

	if (!option || !options || (ft_strlen(option) < 2))
	{
		*options = (1 << ('h' - 'a'));
		return ;
	}
	option++;
	while (*option)
	{
		if (!ft_strchr(available, *option))
		{
			*options = (1 << ('h' - 'a'));
			return ;
		}
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
	while (i < ac)
	{
		if (av[i][0] != '-')
			return (1 << ('h' - 'a'));
		read_option(av[i++], &options, available);
		if ((options >> ('h' - 'a')) & 1)
			return (options);
	}
	return (options);
}
