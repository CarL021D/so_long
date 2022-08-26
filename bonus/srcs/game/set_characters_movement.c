/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_characters_movement.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caboudar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 08:40:09 by caboudar          #+#    #+#             */
/*   Updated: 2022/08/25 10:53:50 by caboudar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_characters_movement(int keycode, t_mlx *mlx)
{
	update_player_position(mlx->game);
	if (keycode == ESC)
		free_all(mlx);
	if (keycode == UP_KEY)
		player_move_up(mlx, mlx->game);
	if (keycode == DOWN_KEY)
		player_move_down(mlx, mlx->game);
	if (keycode == LEFT_KEY)
		player_move_left(mlx, mlx->game);
	if (keycode == RIGHT_KEY)
		player_move_right(mlx, mlx->game);
	init_enemy_movement(mlx);
	return (0);
}
