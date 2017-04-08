# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kbunel <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/07 23:48:30 by kbunel            #+#    #+#              #
#    Updated: 2017/04/08 00:14:35 by kbunel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_retro

SRC_NAME = main.cc

OBJ_NAME = $(SRC_NAME:.cc=.o)

HEADER_NAME = ft_retro.h

SRC_PATH = srcs

OBJ_PATH = obj

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

CC = clang++

CFLAGS = -Wall -Werror -Wextra

.PHONY: all, clean, fclean, re

all: $(NAME)

$(NAME): $(OBJ)
	@echo "  Compiling \033[32m$@\033[32m √\033[0m"
	@$(CC) $(OBJ) -o $@ -lncurses

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.cc
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@echo "  Compiling \033[36m$@\033[0m"
	@$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean:	clean
	@rm -f $(NAME)

re:	fclean all
