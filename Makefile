# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmontezu <tmontezu@student.42lisboa.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/28 18:44:23 by tmontezu          #+#    #+#              #
#    Updated: 2026/02/10 18:39:54 by tmontezu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = push_swap
HEADER  = push_swap.h
CC      = cc
CFLAGS  = -Wall -Wextra -Werror -I./ -I./src/libft
RM      = rm -f

SRC     = src/error.c src/parse.c src/push.c src/rotate.c src/rr.c src/swap.c src/utils.c src/utils2.c src/sortfive.c src/sort.c
OBJ     = $(SRC:.c=.o)

LIBFT_D = src/libft
LIBFT   = $(LIBFT_D)/libft.a

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT)
	@echo "$(NAME) compiled"

$(LIBFT):
	@$(MAKE) -C $(LIBFT_D) --no-print-directory

%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ)
	@$(MAKE) clean -C $(LIBFT_D) --no-print-directory

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) fclean -C $(LIBFT_D) --no-print-directory

re: fclean all

.PHONY: all clean fclean re

