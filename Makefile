# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/09 09:46:03 by fkoehler          #+#    #+#              #
#    Updated: 2016/03/16 15:44:11 by fkoehler         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = display.c handle.c init.c main.c operations.c parse.c store.c

NAME = push_swap

FLAGS = -Wall -Werror -Wextra

LIBDIR = ./libft/

INCLUDES = $(LIBDIR)includes/

LIB = $(LIBDIR)libft.a

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(LIB) $(OBJ)
		gcc $(FLAGS) $(OBJ) -L$(LIBDIR) -lft -o $@

$(LIB):
	make -C $(LIBDIR)

%.o: %.c
	gcc $(FLAGS) -c $< -I $(INCLUDES)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
