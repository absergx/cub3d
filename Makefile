# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: memilio <memilio@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/11 11:23:59 by memilio           #+#    #+#              #
#    Updated: 2020/09/12 19:52:06 by memilio          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
CC = gcc
CFLAGS = -Wall -Wextra -Werror -O2
INCLUDES = -I./includes/ -I$(LX_DIR) -I$(LFT_DIR)
FOLDER_SRCS = ./srcs/
FUNC =		main \
			validate_args \
			parse_map \
			parse_params_utils \
			parse_params \
			init \
			keys \
			keys_tools \
			keys_tools_sub \
			raycasting \
			paint \
			load_textures \
			sprite_utils \
			paint_sprite \
			save_screen \
			handle_error \
			validate_map \
			free_utils
SRC = $(addprefix $(FOLDER_SRCS), $(FUNC))
OBJ = $(SRC:=.o)
LX_DIR = ./minilibx_mms/
LXFLAGS = -L. -lmlx -framework OpenGL -framework AppKit
LFT_DIR = ./libft/
LFTFLAGS = -L$(LFT_DIR) -lft

.PHONY: all clean fclean re norme lft lmlx

all: $(OBJ_DIR) lmlx lft $(NAME)
	@echo "\033[32m[+] Make completed\033[0m"

$(NAME): $(OBJ)
	@$(CC) $(OBJ) $(INCLUDES) $(LXFLAGS) $(LFTFLAGS) -lm -o $(NAME)

lmlx:
	@$(MAKE) -C $(LX_DIR) --silent
	@cp ./minilibx_mms/libmlx.dylib .
	@echo  "\033[32m[+] Minilibx_mms builded\033[0m"

lft:
	@$(MAKE) -C $(LFT_DIR) --silent
	@$(MAKE) bonus -C $(LFT_DIR) --silent
	@echo  "\033[32m[+] Libft builded\033[0m"

$(OBJ): %.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)
	@rm -f screenshot.bmp
	@rm -f libmlx.dylib

re: fclean all
