/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrot <kcarrot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 18:36:20 by kcarrot           #+#    #+#             */
/*   Updated: 2019/02/08 03:44:47 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				total_path_len(int *i, int ants, size_t *path_len)
{
	int p_num;
	int res;
	int len;

	len = 0;
	p_num = 0;
	while (i[p_num] != -1)
	{
		len += path_len[i[p_num]];
		p_num++;
	}
	res = (len % p_num) ? len / p_num + 1 : len / p_num;
	res += (ants % p_num) ? ants / p_num : ants / p_num - 1;
	return (res);
}

static int		preparations(int *res, int *n)
{
	int	end;
	int mv;

	end = 0;
	while (res[end] != -1)
		end++;
	res[end] = *n;
	*n = (*n < 0) ? 0 : *n + 1;
	mv = 7 - *n % 8;
	*n = *n / 8;
	return (mv);
}

int				*recursion(t_path_set *set, int *res,
							unsigned char **cross_m, int n)
{
	int	ii;
	int	mv;
	int end;
	int	*res2;

	mv = preparations(res, &n) + 1;
	end = set->num_of_paths / 8 + (set->num_of_paths % 8) ? 1 : 0;
	while (n < end)
	{
		while (--mv >= 0)
			if (no_crosses(cross_m, res, n, mv))
			{
				ii = n * 8 + (7 - mv);
				res2 = recursion(set, res, cross_m, ii);
				if (total_path_len(res2, set->ants_count, set->lens) <
					total_path_len(res, set->ants_count, set->lens))
				{
					free(res);
					res = res2;
				}
			}
		n++;
		mv = 8;
	}
	return (res);
}

int				*check_each_comb(unsigned char **cross_m,
					t_path_set *set, int i)
{
	int				*res;
	unsigned long	j;

	j = 0;
	res = (int*)malloc(sizeof(int) * (set->num_of_paths + 1));
	while (j <= set->num_of_paths)
		res[j++] = -1;
	res[0] = i;
	res = recursion(set, res, cross_m, -1);
	return (res);
}

int				*find_best_path(size_t ants, t_path_set *set,
					unsigned char **cross_m)
{
	int		min;
	int		*res;
	int		*res2;
	size_t	i;

	i = 0;
	min = (set->lens)[0] + ants - 1;
	res = (int*)malloc(sizeof(int) * 2);
	res[0] = 0;
	res[1] = -1;
	i = 0;
	while (i < set->num_of_paths)
	{
		res2 = check_each_comb(cross_m, set, i);
		if (total_path_len(res2, ants, set->lens) < min)
		{
			free(res);
			res = res2;
			min = total_path_len(res, ants, set->lens);
		}
		else
			free(res2);
		i++;
	}
	return (res);
}
