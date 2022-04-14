# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbaatar <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/18 20:09:59 by bbaatar           #+#    #+#              #
#    Updated: 2022/02/18 20:10:01 by bbaatar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	cub3D

SRCS_DIR	=	srcs

SRCS		=	main.c \
				initialization.c mouse_hook.c \
				draw_background.c load_textures.c position_player.c \
				ft_free_tab.c end_game.c ft_error.c \
				parsing/parsing.c parsing/get_next_line.c \
				parsing/parsing_utils.c parsing/get_content.c \
				parsing/ft_check_chars.c parsing/check_content.c \
				parsing/check_line_file.c parsing/check_rgb.c \
				parsing/get_map.c parsing/check_walls.c \
				parsing/check_wall_continuity.c parsing/check_map.c \
				parsing/create_limit.c \
				my_mlx_pixel_put.c render/draw_rays.c \
				render/keyboard.c render/render_frame.c render/render_utils.c \
				render/move_for_back.c render/move_left_right.c \
				render/move_utils.c render/move_lefts.c render/move_rights.c \
				render/draw_textures.c render/draw_pixels.c \
				render/check_verti_horiz.c

OBJS		=	$(addprefix $(SRCS_DIR)/,$(SRCS:.c=.o))

INC_DIR		=	includes

LIBFT_DIR	=	libft

MLX_DIR		=	minilibx-linux

BONUS_DIR	=	bonus

INCS		=	-I $(INC_DIR) -I $(LIBFT_DIR) -I $(MLX_DIR)

CC			=	clang

CFLAGS		=	-Wall -Wextra -Werror

RM			=	rm -f

.c.o	:
			${CC} ${CFLAGS} ${INCS} -c $< -o $@

$(NAME)	:	${OBJS}
			make -C ${LIBFT_DIR}
			make -C ${MLX_DIR}
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -L $(LIBFT_DIR) -lft -L $(MLX_DIR) -lm -lX11 -lXext -lmlx

all		:	${NAME}

clean	:
			make clean -C ${MLX_DIR}
			make fclean -C ${LIBFT_DIR}
			make fclean -C ${BONUS_DIR}
			${RM} ${OBJS} 

fclean	:	clean
			${RM} ${NAME} cub3D_bonus

re		:	fclean all

bonus	:	
			make -C ${BONUS_DIR}

.PHONY	:	all clean fclean re bonus
