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

SRC_DIR = src/
SRC_C = create_figs.c fill_square.c main.c remove_figs.c dupl_fig.c \
	 get_figs.c print_figs.c
SRC = $(addprefix $(SRC_DIR),$(SRC_C))

INCL_DIR = ./includes/
INCL_H = fillit.h
INCL = $(addprefix $(INCL_DIR),$(INCL_H))

LIBFT = lft
LIBFT_DIR = ./libft/

FLAGS = -Wall -Wextra -Werror

all: $(LIBFT_DIR)$(LIBFT) $(NAME) 

$(NAME): $(SRC) $(INCL)
	gcc $(FLAGS) $(SRC) -I$(LIBFT_DIR) -I$(INCL_DIR) -L$(LIBFT_DIR) -$(LIBFT) -o $(NAME)

$(LIBFT_DIR)$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	make clean -C ./libft/
	rm -f $(OBJECTS)

fclean: clean
	make fclean -C ./libft/
	rm -f $(NAME)

re: fclean all

%.o: %.c
	gcc -c $(FLAGS) -I $(HEADERS) $< -o $@
