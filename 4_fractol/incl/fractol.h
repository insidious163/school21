/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 22:49:08 by trhogoro          #+#    #+#             */
/*   Updated: 2019/01/09 22:49:09 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

typedef struct	s_point
{
	double	x;
	double	y;
	int		xi;
	int		yi;
}				t_point;

typedef struct	s_params
{
	void			*mlx;
	void			*win;
	void			*image;
	int				*data;
	int				bpp;
	int				sl;
	int				endian;
	int				width;
	int				height;
	double			min_x;
	double			max_x;
	double			min_y;
	double			max_y;
	double			step_x;
	double			step_y;
	double			ci;
	double			cr;
	int				color[256];
	char			type;
	char			ctrl;
	void			(*draw)(struct s_params *params, int start, int finish);
	int				threads;
}				t_params;

typedef struct	s_thread_info
{
	int			start_x;
	int			finish_x;
	t_params	*params;
}				t_thread_info;

# define T_JULIA 1
# define T_MANDELBROT 2
# define T_BURN 3
# define T_E_JULIA 4
# define T_JULIA_4 5
# define T_E_JULIA_4 6
# define T_JULIA_3 7
# define T_E_JULIA_3 8
# define T_NAUT 9
# define T_DRAG 10
# define T_KOCH 11

# define MAX_WIDTH 1440/2
# define MAX_HEIGHT 1440/2
# define DEPTH 255
# define DEFAULT_THREADS 16

# define P_TMP 0
# define P_ZI 1
# define P_ZR 2
# define P_CI 3
# define P_CR 4
# define P_XMIN 5
# define P_XMAX 6
# define P_YMIN 7
# define P_YMAX 8

# define V_X 0
# define V_Y 1
# define V_ERR 2
# define V_DLT 3
# define V_DLT_E 4
# define V_DIR 5

# define COLORS_FILE "./colors/rand"
# define E_NUM_PARAMS 1
# define E_NUM_COL_FILE 2
# define E_NUM_TREAD 3
# define E_SUCCESS 0

# define USAGE "usage: ./fractol <-c colorfile> <-t threads> type1 <type2>"
# define E_MSG_COL_FILE "Wrong format of color file."
# define E_MSG_THREAD "You can use 2, 4, 8, 16 or 32 threads."

void			er_error(int error_number);

void			gr_calculate(t_params *params);

void			draw_mandelbrot(t_params *params, int start_i, int finish_i);
void			draw_julia(t_params *params, int start_i, int finish_i);
void			draw_julia4(t_params *params, int start_i, int finish_i);
void			draw_julia3(t_params *params, int start_i, int finish_i);
void			draw_burning(t_params *params, int start_x, int finish_x);
void			draw_nautilus(t_params *params, int start_x, int finish_x);
void			draw_dragon(t_params *params, t_point pt_a, t_point pt_b,
					int depth);
void			draw_koch(t_params *params, t_point pt_a, t_point pt_b,
					int depth);

void			gr_draw_line(t_params *params, t_point pt_a, t_point pt_b,
					int color);

double			ft_abs_d(double value);
int				ft_get_colors(char *color_file, t_params **params);
int				is_visible(t_point pt_a, t_point pt_b,
					t_params *params);
void			ft_calc_ints(t_point *pt_a, t_point *pt_b, t_params *params);

int				exit_x(void);
int				key_release(int keycode, t_params *params);
int				key_press(int keycode, t_params *params);
int				mouse_move(int x, int y, void *param);
int				mouse_press(int button, int x, int y, void *param);

void			ft_collect_info(t_params **param, int argc, char **argv);
void			ft_color_param(t_params **param, int argc, char **argv, int *i);
void			ft_thread_param(t_params **param, int argc, char **argv,
					int *i);
int				ft_get_thread(char *str, t_params **param);
void			set_defaults(t_params *params);

#endif
