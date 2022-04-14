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

NAME		=	cub3D_bonus

SRCS_DIR	=	srcs

SRCS		=	main_bonus.c \
				initialization_bonus.c mouse_hook_bonus.c \
				draw_background_bonus.c load_textures_bonus.c position_player_bonus.c \
				ft_free_tab_bonus.c end_game_bonus.c ft_error_bonus.c \
				parsing/parsing_bonus.c parsing/get_next_line_bonus.c \
				parsing/parsing_utils_bonus.c parsing/get_content_bonus.c \
				parsing/ft_check_chars_bonus.c parsing/check_content_bonus.c \
				parsing/check_line_file_bonus.c parsing/check_rgb_bonus.c \
				parsing/get_map_bonus.c parsing/check_walls_bonus.c \
				parsing/check_wall_continuity_bonus.c parsing/check_map_bonus.c \
				parsing/create_limit_bonus.c \
				my_mlx_pixel_put_bonus.c render/draw_rays_bonus.c \
				render/keyboard_bonus.c render/render_frame_bonus.c render/render_utils_bonus.c \
				render/move_for_back_bonus.c render/move_left_right_bonus.c \
				render/move_utils_bonus.c render/move_lefts_bonus.c render/move_rights_bonus.c \
				render/draw_textures_bonus.c render/draw_pixels_bonus.c \
				render/check_verti_horiz_bonus.c

OBJS		=	$(addprefix $(SRCS_DIR)/,$(SRCS:.c=.o))

INC_DIR		=	includes

LIBFT_DIR	=	../libft

MLX_DIR		=	../minilibx-linux

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
			cp ${NAME} ../

all		:	${NAME}

clean	:
			make clean -C ${MLX_DIR}
			make fclean -C ${LIBFT_DIR}
			${RM} ${OBJS}

fclean	:	clean
			${RM} ${NAME}

re		:	fclean all

.PHONY	:	all clean fclean re bonus