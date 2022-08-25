/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caboudar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 03:12:37 by caboudar          #+#    #+#             */
/*   Updated: 2022/08/25 12:52:39 by caboudar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define BUFFER_SIZE 1
# define ESC 65307
# define UP_KEY 119
# define DOWN_KEY 115
# define LEFT_KEY 97
# define RIGHT_KEY 100
# define UP_DIR 1
# define LEFT_DIR 2
# define DOWN_DIR 3
# define RIGHT_DIR 4

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <mlx.h>

typedef struct s_mlx
{
	void			*mlx;
	void			*window;
	void			*mlx_wall_img;
	void			*mlx_ground_img;
	void			*mlx_player_front_img;
	void			*mlx_player_left_img;
	void			*mlx_player_right_img;
	void			*mlx_collectible1_img;
	void			*mlx_collectible2_img;
	void			*mlx_collectible3_img;
	void			*mlx_collectible4_img;
	void			*mlx_enemy1_img;
	void			*mlx_enemy2_img;
	void			*mlx_exit_img;
	struct s_game	*game;
}	t_mlx;

typedef struct s_game
{
	char	**map;
	int		width;
	int		height;
	int		map_width;
	int		map_height;
	int		p_vrt_pos;
	int		p_hrz_pos;
	int		nb_collectibles;
	int		movement_count;
	int		player_direction;
	int		enemy_direction;
	int		enemy_x_pos;
	int		enemy_y_pos;
	int		enemy_counter;
	int		coin_counter;
	void	*current_collectible_img;
}	t_game;

//=======================  GAME  ============================

void	display_images(t_mlx *mlx);
void	update_player_position(t_game *game);
void	print_movement_count_on_window(t_mlx *mlx);
void	print_movement_count_on_terminal(t_mlx *mlx);
int		init_images(t_mlx *mlx);
int		init_images2(t_mlx *mlx);

//===================  MAP PARSING  ==========================

char	**set_map(char *map_file, t_game *game);
char	**del_carriage_return(char **map, t_game *game);
char	**del_double_null_char(char **map, int map_nb_line);
int		check_map_errors(t_game *game);
int		nb_map_row(char *name);
int		file_name_extension_error(char *file);
int		check_map_characters(char **map);
int		check_rectangular_map(char **map);
int		check_map_surrounded_by_walls(char **map);
int		check_number_of_player(char **map);
int		check_number_of_collectible_and_exit(t_game *game);

// ==================  GAME ANIMATION  ======================

int		animation_handler(t_mlx *mlx);
int		init_characters_movement(int keycode, t_mlx *mlx);
void	set_coin_animation(t_mlx *mlx);
void	coin_animation(t_mlx *mlx, int i, int j);
void	set_player_animation(t_mlx *mlx, int direction);
void	player_move_up(t_mlx *mlx, t_game *game);
void	player_move_down(t_mlx *mlx, t_game *game);
void	player_move_left(t_mlx *mlx, t_game *game);
void	player_move_right(t_mlx *mlx, t_game *game);
void	set_enemy_animation(t_mlx *mlx);
void	init_enemy_movement(t_mlx *mlx);
void	randomize_enemy_direction(t_mlx *mlx, int i, int j);
void	enemy_move_up_then_random(t_mlx *mlx, int i, int j);
void	enemy_move_down_then_random(t_mlx *mlx, int i, int j);
void	enemy_move_left_then_random(t_mlx *mlx, int i, int j);
void	enemy_move_right_then_random(t_mlx *mlx, int i, int j);

// ====================  FREE  ==============================

void	ft_free_map(char **map);
void	free_mlx_and_map(t_mlx *mlx);
void	free_img(t_mlx *mlx);
int		free_all(t_mlx *mlx);

// ======================  GNL  ==============================

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *buffer);
char	*ft_get_line(char *stash);
char	*ft_set_stash(char *stash);
int		still_on_line(char *stash);

// ====================  UTILS  =============================
size_t	ft_strlen(char *str);
void	ft_putnbr(int nb);
void	ft_swap(char *a, char *b);
char	*ft_itoa(int n);
char	*ft_fill_arr(unsigned int value, int i, int neg);

// ====================  VAR INITS ==========================

void	set_game_variable(t_mlx *mlx);
void	set_imgs_to_null(t_mlx *mlx);
void	init_struct_and_var(t_mlx *mlx);

#endif
