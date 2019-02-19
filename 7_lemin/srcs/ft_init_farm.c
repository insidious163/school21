/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_farm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrot <kcarrot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 10:29:17 by kcarrot           #+#    #+#             */
/*   Updated: 2019/02/08 14:06:50 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		ft_read_ants_count(t_farm *farm, char **data)
{
	size_t	i;

	while (get_next_line(0, data) == 1)
	{
		ft_lstradd(&(farm->output), ft_lstnew(*data, ft_strlen(*data) + 1));
		if (ft_is_comment(*data))
		{
			ft_memdel((void**)data);
			continue ;
		}
		break ;
	}
	(*data == NULL) ? ft_error_output(farm, "No input data") : (void)0;
	i = 0;
	while ((*data)[i])
	{
		if (!(ft_isdigit((*data)[i])))
			ft_error_output(farm, "Wrong format for ants count");
		i++;
	}
	farm->ants_count = (size_t)ft_atoi(*data);
	if (farm->ants_count > INT_MAX)
		ft_error_output(farm, "Integer owerflow");
	ft_ants_generator(farm);
	free(*data);
}

int				ft_is_comment(char *input_data)
{
	if (input_data)
	{
		if (input_data[0] == '#')
			return (1);
	}
	return (0);
}

t_farm			*ft_init_farm(void)
{
	t_farm	*farm;
	char	*input_data;

	input_data = NULL;
	farm = ft_create_farm();
	ft_read_ants_count(farm, &input_data);
	ft_read_rooms(farm, &input_data);
	ft_rooms_reverse(&farm->rooms);
	return (farm);
}
