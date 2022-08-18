/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player_movement.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caboudar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 07:00:08 by caboudar          #+#    #+#             */
/*   Updated: 2022/08/18 08:31:53 by caboudar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_player_movement(int keycode, t_mlx *mlx)
{
	update_player_position(mlx->game);
	if (keycode == ESC)
		free_all(mlx);
	if (keycode == UP)
		move_up(mlx, mlx->game);
	if (keycode == DOWN)
		move_down(mlx, mlx->game);
	if (keycode == LEFT)
		move_left(mlx, mlx->game);
	if (keycode == RIGHT)
		move_right(mlx, mlx->game);
	return (0);
}

void	move_up(t_mlx *mlx, t_game *game)
{
	if ((game->map[game->p_vrt_pos - 1][game->p_hrz_pos] == '0')
		|| (game->map[game->p_vrt_pos - 1][game->p_hrz_pos] == 'C'))
	{
		if (game->map[game->p_vrt_pos - 1][game->p_hrz_pos] == 'C')
			game->nb_collectibles--;
		game->map[game->p_vrt_pos - 1][game->p_hrz_pos] = 'P';
		game->map[game->p_vrt_pos][game->p_hrz_pos] = '0';
		mlx->game->movement_count++;
	}
	if (game->map[game->p_vrt_pos - 1][game->p_hrz_pos] == 'E'
		&& !game->nb_collectibles)
		free_all(mlx);
	if (game->map[game->p_vrt_pos - 1][game->p_hrz_pos] == 'V')
		free_all(mlx);
	print_movement_count_on_terminal(mlx);
	player_animation(mlx, 1);
	display_images(mlx);
}

void	move_down(t_mlx *mlx, t_game *game)
{
	if (game->map[game->p_vrt_pos + 1][game->p_hrz_pos] == '0'
		|| game->map[game->p_vrt_pos + 1][game->p_hrz_pos] == 'C')
	{
		if (game->map[game->p_vrt_pos + 1][game->p_hrz_pos] == 'C')
			game->nb_collectibles--;
		game->map[game->p_vrt_pos + 1][game->p_hrz_pos] = 'P';
		game->map[game->p_vrt_pos][game->p_hrz_pos] = '0';
		mlx->game->movement_count++;
	}
	if (game->map[game->p_vrt_pos + 1][game->p_hrz_pos] == 'E'
		&& !game->nb_collectibles)
		free_all(mlx);
	if (game->map[game->p_vrt_pos + 1][game->p_hrz_pos] == 'V')
		free_all(mlx);
	print_movement_count_on_terminal(mlx);
	player_animation(mlx, 1);
	display_images(mlx);
}

void	move_left(t_mlx *mlx, t_game *game)
{
	if (game->map[game->p_vrt_pos][game->p_hrz_pos - 1] == '0'
		|| game->map[game->p_vrt_pos][game->p_hrz_pos - 1] == 'C')
	{
		if (game->map[game->p_vrt_pos][game->p_hrz_pos - 1] == 'C')
			game->nb_collectibles--;
		game->map[game->p_vrt_pos][game->p_hrz_pos - 1] = 'P';
		game->map[game->p_vrt_pos][game->p_hrz_pos] = '0';
		mlx->game->movement_count++;
	}
	if (game->map[game->p_vrt_pos][game->p_hrz_pos - 1] == 'E'
		&& !game->nb_collectibles)
		free_all(mlx);
	if (game->map[game->p_vrt_pos][game->p_hrz_pos - 1] == 'V')
		free_all(mlx);
	print_movement_count_on_terminal(mlx);
	player_animation(mlx, 2);
	display_images(mlx);
}

void	move_right(t_mlx *mlx, t_game *game)
{
	if (game->map[game->p_vrt_pos][game->p_hrz_pos + 1] == '0'
		|| game->map[game->p_vrt_pos][game->p_hrz_pos + 1] == 'C')
	{
		if (game->map[game->p_vrt_pos][game->p_hrz_pos + 1] == 'C')
			game->nb_collectibles--;
		game->map[game->p_vrt_pos][game->p_hrz_pos + 1] = 'P';
		game->map[game->p_vrt_pos][game->p_hrz_pos] = '0';
		mlx->game->movement_count++;
	}
	if (game->map[game->p_vrt_pos][game->p_hrz_pos + 1] == 'E'
		&& !game->nb_collectibles)
		free_all(mlx);
	if (game->map[game->p_vrt_pos][game->p_hrz_pos + 1] == 'V')
		free_all(mlx);
	print_movement_count_on_terminal(mlx);
	player_animation(mlx, 3);
	display_images(mlx);
}
