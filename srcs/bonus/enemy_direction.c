/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_direction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caboudar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 12:39:50 by caboudar          #+#    #+#             */
/*   Updated: 2022/08/27 13:24:10 by caboudar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	enemy_move_up_then_random(t_mlx *mlx, int i, int j)
{
	if (mlx->game->map[i - 1][j] == '0')
		ft_swap(&mlx->game->map[i - 1][j], &mlx->game->map[i][j]);
	else if (mlx->game->map[i - 1][j] == 'P')
		free_all(mlx);
	else
	{
		mlx->game->enemy_direction = LEFT_DIR;
		if (mlx->game->map[i][j - 1] == '0')
			enemy_move_left_then_random(mlx, i, j);
		if (mlx->game->map[i][j + 1] == '0')
			enemy_move_right_then_random(mlx, i, j);
		if (mlx->game->map[i + 1][j] == '0')
			enemy_move_down_then_random(mlx, i, j);
	}
}

void	enemy_move_down_then_random(t_mlx *mlx, int i, int j)
{
	if (mlx->game->map[i + 1][j] == '0')
		ft_swap(&mlx->game->map[i + 1][j], &mlx->game->map[i][j]);
	else if (mlx->game->map[i + 1][j] == 'P')
		free_all(mlx);
	else
	{
		mlx->game->enemy_direction = RIGHT_DIR;
		if (mlx->game->map[i][j + 1] == '0')
			enemy_move_right_then_random(mlx, i, j);
		if (mlx->game->map[i][j - 1] == '0')
			enemy_move_left_then_random(mlx, i, j);
		if (mlx->game->map[i - 1][j] == '0')
			enemy_move_up_then_random(mlx, i, j);
	}
}

void	enemy_move_left_then_random(t_mlx *mlx, int i, int j)
{
	if (mlx->game->map[i][j - 1] == '0')
		ft_swap(&mlx->game->map[i][j - 1], &mlx->game->map[i][j]);
	else if (mlx->game->map[i][j - 1] == 'P')
		free_all(mlx);
	else
	{
		mlx->game->enemy_direction = DOWN_DIR;
		if (mlx->game->map[i - 1][j] == '0')
			enemy_move_up_then_random(mlx, i, j);
		if (mlx->game->map[i][j + 1] == '0')
			enemy_move_right_then_random(mlx, i, j);
		if (mlx->game->map[i + 1][j] == '0')
			enemy_move_down_then_random(mlx, i, j);
	}
}

void	enemy_move_right_then_random(t_mlx *mlx, int i, int j)
{
	if (mlx->game->map[i][j + 1] == '0')
		ft_swap(&mlx->game->map[i][j + 1], &mlx->game->map[i][j]);
	else if (mlx->game->map[i][j + 1] == 'P')
		free_all(mlx);
	else
	{
		mlx->game->enemy_direction = UP_DIR;
		if (mlx->game->map[i - 1][j] == '0')
			enemy_move_up_then_random(mlx, i, j);
		if (mlx->game->map[i][j - 1] == '0')
			enemy_move_left_then_random(mlx, i, j);
		if (mlx->game->map[i + 1][j] == '0')
			enemy_move_down_then_random(mlx, i, j);
	}
}
