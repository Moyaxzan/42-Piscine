# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsaint-p <tsaint-p@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/27 18:14:36 by elrichar          #+#    #+#              #
#    Updated: 2023/03/01 22:46:51 by tsaint-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq

OBJ = $(SRC:.c=.o) 

CC = cc

HEAD = includes

FLAGS = -Wall -Wextra -Werror

SRC = src/main.c src/map.c src/read_file.c src/solve.c src/split.c src/write_map.c src/memory.c src/utils.c

.c.o:
	$(CC) $(FLAGS) -I $(HEAD) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) -I $(HEAD) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	
re: fclean all

.PHONY : all clean fclean re



