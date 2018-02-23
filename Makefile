# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: proshchy <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/17 16:20:26 by proshchy          #+#    #+#              #
#    Updated: 2018/01/17 16:20:29 by proshchy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MFLAGS = -framework OpenGL -framework AppKit -lmlx
SRCS = main.c create_matrix.c draw.c key_hook.c move.c rotate.c \
      mtr_init.c help.c mtr_init1.c 
OBJ = $(SRC:.c=.o)

NAME = fdf

FLAGS = -Wall -Wextra -Werror 

all: $(OBJ)
	@gcc $(FLAGS) $(SRCS) $(MFLAGS) libft/libft.a -o $(NAME)

$(NAME): all

%.o: %.c
	gcc -o $@ -c $< $(FLAGS) 

re: relib fclean all

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

lib: 
	@make -C libft

relib:
	make -C libft re
normin:
	norminette $(SRCS)
.PHONY: all clean re lib
