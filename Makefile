# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/16 14:30:29 by maalwis           #+#    #+#              #
#    Updated: 2025/03/10 16:27:47 by maalwis          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Werror -Wextra

SRC = \
	atol.c \
	error_handling.c \
	implementations_operations.c \
	operations1.c \
	operations2.c \
	operations3.c \
	push_swap.c \
	radix.c \
	sort_small.c \
	sorting_algorithm.c \
	utils.c

LIBFT_PATH = Superlibft
LIBFT = $(LIBFT_PATH)/libft.a

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) -L$(LIBFT_PATH) -lft -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_PATH)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re
