# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgrasser <cgrasser@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/05 23:22:02 by cgrasser          #+#    #+#              #
#    Updated: 2024/12/19 14:34:04 by cgrasser         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -rf

SRC_DIR = src
INC_DIR = include
OBJ_DIR = build

SRC = main.c fdf.c init_data.c mlx_event.c init_data_map.c mlx_destroy_data.c

BOLD = \033[1m
GREEN = \033[32m
YELLOW = \033[93m
RESET = \033[0m

OBJS = $(SRC:%.c=$(OBJ_DIR)/%.o)

MINILIBX_PATH = ./lib/minilibx_linux
MINILIBX = libmlx.a
MLX_FLAGS = -lX11 -lXext

LIBFT_PATH = ./lib/libft
LIBFT = libft.a

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) -I $(LIBFT_PATH)/$(INC_DIR) -I $(MINILIBX_PATH) -I $(INC_DIR) -c $< -o $@

all: $(NAME)

$(NAME): $(LIBFT_PATH)/$(LIBFT) $(MINILIBX_PATH)/$(MINILIBX) $(OBJ_DIR) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT_PATH)/$(LIBFT) $(MINILIBX_PATH)/$(MINILIBX) $(MLX_FLAGS) -o $(NAME)
	@echo "$(YELLOW) ➥ $(RESET)$(BOLD)$(NAME) $(GREEN)✔$(RESET)"

$(LIBFT_PATH)/$(LIBFT):
	@make -s -C $(LIBFT_PATH) all

$(MINILIBX_PATH)/$(MINILIBX):
	@make -s -C $(MINILIBX_PATH) all > /dev/null 2>&1
	@echo "$(YELLOW) ➥ $(RESET)$(BOLD)libmlx.a $(GREEN)✔$(RESET)"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@make -s -C $(LIBFT_PATH) clean
	@make -s -C $(MINILIBX_PATH) clean > /dev/null 2>&1
	@$(RM) $(OBJ_DIR)

fclean:
	@make -s -C $(LIBFT_PATH) fclean
	@make -s -C $(MINILIBX_PATH) clean > /dev/null 2>&1
	@$(RM) $(OBJ_DIR)
	@$(RM) $(NAME)
	@echo "$(YELLOW) ➥ $(RESET)$(BOLD)Cleaned $(MINILIBX)! $(GREEN)✔$(RESET)"
	@echo "$(YELLOW) ➥ $(RESET)$(BOLD)Cleaned $(NAME)! $(GREEN)✔$(RESET)"

re: fclean all

.PHONY: all clean fclean re libft

