/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbl_2.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 16:38:52 by trhogoro          #+#    #+#             */
/*   Updated: 2018/12/11 16:42:24 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DBL_2_H
# define DBL_2_H

# include "ft_printf.h"

typedef struct	s_double
{
	char					sign;
	short					exponent;
	unsigned long long int	mantisa;
	char					is_nan;
	char					is_inf;
	char					is_norm;
}				t_double;

typedef struct	s_double_d
{
	char	*int_part;
	char	*frc_part;
	char	is_inf;
	char	is_nan;
	char	sign;
}				t_double_d;

# define MASK_MANTISA 0x000FFFFFFFFFFFFFLU
# define MASK_EXPONENT 0x7FF
# define MASK_SIGN 0x800
# define MASK_INF 0x7FF

# define MASK_EXPONENT_L 0x7FFF
# define MASK_SIGN_L 0x8000
# define MASK_BIT63 0x8000000000000000LU
# define MASK_BIT_0_61 0x3FFFFFFFFFFFFFFFLU

# define DBL_MAXEXP_L 16382
# define DBL_MAXEXP 1023
# define DBL_MANTISA_HIGH_BIT 0x0010000000000000LLU

# define MAX_POWER5 26

# define LONG_DOUBLE_YES 1
# define LONG_DOUBLE_NO 0

t_double		ft_convert_double(double value);
t_double		ft_convert_ldouble(long double value);
t_double_d		ft_dbld_create(t_double dbl, char is_ld);
void			*ft_clear_t_double_d(t_double_d val);

char			*ft_strmltint(char *val1, char *val2);
char			*ft_strmltfrc(char *val1, char *val2);
char			*ft_strpower2(int p);
int				ft_round_double(char *value, int index);
char			*ft_check_dbl2(t_double dbl2);
void			*ft_clear2ptrs(char *val1, char *val2, char *result);
char			*ft_dtoa_g(t_double_d d, t_double_d dg, t_pelem pelem);
char			*ft_dtoa_f(t_double_d d, t_pelem pelem, char is_g);
char			*ft_dtoa_e(t_double_d d, t_pelem pelem);
char			*ft_ldtoa(long double val, t_pelem pelem);

#endif
