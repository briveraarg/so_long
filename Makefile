# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/18 18:41:57 by brivera@stu       #+#    #+#              #
#    Updated: 2025/02/19 18:52:45 by brivera          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror #-g3 -fsanitize=address
MLX42_DIR = libs/MLX42
MLX42 = $(MLX42_DIR)/build/libmlx42.a
MLX42_INC = $(MLX42_DIR)/include

LIBFT_DIR = libs/libft
LIBFTA = $(LIBFT_DIR)/libft.a

FT_PRINTF_DIR = libs/ft_printf
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a

OBJ_DIR = obj
SRC_DIR = src
SRCS = $(SRC_DIR)/check_map_00.c $(SRC_DIR)/check_map_01.c $(SRC_DIR)/check_map_02.c \
       $(SRC_DIR)/check_map_03.c \
	   $(SRC_DIR)/initialize_game_struc_00.c $(SRC_DIR)/initialize_game_struc_01.c \
       $(SRC_DIR)/initialize_game_struc_02.c $(SRC_DIR)/initialize_game_struc_03.c \
	   $(SRC_DIR)/initialize_game_struc_04.c \
       $(SRC_DIR)/move_player_00.c $(SRC_DIR)/move_player_01.c $(SRC_DIR)/move_player_02.c \
	   $(SRC_DIR)/main.c \
	   $(SRC_DIR)/error_exit.c\
	   $(SRC_DIR)/utils.c \

OBJS = $(OBJ_DIR)/check_map_00.o $(OBJ_DIR)/check_map_01.o $(OBJ_DIR)/check_map_02.o \
       $(OBJ_DIR)/check_map_03.o \
	   $(OBJ_DIR)/initialize_game_struc_00.o $(OBJ_DIR)/initialize_game_struc_01.o \
       $(OBJ_DIR)/initialize_game_struc_02.o $(OBJ_DIR)/initialize_game_struc_03.o \
	   $(OBJ_DIR)/initialize_game_struc_04.o \
       $(OBJ_DIR)/move_player_00.o $(OBJ_DIR)/move_player_01.o $(OBJ_DIR)/move_player_02.o \
	   $(OBJ_DIR)/main.o \
       $(OBJ_DIR)/error_exit.o\
	   $(OBJ_DIR)/utils.o\

INCLUDE = so_long.h

RED			= \033[91;1m
GREEN		= \033[92;1m
CLEAR_COLOR	= \033[0m
CYAN 		= \033[96;1m

OS = $(shell uname)
ifeq ($(OS), Linux)
	MLX_FLAGS = -lglfw -lm -ldl -lX11 -lpthread -lXrandr -lXi
else
	MLX_FLAGS = -framework Cocoa -framework OpenGL -framework IOKit -lglfw
endif

all: $(NAME)

$(NAME): $(LIBFTA) $(MLX42) $(FT_PRINTF) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFTA) $(FT_PRINTF) $(MLX42) $(MLX_FLAGS) -I$(MLX42_INC) -o $(NAME)
	@echo "$(CYAN)✅ Compilado so_long\n$(CLEAR_COLOR)"
                         
$(LIBFTA):
	@make -C $(LIBFT_DIR)
	@echo "$(GREEN)✅ Compilado LIBFT\n$(CLEAR_COLOR)"

$(FT_PRINTF):
	@make -C $(FT_PRINTF_DIR)
	@echo "$(GREEN)✅ Compilado LIBFT_PRINTF\n$(CLEAR_COLOR)"

$(MLX42):
	@cmake -B $(MLX42_DIR)/build $(MLX42_DIR)
	@cmake --build $(MLX42_DIR)/build
	@echo "$(GREEN)✅ Compilado MLX42\n$(CLEAR_COLOR)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INCLUDE)
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I. -c $< -o $@

clean:
	@$(RM) $(OBJS)
	@rm -rf $(OBJ_DIR)
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(FT_PRINTF_DIR)
	@echo "$(RED)⛔ Limpieza de archivos objeto.$(CLEAR_COLOR)"

fclean: clean
	@$(RM) $(NAME)
	@rm -rf $(MLX42_DIR)/build
	@make fclean -C $(LIBFT_DIR)
	@make fclean -C $(FT_PRINTF_DIR)
	@echo "$(RED)⛔ Limpieza total (ejecutables y librerías).$(CLEAR_COLOR)"

re: fclean all

norminette:
	@norminette $(SRCS) ./so_long.h

.PHONY: all clean fclean re
