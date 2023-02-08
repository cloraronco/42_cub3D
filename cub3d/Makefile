include config/parsing_srcs.mk
include config/init_srcs.mk
include config/draw_srcs.mk
include config/dhook_srcs.mk
include config/error_srcs.mk
include config/engine_srcs.mk

NAME	= cub3D

HEADER	= 	include/cub3d.h		\
			src/init/init.h			\
			src/parsing/parsing.h	\
			src/dhook/dhook.h		\
			src/draw/draw.h			\
			src/error/error.h		\
			src/engine/engine.h		\
			mlx/mlx.h				\
			mlx/mlx_new_window.h	\
			mlx/mlx_int.h			\
			mlx/mlx_opengl.h		\
			mlx/mlx_png.h			\
			libft2/include/gc.h		\
			libft2/include/libft.h	\

LIBFT	= libft2/libft2.a
MLX		= mlx/libmlx.a

INCLUDES= ${addprefix -I, ${sort ${dir ${HEADER}}}}

SRCS	+=	src/main.c


OBJS	= ${SRCS:.c=.o}
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra -O3 #-fsanitize=address -g3
LIBFLAGS= -Lmlx -lmlx -lm -lXext -lX11

all: ${NAME}


${LIBFT}: FORCE
	make -C libft2

${MLX}: FORCE
	make	-C mlx

${NAME}: ${OBJS} 
		${CC} ${CFLAGS} ${OBJS} ${LIBFLAGS} ${INCLUDES} $(MLX) ${LIBFT} -o $@ 

%.o : %.c	${HEADER} ${LIBFT} ${MLX} Makefile
			${CC} ${CFLAGS} ${INCLUDES} -c $< -o $@


FORCE:


clean:
		rm -f ${OBJS}
		${MAKE} clean -C libft2
		${MAKE} clean -C mlx

fclean:	clean
		rm -f ${NAME}
		${MAKE} fclean -C libft2

re:		fclean all
.PHONY: all clean fclean FORCE mlx libft2 re maker
