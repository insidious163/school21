NAME = libftprintf.a
INCL_DIR = ./includes/
FUNCS = $(shell cat $(INCL_DIR)/libft.h | grep -Eo "ft_\w+")
SRCS_LIB = $(FUNCS:=.c)
SRCS_PRF = convert_ctoa.c \
convert_detoa.c \
convert_dftoa.c \
convert_dgtoa.c \
convert_dtoa.c \
convert_itoa.c \
convert_ldtoa.c \
convert_litoa.c \
convert_llitoa.c \
convert_nptoa.c \
convert_stoa.c \
convert_sttoa.c \
convert_imtoa.c \
dbl_2.c \
dbl_10.c \
dbl_check.c \
dbl_mlt.c \
dbl_mlt_2.c \
dbl_power2.c \
ft_apply_flags.c \
ft_apply_precision.c \
ft_apply_width.c \
ft_apply_width_eol.c \
ft_fill_pelem.c \
ft_validate_pelem.c \
ft_format_l_0.c \
ft_format_l_h.c \
ft_format_l_hh.c \
ft_format_l_l.c \
ft_format_l_ldbl.c \
ft_format_l_ll.c \
ft_format_l_z.c \
ft_format_l_j.c \
ft_format_main.c \
pelem.c \
print_color.c \
ft_vprint.c
SRCS_DIR_LIB = ./srcs_lib
SRCS_DIR_PRF = ./srcs
OBJ_LIB = $(SRCS_LIB:%.c=%.o)
OBJ_PRF = $(SRCS_PRF:%.c=%.o)
CC = gcc
FLAGS = -c -Wall -Werror -Wextra -I $(INCL_DIR)

all: $(NAME)

$(NAME): $(OBJ_LIB) $(OBJ_PRF)
	ar rcs $(NAME) $(OBJ_LIB) $(OBJ_PRF)
	ranlib $(NAME)

$(OBJ_LIB): $(addprefix $(SRCS_DIR_LIB)/, $(SRCS_LIB))
	$(CC) $(FLAGS) $(addprefix $(SRCS_DIR_LIB)/, $(SRCS_LIB))

$(OBJ_PRF): $(addprefix $(SRCS_DIR_PRF)/, $(SRCS_PRF))
	$(CC) $(FLAGS) $(addprefix $(SRCS_DIR_PRF)/, $(SRCS_PRF))

clean:
	rm -rf $(OBJ_LIB)
	rm -rf $(OBJ_PRF)

fclean: clean
	rm -rf $(NAME)

re: fclean all
