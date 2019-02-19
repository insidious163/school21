/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 02:56:00 by trhogoro          #+#    #+#             */
/*   Updated: 2019/02/01 02:56:01 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct	s_mini
{
	int		order_a;
	int		order_b;
	char	*cmd;
}				t_mini;

typedef struct	s_gr
{
	void	*mlx;
	void	*win;
	int		width;
	int		height;
	int		step_y;
	int		max_x;
}				t_gr;

typedef struct	s_param
{
	t_gr	*gr;
	t_lst2	*stack_a;
	t_lst2	*stack_b;
	t_list	*cmd;
}				t_param;

typedef struct	s_point
{
	int x;
	int y;
}				t_point;

typedef struct	s_xymini
{
	int		x;
	int		y;
	t_list	*mini;
}				t_xymini;

# define WIDTH 1000
# define HEIGHT 1000

# define SA "sa"
# define SB "sb"
# define SS "ss"
# define PA "pa"
# define PB "pb"
# define RA "ra"
# define RB "rb"
# define RR "rr"
# define RRA "rra"
# define RRB "rrb"
# define RRR "rrr"

# define E_SUCCESS 0
# define E_ERROR 1
# define E_NOTINT 2
# define E_MEMORY 3
# define E_PARAMS 4
# define E_KO 5
# define E_READING 6
# define E_EMPTY 7
# define E_VISUAL 8

# define PRINT_RED "\x1b[31m"
# define PRINT_ZERO "\x1b[0m"

# define OPTIONS_CH "dcvh"
# define OPTIONS_PS "ht"
# define CMD_LST (ft_lstlen(cmd_ll) > ft_lstlen(cmd_qs) ? cmd_qs : cmd_ll)

# define MINI_FILE "./mini"
# define FIRST 0

# define FALSE 22
# define TRUE 21

# define STACK_A 0
# define STACK_B 1

# define LA 0
# define LB 1
# define IA 2
# define IB 3
# define VAL 4

# define I_X 0
# define I_Y 1
# define I_R 2
# define I_RR 3
# define I_I 4

typedef struct	s_info
{
	int		value;
	char	to_remove;
	int		id;
	int		d[2];
	int		color;
}				t_info;

int				ft_swap(t_lst2 **lst_a, t_lst2 **lst_b);
int				ft_rotate(t_lst2 **lst_a, t_lst2 **lst_b, char reverse);

int				ft_push(t_lst2 **lst_to, t_lst2 **lst_from);
int				ft_apply_command(t_lst2 **stack_a, t_lst2 **stack_b, char *cmd);
int				ft_apply_commands(t_lst2 **stack_a, t_lst2 **stack_b,
					t_list *commands);
int				ft_check_result(t_lst2 *stack_a, t_lst2 *stack_b);

int				rd_options(int ac, char **av, char *available);
void			rd_init_stack_a(int ac, char **av, t_lst2 **stack_a);
int				read_commands(int fd, t_list **commands);

void			er_error(int err_num);
void			wr_usage_push_swap();
void			cl_clear(t_lst2 **stack_a, t_lst2 **stack_b, t_list **cmd_ll,
					t_list **cmd_qs);
void			wr_type(t_list *cmd_ll, t_list *cmd_qs);
void			wr_usage_checker();
int				ft_lst_has_equals(t_lst2 *stack_a);

void			ll_sort(t_lst2 *stack_a, t_list **commands);
void			ll_find_max_line(t_lst2 *stack_a);
void			ll_fill_b(t_lst2 **stack_a, t_lst2 **stack_b,
					t_list **commands);
int				ll_i_mn(int a, int b);
int				ll_i_mx(int a, int b);
void			ll_add_rotations(t_list **commands, int a, int b);
void			ll_push_back(t_lst2 **stack_a, t_lst2 **stack_b,
					t_list **commands);

void			qs_sort(t_lst2 *stack_a, t_list **commands_q);
t_list			*qs_initialize_mini();
void			qs_initialize(t_lst2 **stack_a, t_lst2 **stack_b,
					t_list **commands_q, t_list **cmd);
void			qs_rotate_n(t_lst2 **stack, int n, int stack_id,
					t_list **commands);
void			qs_add_command(t_list **commands, char *cmd);
t_lst2			*qs_elem_y(t_lst2 *stack, int i);
t_list			*qs_set_commmands1(int order_a, int order_b);
t_list			*qs_set_commands(int order_a, int order_b, t_list *mini);
int				qs_order(t_lst2 *stack_a, int x, int y);
t_list			*qs_push_b(t_lst2 **stack_a, t_lst2 **stack_b, int x, int y);
t_list			*qs_push_a(t_lst2 **stack_a, t_lst2 **stack_b, int x, int y);
void			qs_sort_a(t_lst2 **stack_a, t_lst2 **stack_b, t_list **commands,
					t_xymini param);
void			qs_sort_b(t_lst2 **stack_a, t_lst2 **stack_b, t_list **commands,
					t_xymini param);

void			rm_pa_pb(t_list **commands_q);
void			rm_rr_rrr(t_list **commands_q);

void			ptr_lstprint(t_list *lst);
void			ptr_lst2print(t_lst2 *copy_a);
int				ptr_rbtcmp(t_rbtree *node1, t_rbtree *node2);
void			ptr_setid(t_rbtree *elem, void *param);
void			ptr_lstdel(void *content, size_t content_size);
void			ptr_rbtdel(t_rbtree *elem);
void			ptr_lstminidel(void *content, size_t content_size);
void			ptr_stackdel(void *content, size_t content_size);
int				ptr_valuecmp(t_list *elem1, t_list *elem2);

void			gr_visual(t_lst2 *stack_a, t_list *cmd);
void			ft_apply_color(t_lst2 **stack_a, t_lst2 **stack_b, char *cmd);
void			wr_debug(t_lst2 *stack_a, t_list *cmd, int is_color);
void			ft_color_clean(t_lst2 *stack_a, t_lst2 *stack_b);
int				exit_x(void);
int				key_press(int keycode, t_param **params);
void			gr_draw_picture(t_gr *gr, t_lst2 *stack_a, t_lst2 *stack_b);
int				mouse_move(int x, int y, t_param **params);
int				gr_max_abs(t_lst2 *stack_a);
void			gr_draw_rectangle(t_gr *gr, t_point a, t_point b, int color);
#endif
