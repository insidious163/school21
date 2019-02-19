NAME_CH = checker
NAME_PS = push_swap
SRCS_DIR = srcs
INCL_DIR = ./incl
LIBS_DIR = ./libs
CC = gcc
FLAGS = -Wall -Werror -Wextra -I $(INCL_DIR)
FLAG_G = -lmlx -framework OpenGL -framework Appkit
LIBS = -L$(LIBS_DIR) -lft
CH_C_FILES = checker.c \
			 cl_clear.c \
			 ch_apply.c \
			 gr_visual.c gr_hooks.c gr_tools.c \
			 cmd_push.c cmd_rotate.c cmd_swap.c \
			 er_error.c \
			 ptr_funcs.c ptr_rbt.c\
			 rd_options.c rd_read_commands.c rd_init_stack_a.c \
			 wr_color.c wr_debug.c
CH_O_FILES = $(CH_C_FILES:%.c=%.o)
PS_C_FILES = cl_clear.c \
			 ch_apply.c \
			 cmd_push.c cmd_rotate.c cmd_swap.c \
			 er_error.c \
			 ll_fill_b.c ll_find_max_line.c ll_main.c ll_push_back.c ll_tools.c \
			 ptr_funcs.c ptr_rbt.c \
			 push_swap.c \
			 qs_initialize.c qs_main.c qs_push.c qs_set_commands.c \
			 qs_sort_a.c qs_sort_b.c qs_tools.c \
			 rd_init_stack_a.c rd_options.c \
			 rm_pa_pb.c rm_rr_rrr.c \
			 wr_type.c
C_FILES	=	checker.c \
			ch_apply.c \
			cl_clear.c \
			cmd_push.c cmd_rotate.c cmd_swap.c \
			er_error.c \
			gr_visual.c gr_hooks.c gr_tools.c \
			ll_fill_b.c ll_find_max_line.c ll_main.c ll_push_back.c ll_tools.c \
			ptr_funcs.c ptr_rbt.c \
			push_swap.c \
			qs_initialize.c qs_main.c qs_push.c qs_set_commands.c \
			qs_sort_a.c qs_sort_b.c qs_tools.c \
			rd_read_commands.c rd_init_stack_a.c rd_options.c \
			rm_pa_pb.c rm_rr_rrr.c \
			wr_color.c wr_debug.c wr_type.c
O_FILES = $(C_FILES:%.c=%.o)
PS_O_FILES = $(PS_C_FILES:%.c=%.o)
NAME_LIB = libft.a

all: $(NAME_LIB) $(O_FILES)
	$(CC) -o $(NAME_CH) $(FLAGS) $(FLAG_G) $(CH_O_FILES) $(LIBS)
	$(CC) -o $(NAME_PS) $(FLAGS) $(PS_O_FILES) $(LIBS)

$(NAME_LIB):
	make -C $(LIBS_DIR)

$(O_FILES): $(addprefix $(SRCS_DIR)/, $(C_FILES))
	$(CC) -c $(FLAGS) $(addprefix $(SRCS_DIR)/, $(C_FILES))

clean:
	rm -rf $(O_FILES)
	make -C $(LIBS_DIR) clean

fclean:
	rm -rf $(O_FILES)
	rm -rf $(NAME_CH)
	rm -rf $(NAME_PS)
	make -C $(LIBS_DIR) fclean

re:	fclean all
