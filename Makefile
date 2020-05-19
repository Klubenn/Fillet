# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gtristan <gtristan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/07 11:40:49 by gtristan          #+#    #+#              #
#    Updated: 2019/10/07 17:42:09 by gtristan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRCS = create_figs.c fill_square.c main.c remove_figs.c dupl_fig.c get_figs.c \
	   	print_figs.c

OBJECTS = $(SRCS:.c=.o)

LIBFT = libft/

HEADERS = ./

FLAGS = -Wall -Wextra -Werror

all: $(NAME) LIB

$(NAME): LIB
	gcc $(FLAGS) -I $(HEADERS) $(SRCS) -L $(LIBFT) -lft -o $(NAME)

LIB:
	make -C ./libft/

clean:
	make clean -C ./libft/
	rm -f $(OBJECTS)

fclean: clean
	make fclean -C ./libft/
	rm -f $(NAME)

re: fclean all

%.o: %.c
	gcc -c $(FLAGS) -I $(HEADERS) $< -o $@
