/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_output.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrot <kcarrot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 10:29:06 by kcarrot           #+#    #+#             */
/*   Updated: 2019/02/08 10:29:09 by kcarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_error_output(t_farm *farm, const char *error_message)
{
	ft_putstr("ERROR\n");
	ft_putstr(error_message);
	ft_putchar('\n');
	ft_farm_destroyer(farm);
	exit(0);
}
