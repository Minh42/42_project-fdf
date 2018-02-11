# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minh <minh@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 12:55:31 by cmace             #+#    #+#              #
#    Updated: 2018/02/06 10:50:03 by minh             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# BINARY
NAME = fdf

# COMPILATION FLAGS
CC = gcc
FLAGS = -g -Wall -fsanitize=address
ADDFLAGS =

# DIRECTORIES
LIBFT_DIR = libft
MLIBX_DIR = minilibx

# SOURCES
SRC = \
			main.c\
			ft_parse_map.c \
			m_functions.c \
			ft_bresenham.c \
			ft_init_map.c \
			ft_draw.c \
			ft_events.c \
			ft_checks.c

OBJ = $(SRC:.c=.o)

# FILES
LIBFT = $(LIBFT_DIR)/libft.a
MLIBX = $(MLIBX_DIR)/libmlx.a

# PROGRESS BAR
T = $(words $(OBJ))
N = 0
C = $(words $N)$(eval N := x $N)
ECHO = "[`expr $C  '*' 100 / $T`%]"

#Colors
_GREY=\x1b[30m
_RED=\x1b[31m
_GREEN=\x1b[32m
_YELLOW=\x1b[33m
_BLUE=\x1b[34m
_PURPLE=\x1b[35m
_CYAN=\x1b[36m
_WHITE=\x1b[37m
_END=\x1b[0m

all: $(NAME)

$(NAME): $(LIBFT) $(MLIBX) $(OBJ)
	@echo "\n$(NAME) compilation : $(_CYAN)done$(_END)"
	@$(CC) $(FLAGS) $(ADDFLAGS) -o $(NAME) $(OBJ) -L$(LIBFT_DIR) -lft -L$(MLIBX_DIR) -lmlx -framework OpenGL -framework AppKit

%.o: %.c
	@printf "%-60b\r" "$(ECHO) $(_CYAN) Compiling $@ $(_END)"
	@$(CC) $(FLAGS) $(ADDFLAGS) -c $<

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(MLIBX):
	@make -C $(MLIBX_DIR)

clean:
	@$(RM) -f $(OBJ)
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(MLIBX_DIR)
	@echo "clean fillit: $(_CYAN)done$(_END)"

fclean: clean
	@$(RM) -f $(NAME)
	@make fclean -C $(LIBFT_DIR)
	@make clean -C $(MLIBX_DIR)
	@echo "fclean fdf: $(_CYAN)done$(_END)"

re: fclean all

.PHONY: all clean fclean re