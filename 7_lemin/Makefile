# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kcarrot <kcarrot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/29 19:04:47 by ffahey            #+#    #+#              #
#    Updated: 2019/02/08 00:35:43 by trhogoro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

vpath %.c srcs
vpath %.h includes
vpath %.o bin

FLAGS_G = -lmlx -framework OpenGL -framework Appkit

FLAGS = -Wall -Wextra -Werror

OBJ = $(addprefix bin/,$(notdir $(patsubst %.c,%.o,$(wildcard srcs/*.c))))

HEADERS = $(wildcard includes/*.h)

LIB = libft/libft.a

all: makedir make_lib $(NAME)

makedir:
	@mkdir -p bin

make_lib:
	make -C libft/

$(NAME): $(OBJ) $(LIB)
	gcc $(FLAGS) $(FLAGS_G) $^ -o $@ -Iincludes -Ilibft -Llibft -lft

bin/%.o: %.c $(HEADERS)
	gcc $(FLAGS) -c $< -o $@ -Iincludes -Ilibft

clean:
	rm -rf bin/
	rm -rf libft/*.o

fclean: clean
	rm -f $(NAME)
	rm -f $(LIB)

re: fclean all

.PHONY: all clean fclean re make_lib
