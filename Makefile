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

# NAME = mlx
MFLAGS = -framework OpenGL -framework AppKit -lmlx
# CFLAGS = -Wall -Wextra -Werror
# LIBFT = libft/libft.a
# GNL = get_next_line.c get_next_line.h
SRCS = main.c create_matrix.c draw.c key_hook.c move.c rotate.c \
      mtr_init.c help.c mtr_init1.c get_next_line.c \
      get_next_line.h 
OBJ = $(SRC:.c=.o)

NAME = fdf

FLAGS = -Wall -Wextra -Werror 
# all: $(NAME)

# $(NAME): lib
# 	@gcc $(SRCS) $(GNL) $(LIBFT) $(MFLAGS) $(CFLAGS)

# %.o: %.c
# 	$(CC) -o $@ -c $< $(FLAGS) 

# clean :
# 	@rm a.out
	
# re: clean
# 	$(NAME)
# lib:
# 	make -C libft
	
# .PHONY: all clean re

all: $(OBJ)
	gcc $(FLAGS) $(SRCS) $(MFLAGS) libft/libft.a

$(NAME): all

%.o: %.c
	$(CC) -o $@ -c $< $(FLAGS) 

re: relib fclean all

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

lib: 
	make -C libft

relib:
	make -C libft re