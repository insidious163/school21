/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrot <kcarrot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 09:39:51 by trhogoro          #+#    #+#             */
/*   Updated: 2019/02/08 11:53:58 by kcarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUAL_H
# define VISUAL_H

# include "libft.h"
# include <unistd.h>
# include "lem_in.h"

typedef struct	s_point3d
{
	int		id;
	int		x;
	int		y;
	int		z;
	int		xi;
	int		yi;
	int		zi;
	double	xt;
	double	yt;
	double	zt;
	int		color;
	int		state;
}				t_point3d;

typedef struct	s_line
{
	int			visible;
	t_point3d	*a;
	t_point3d	*b;
}				t_line;

typedef struct	s_xyz
{
	double x;
	double y;
	double z;
}				t_xyz;

typedef struct	s_correction
{
	int		iter;
	int		path;
	t_xyz	mv[3];
	t_xyz	rt[3];
	double	sc[3];
	int		type;
}				t_correction;

typedef struct	s_params
{
	void			*mlx;
	void			*win;
	void			*image;
	int				*data;
	int				bpp;
	int				sl;
	int				endian;
	t_correction	c;
	int				width;
	int				height;
	int				max_x;
	int				max_y;
	int				min_z;
	int				max_z;
	t_list			*points;
	t_list			*lines;
	t_path_set		*set;
	t_list			*moves;
	t_ant			**ants;
}				t_params;

# define E_SUCCESS 0
# define E_ERROR 1
# define E_MEMORY_ERROR 2
# define E_WRONG_DATA 3
# define E_READING_ERROR 4
# define E_WIDTH 5
# define E_HEIGHT 6
# define E_FILE_ERR 7

# define CON_D 500
# define P_ISO 0
# define P_PAR 1
# define P_CON 2
# define MV_STEP 10
# define RT_STEP 0.05
# define SC_STEP 0.15
# define Y0 78
# define MAX_X	4*640
# define MAX_Y	4*360
# define MINX 0
# define MAXX 1
# define MINY 2
# define MAXY 3

# define C_NODE 0x6D2D9E
# define C_START 0x990000
# define C_FINISH 0x39A495
# define C_LINE 0x6D2D9E
# define C_PATH 0xE8B763
# define C_ANT 0xFFFFFF
# define ANT_MINI 0x42A5243C5A3C1824LU
# define ANT_LU 0x10304888080C0F1FLU
# define ANT_RU 0x080C12111030F0F8LU
# define ANT_LD 0x33331F0F03060C08LU
# define ANT_RD 0xCCCCF8F0C0603010LU
# define ITER 4

# define WIDTH 2560/2
# define HEIGHT 1440/2

# define V_X 0
# define V_Y 1
# define V_ERR 2
# define V_DLT 3
# define V_DLT_E 4
# define V_DIR 5

# define M_USG "usage: ./fdf <file name> or ./fdf <file name> <width> <height>."
# define M_WIDTH "Width should be between 640 and 2560."
# define M_HEIGHT "Height should be between 640 and 1440."
# define M_FILE_ERR "File error. Please use another file."
# define M_ERR_MEM "Memory error."
# define M_ERR_DATA "Wrong data in file."
# define M_ERR_READ "Reading error."
# define HELP1 "HELP:     +   -  \t               +   -  \t Zoom:       '+'/'-'"
# define HELP2 " Move: x 'q' 'w' \t Rotation: x  'e' 'r' \t Projection: ISO '1'"
# define HELP3 "       y 'a' 's' \t           y  'd' 'f' \t             PAR '2'"
# define HELP4 "       z 'z' 'x' \t           z  'c' 'v' \t             CON '3'"

int				exit_x(void);
int				key_hook(int keycode, t_params *params);
int				gr_line_color(t_params *params, t_line *line);
void			gr_draw_line(t_params *params, t_point3d pt_a, t_point3d pt_b,
		int color);
void			gr_draw_move(t_list *moves, int i, t_params *params);
void			gr_draw_ant(int x, int y, t_params *params);
t_list			*gr_get_moves(t_params *params);
void			gr_plot(int x, int y, int c, t_params *params);
int				gr_node_color(t_point3d *node);
void			gr_set_start_settings_iso(t_params *params);
void			gr_set_start_settings_par(t_params *params);
void			gr_set_start_settings_con(t_params *params);
void			gr_apply_correction(t_correction correction, t_params *params);
void			gr_apply_move(void *params, t_params *param);
void			gr_apply_rotation(void *params, t_params *param);
void			gr_apply_scale(void *params, t_params *param);
void			gr_apply_type(int type, t_params *params);
t_params		*gr_init(t_farm *farm, t_ant **ants);
void			gr_draw_farm(t_params *params);
void			gr_apply_color(t_params *params);

#endif
