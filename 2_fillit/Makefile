NAME = fillit
SRCS_DIR = project
INCL_DIR = project
LIBS_DIR = libft
CC = gcc
FLAGS = -Wall -Werror -Wextra -I$(INCL_DIR)
LIBS = -L$(LIBS_DIR) -lft
C_FILES = error.c cr_matrix.c fill_it.c rd_check_figure.c rd_ptrs_ft.c rd_read_file.c main.c
O_FILES = $(C_FILES:%.c=%.o)

all: $(NAME)

$(NAME): $(O_FILES)
	make -C $(LIBS_DIR)
	$(CC) -o $(NAME) $(FLAGS) $(O_FILES) $(LIBS)

$(O_FILES): $(addprefix $(SRCS_DIR)/, $(C_FILES))
	$(CC) -c $(FLAGS) $(addprefix $(SRCS_DIR)/, $(C_FILES))

clean:
	rm -rf $(O_FILES)
	make -C $(LIBS_DIR) clean

fclean:
	rm -rf $(NAME)
	rm -rf $(O_FILES)
	make -C $(LIBS_DIR) fclean

re:	fclean all
