/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caboudar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 03:12:37 by caboudar          #+#    #+#             */
/*   Updated: 2022/08/18 18:15:00 by caboudar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define BUFFER_SIZE 1
# define ESC 65307
# define UP 119
# define DOWN 115
# define LEFT 97
# define RIGHT 100

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
	int		enemy_direction;

	int		enemy_counter_anim;
	int		enemy_counter_move;
	
	
	void	*current_collectible_img;
	
	
	int		coin_counter;
}	t_game;

// ====================  GNL  ==============================
int		still_on_line(char *stash);
char	*ft_strjoin(char *s1, char *buffer);
char	*ft_get_line(char *stash);
char	*ft_set_stash(char *stash);
char	*get_next_line(int fd);

// ====================  SO_LONG ===========================

int	init_player_movement(int keycode, t_mlx *mlx);
void	move_up(t_mlx *mlx, t_game *game);
void	move_down(t_mlx *mlx, t_game *game);
void	move_left(t_mlx *mlx, t_game *game);
void	move_right(t_mlx *mlx, t_game *game);
void	update_player_position(t_game *game);
int	print_player_movement(t_mlx *mlx);
int	free_all(t_mlx *mlx);

//=====================  PARSING  ==========================
void	ft_free_map(char **map);
void	free_mlx_and_map(t_mlx *mlx);
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

//=======================  GAME  ==========================
int		init_images(t_mlx *mlx);
int		init_images2(t_mlx *mlx);
void	display_images(t_mlx *mlx);
void	player_animation(t_mlx *mlx, int direction);
void	update_player_position(t_game *game);
void		print_movement_count_on_window(t_mlx *mlx);
void		print_movement_count_on_terminal(t_mlx *mlx);


// ===================  UTILS  =============================
size_t	ft_strlen(char *str);
void	ft_putnbr(int nb);
char	*ft_itoa(int n);
char	*ft_fill_arr(unsigned int value, int i, int neg);


void	coin_animation(t_mlx *mlx);

int		looping_func(t_mlx *mlx);

void	enemy_animation(t_mlx *mlx);
void	init_enemy_movement(t_mlx *mlx);
void    enemy_move_up(t_mlx *mlx, int i, int j);
void    enemy_move_down(t_mlx *mlx, int i, int j);
void    enemy_move_left(t_mlx *mlx, int i, int j);
void    enemy_move_right(t_mlx *mlx, int i, int j);

#endif
