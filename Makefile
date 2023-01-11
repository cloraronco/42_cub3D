# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clora-ro <clora-ro@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/16 11:20:22 by clora-ro          #+#    #+#              #
#    Updated: 2023/01/04 15:13:59 by clora-ro         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME 		= cub3D

SRCS		=	action.c \
				check_wall.c \
				checker_map.c \
				checker_map_wall.c \
				main.c \
				map_build.c \
				map_init.c \
				move.c \
				move_square.c \
				position.c \
				raycast.c \
				rotate.c \
				get_next_line.c

OBJS		= $(SRCS:.c=.o)

CC			= gcc

CFLAGS		= -Wall -Werror -Wextra

RM			= rm -f

CLEAN		= CLEAN

all			: libft minilibx $(NAME)

libft		:
			$(MAKE) -C libft

minilibx	:
			$(MAKE) -C minilibx

$(NAME)		: $(addprefix objs/, $(OBJS)) libft/libft.a minilibx/libmlx.a
			$(CC) $(CFLAGS) -o $(NAME) $^ -Lminilibx -lmlx -lm -framework OpenGL -framework AppKit

objs/%.o	:	%.c includes/get_next_line.h includes/cub3D.h libft/libft.h minilibx/mlx.h minilibx/mlx_int.h minilibx/mlx_new_window.h minilibx/mlx_opengl.h minilibx/mlx_png.h Makefile
				@mkdir -p objs
				$(CC) $(CFLAGS) -Iincludes -DBUFFER_SIZE=20 -c $< -o $@

			
clean		:
			rm -rf objs/
			make clean -C libft
			make clean -C minilibx

fclean		: clean
			rm -f $(NAME)
			make fclean -C libft

re			: fclean all

.PHONY		: all clean re fclean libft minilibx