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

NAME = mlx
MFLAGS = -framework OpenGL -framework AppKit -lmlx
CFLAGS = -Wall -Wextra -Werror
LIBFT = libft/libft.a
GNL = get_next_line.c get_next_line.h
SRCS = main.c create_matrix.c draw_line.c

all: $(NAME)

$(NAME): 
	@gcc $(SRCS) $(GNL) $(LIBFT) $(MFLAGS) -g $(CFLAGS)

clean :
	@rm a.out

re: clean
	$(NAME)
	
.PHONY: all clean re
