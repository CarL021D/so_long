/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_enemy_movement.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caboudar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 11:12:59 by caboudar          #+#    #+#             */
/*   Updated: 2022/08/25 12:46:32 by caboudar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	randomize_enemy_direction(t_mlx *mlx, int i, int j)
{
	if (mlx->game->enemy_direction == UP_DIR)
		enemy_move_up_then_random(mlx, i, j);
	else if (mlx->game->enemy_direction == LEFT_DIR)
		enemy_move_left_then_random(mlx, i, j);
	else if (mlx->game->enemy_direction == RIGHT_DIR)
		enemy_move_right_then_random(mlx, i, j);
}

void	init_enemy_movement(t_mlx *mlx)
{
	int		i;
	int		j;

	i = -1;
	while (mlx->game->map[++i])
	{
		j = -1;
		while (mlx->game->map[i][++j])
		{
			if (mlx->game->map[i][j] == 'V')
			{
				if (mlx->game->enemy_direction == DOWN_DIR)
				{
					enemy_move_down_then_random(mlx, i, j);
					if (mlx->game->map[i + 2])
						i += 2;
				}
				else
					randomize_enemy_direction(mlx, i, j);
				break ;
			}
		}
	}
	display_images(mlx);
}
