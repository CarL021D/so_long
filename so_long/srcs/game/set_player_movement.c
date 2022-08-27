/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_player_movement.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caboudar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 07:00:08 by caboudar          #+#    #+#             */
/*   Updated: 2022/08/26 09:42:52 by caboudar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_move_up(t_mlx *mlx, t_game *game)
{
	if ((game->map[game->p_vrt_pos - 1][game->p_hrz_pos] == '0')
		|| (game->map[game->p_vrt_pos - 1][game->p_hrz_pos] == 'C'))
	{
		if (game->map[game->p_vrt_pos - 1][game->p_hrz_pos] == 'C')
			game->nb_collectibles--;
		game->map[game->p_vrt_pos - 1][game->p_hrz_pos] = 'P';
		game->map[game->p_vrt_pos][game->p_hrz_pos] = '0';
		mlx->game->movement_count++;
		print_movement_count_on_terminal(mlx);
	}
	if (game->map[game->p_vrt_pos - 1][game->p_hrz_pos] == 'E'
		&& !game->nb_collectibles)
	{
		mlx->game->movement_count++;
		print_movement_count_on_terminal(mlx);
		free_all(mlx);
	}
	set_player_animation(mlx, 1);
	display_images(mlx);
}

void	player_move_down(t_mlx *mlx, t_game *game)
{
	if (game->map[game->p_vrt_pos + 1][game->p_hrz_pos] == '0'
		|| game->map[game->p_vrt_pos + 1][game->p_hrz_pos] == 'C')
	{
		if (game->map[game->p_vrt_pos + 1][game->p_hrz_pos] == 'C')
			game->nb_collectibles--;
		game->map[game->p_vrt_pos + 1][game->p_hrz_pos] = 'P';
		game->map[game->p_vrt_pos][game->p_hrz_pos] = '0';
		mlx->game->movement_count++;
		print_movement_count_on_terminal(mlx);
	}
	if (game->map[game->p_vrt_pos + 1][game->p_hrz_pos] == 'E'
		&& !game->nb_collectibles)
	{
		mlx->game->movement_count++;
		print_movement_count_on_terminal(mlx);
		free_all(mlx);
	}
	set_player_animation(mlx, 1);
	display_images(mlx);
}

void	player_move_left(t_mlx *mlx, t_game *game)
{
	if (game->map[game->p_vrt_pos][game->p_hrz_pos - 1] == '0'
		|| game->map[game->p_vrt_pos][game->p_hrz_pos - 1] == 'C')
	{
		if (game->map[game->p_vrt_pos][game->p_hrz_pos - 1] == 'C')
			game->nb_collectibles--;
		game->map[game->p_vrt_pos][game->p_hrz_pos - 1] = 'P';
		game->map[game->p_vrt_pos][game->p_hrz_pos] = '0';
		mlx->game->movement_count++;
		print_movement_count_on_terminal(mlx);
	}
	if (game->map[game->p_vrt_pos][game->p_hrz_pos - 1] == 'E'
		&& !game->nb_collectibles)
	{
		mlx->game->movement_count++;
		print_movement_count_on_terminal(mlx);
		free_all(mlx);
	}
	set_player_animation(mlx, 2);
	display_images(mlx);
}

void	player_move_right(t_mlx *mlx, t_game *game)
{
	if (game->map[game->p_vrt_pos][game->p_hrz_pos + 1] == '0'
		|| game->map[game->p_vrt_pos][game->p_hrz_pos + 1] == 'C')
	{
		if (game->map[game->p_vrt_pos][game->p_hrz_pos + 1] == 'C')
			game->nb_collectibles--;
		game->map[game->p_vrt_pos][game->p_hrz_pos + 1] = 'P';
		game->map[game->p_vrt_pos][game->p_hrz_pos] = '0';
		mlx->game->movement_count++;
		print_movement_count_on_terminal(mlx);
	}
	if (game->map[game->p_vrt_pos][game->p_hrz_pos + 1] == 'E'
		&& !game->nb_collectibles)
	{
		mlx->game->movement_count++;
		print_movement_count_on_terminal(mlx);
		free_all(mlx);
	}
	set_player_animation(mlx, 3);
	display_images(mlx);
}