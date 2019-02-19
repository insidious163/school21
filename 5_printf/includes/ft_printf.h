/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 16:21:41 by trhogoro          #+#    #+#             */
/*   Updated: 2018/12/23 02:39:13 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_FT_PRINTF_H
# define PRINTF_FT_PRINTF_H

# include <inttypes.h>
# include <stdarg.h>
# include "libft.h"
# include <sys/types.h>

# define DEFAULT_FD 1
# define CLR_DEFAULT "\x1b[0m"
# define CLR_PREFIX "\x1b[38;5;"
# define CLR_SUFFIX "m"

# define FLAGS_COUNT 5
# define FLAGS "#0+- "
# define FLAG_35 0
# define FLAG_48 1
# define FLAG_43 2
# define FLAG_45 3
# define FLAG_32 4
# define FLAG_39 5

# define F35(p) p.flags[FLAG_35]
# define F48(p) p.flags[FLAG_48]
# define F43(p) p.flags[FLAG_43]
# define F45(p) p.flags[FLAG_45]
# define F32(p) p.flags[FLAG_32]
# define F39(p) p.flags[FLAG_39]

# define DEFAULT_PRECISION -1
# define POINT '.'
# define NUM_DBL 1
# define NUM_INT 2
# define NUM_NOT 3

# define L_0 0
# define L_HH 1
# define L_H 2
# define L_L 3
# define L_LL 4
# define L_J 5
# define L_Z 6
# define L_L_D 7

# define SPEC "csprdiouxXbfFeEgG"
# define SPEC_UP "DIOUSC"
# define SPEC_INT "diouxXb"
# define SPEC_STR "csr"
# define SPEC_DBL "fegFEG"
# define SIGNED 1
# define UNSIGNED 0
# define DEC 10
# define OCT 8
# define HEX 16
# define BIN 2

# define ERROR 1
# define SUCCESS 0

# define IL(d) ft_strlen(d.int_part)
# define PR(pelem) (pelem.precision)

typedef struct	s_pelem
{
	char	flags[FLAGS_COUNT];
	int		width;
	int		precision;
	char	length;
	char	spec;
}				t_pelem;

char			*ft_ctoa_base(char c, char base, char sign);
char			*ft_stoa_base(short s, char base, char sign);
char			*ft_itoa_base(int i, char base, char sign);
char			*ft_litoa_base(long int li, char base, char sign);
char			*ft_llitoa_base(long long int lli, char base, char sign);
char			*ft_imtoa_base(intmax_t im, char base, char sign);
char			*ft_sttoa_base(ssize_t st, char base, char sign);
char			*ft_dtoa(double val, t_pelem pelem);
char			*ft_str_nonprintable(char *str);
void			ft_check_color(int fd, char *format, int *count, int *printed);

int				ft_format(int fd, char *format, int *count, va_list *ap);
int				ft_check_flags(char *format, t_pelem *pelem);
int				ft_check_width(char *format, t_pelem *pelem, va_list *ap);
int				ft_check_precision(char *format, t_pelem *pelem, va_list *ap);
int				ft_check_len_flag(char *format, t_pelem *pelem);
int				ft_check_specificator(char *format, t_pelem *pelem);
int				ft_apply_format(t_pelem pelem, char **value);
int				ft_apply_precision(t_pelem pelem, char **value);
int				ft_apply_flag35(t_pelem pelem, char **value);
int				ft_apply_flag32(t_pelem pelem, char **value);
int				ft_apply_flag43(t_pelem pelem, char **value);
int				ft_apply_width(t_pelem pelem, char **value);
int				ft_apply_width_eol(t_pelem pelem, char **value);
void			ft_validate_pelem(t_pelem *pelem);
char			*ft_convert_tostr(int **temp, size_t len);
char			*ft_remove_zeros(char *result);

char			*ft_print_l_0(t_pelem *pelem, va_list *ap);
char			*ft_print_l_h(t_pelem pelem, va_list *ap);
char			*ft_print_l_hh(t_pelem pelem, va_list *ap);
char			*ft_print_l_l(t_pelem *pelem, va_list *ap);
char			*ft_print_l_ll(t_pelem pelem, va_list *ap);
char			*ft_print_l_ldbl(t_pelem pelem, va_list *ap);
char			*ft_print_l_j(t_pelem pelem, va_list *ap);
char			*ft_print_l_z(t_pelem pelem, va_list *ap);

int				ft_vprint(int fd, char *format, va_list *ap);

#endif
