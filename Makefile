
SRCS		=	srcs/game/so_long.c								\
				srcs/game/init_images.c							\
				srcs/game/set_player_movement.c					\
				srcs/game/set_enemy_movement.c					\
				srcs/map_parsing/check_map_name.c				\
				srcs/map_parsing/check_map_error.c				\
				srcs/map_parsing/check_map_elements.c			\
				srcs/map_parsing/get_map.c						\
				srcs/utils/helpers.c							\
				srcs/utils/so_long_utils.c						\
				srcs/utils/get_next_line.c						\
				srcs/utils/get_next_line_utils.c				\
				srcs/game/free_var.c							\
				srcs/game/set_var.c								\
				srcs/game/set_characters_movement.c				\
				srcs/game/set_animations_and_images.c			\

OBJS		=	$(SRCS:.c=.o)

CC			=	gcc

RM			=	rm -f

CFLAGS		= 	-Wall -Wextra -Werror -g -I./srcs/includes

NAME		= 	so_long
	
MLX			= 	-Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

%.o: %.c
	$(CC) $(CFLAGS) -I/uscdr/include -Imlx_linux -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJS)
	@make -C ./mlx_linux
	$(CC) $(CFLAGS) $(OBJS) $(MLX) -o $(NAME)	

clean:
	$(RM) $(OBJS)

fclean:		clean
	$(RM) $(NAME)

re:		fclean $(NAME)

.PHONY:		all clean fclean re bonus
