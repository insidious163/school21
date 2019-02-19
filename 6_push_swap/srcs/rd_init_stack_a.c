/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rd_init_stack_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 02:14:49 by trhogoro          #+#    #+#             */
/*   Updated: 2019/02/01 02:14:51 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

static void	ft_del_split(char **split)
{
	int i;

	i = 0;
	while (split[i])
	{
		free(split[i++]);
	}
	free(split);
}

static void	rd_init_stack_split(char *stack_str, t_lst2 **stack_a)
{
	int		i;
	char	**val;
	char	*itoa;
	t_info	elem;

	i = 0;
	val = ft_strsplit(stack_str, ' ');
	while (val[i])
	{
		if (!ft_strequ((itoa = ft_itoa(ft_atoi(val[i]))), val[i]))
		{
			ft_del_split(val);
			er_error(E_NOTINT);
		}
		free(itoa);
		elem.value = ft_atoi(val[i]);
		ft_lst2add_last(stack_a, ft_lst2new(&elem, sizeof(elem)));
		i++;
	}
	ft_del_split(val);
}

static void	rd_init_stack_non_split(int i, int ac, char **av, t_lst2 **stack_a)
{
	char	*itoa;
	t_info	elem;

	while (i <= ac - 1)
	{
		if (!ft_strequ(itoa = ft_itoa(ft_atoi(av[i])), av[i]))
			er_error(E_NOTINT);
		free(itoa);
		elem.value = ft_atoi(av[i]);
		ft_lst2add_last(stack_a, ft_lst2new(&elem, sizeof(elem)));
		i++;
	}
}

void		rd_init_stack_a(int ac, char **av, t_lst2 **stack_a)
{
	int	i;

	i = 1;
	if (ac == 1)
		er_error(E_EMPTY);
	while (i < ac && av[i][0] == '-' && (ft_strlen(av[i]) > 1) &&
		(ft_isalpha(av[i][1])))
	{
		i++;
	}
	if (i == ac)
		er_error(E_PARAMS);
	if (i == ac - 1)
		return (rd_init_stack_split(av[ac - 1], stack_a));
	else
		return (rd_init_stack_non_split(i, ac, av, stack_a));
}
