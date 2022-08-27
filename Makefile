# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: caboudar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/27 13:19:21 by caboudar          #+#    #+#              #
#    Updated: 2022/08/27 15:34:32 by caboudar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS	= 		srcs/so_long.c                             \
                srcs/init_images.c                         \
                srcs/set_player_movement.c                 \
                srcs/set_var.c                             \
                srcs/set_characters_movement.c             \
                srcs/set_animations_and_images.c           \
                srcs/set_images.c                          \
                srcs/free_var.c                            \
                srcs/check_map_name.c               \
                srcs/check_map_error.c              \
                srcs/check_map_elements.c           \
                srcs/get_map.c                      \
                srcs/helpers.c                            \
                srcs/so_long_utils.c                      \
                srcs/get_next_line.c                      \
                srcs/get_next_line_utils.c                \
				
SRCS_B =		srcs/bonus/so_long.c                             \
                srcs/bonus/init_images.c                         \
                srcs/bonus/set_player_movement.c                 \
                srcs/bonus/set_enemy_movement.c                  \
                srcs/bonus/set_var.c                             \
                srcs/bonus/set_characters_movement.c             \
                srcs/bonus/set_animations_and_images.c           \
                srcs/bonus/set_images.c                          \
                srcs/bonus/enemy_direction.c                     \
                srcs/bonus/free_var.c                            \
                srcs/bonus/check_map_name.c               \
                srcs/bonus/check_map_error.c              \
                srcs/bonus/check_map_elements.c           \
                srcs/bonus/get_map.c                      \
                srcs/bonus/helpers.c                            \
                srcs/bonus/get_next_line.c                      \
                srcs/bonus/get_next_line_utils.c                \
                srcs/bonus/init_player_movement.c                \
                srcs/bonus/so_long_utils.c                \


OBJS	= ${SRCS:.c=.o}

OBJS_B	= ${SRCS_B:.c=.o}

CFLAGS	= -Wall -Werror -Wextra -g

CC		= gcc

RM		= rm -f

INCS    = includes

MLX = ./mlx_linux/libmlx.a

all:	${NAME}

.c.o:
		@$(CC) ${CFLAGS} -I$(INCS) -c $< -o $@

${NAME}:	${OBJS} ${MLX}
		@${CC} ${CFLAGS} ${OBJS} ${MLX}  -lX11 -lXext -o so_long
		@printf "%s\e[0;32m so_long : Compiling object file into executable\n\e[0m" "-"

${MLX}:
		@make -C mlx_linux --no-print-directory

bonus: ${OBJS_B} ${MLX}
		${CC} ${CFLAGS} ${OBJS_B} -I$(INCS) ${MLX} -lX11 -lXext -o so_long
		@printf "%s\e[0;32m so_long : Compiling bonus object file into executable\n\e[0m" "-"

clean:
		@${RM} ${OBJS}
		@${RM} ${OBJS_B}
		@printf "%s\e[0;31m so_long : Delete all object files\n\e[0m" "-"

fclean:
		@${RM} ${OBJS}
		@${RM} ${OBJS_B}
		@printf "%s\e[0;31m so_long : Delete all object files\n\e[0m" "-"
		@${RM} ${NAME}
		@printf "%s\e[0;31m so_long : Delete executable\n\e[0m" "-"
		@make clean -C mlx_linux --no-print-directory


re: fclean ${NAME}

.PHONY: all clean fclean re bonus