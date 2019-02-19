NAME = fractol
SRCS_DIR = srcs
INCL_DIR = incl
LIBS_DIR = libs
FLAG_W = -Wall -Wextra -Werror
FLAG_G = -lmlx -framework OpenGL -framework Appkit
LIBS = -L$(LIBS_DIR) -l$(L_FILE)
C_FILES = fr_mandelbrot.c fr_julia.c fr_koch.c fr_julia4.c fr_julia3.c fr_dragon.c gr_draw_line.c fr_nautilus.c gr_hooks.c gr_color.c gr_tools.c gr_params.c gr_thread.c fr_burningship.c er_error.c
O_FILES = $(C_FILES:%.c=%.o) main.o
L_FILE = ft

all: $(NAME)

$(NAME): $(O_FILES)
	make -C $(LIBS_DIR)
	$(CC) -o $(NAME) $(FLAG_G) $(O_FILES) $(LIBS)

$(O_FILES): $(addprefix $(SRCS_DIR)/, $(C_FILES)) main.c
	$(CC) -c $(FLAG_W) -I$(INCL_DIR) $(addprefix $(SRCS_DIR)/, $(C_FILES)) main.c

clean:
	rm -rf $(O_FILES)
	make -C $(LIBS_DIR) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(LIBS_DIR) fclean

re:	fclean all
