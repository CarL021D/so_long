/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_enemy_movement.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caboudar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 11:12:59 by caboudar          #+#    #+#             */
/*   Updated: 2022/08/23 14:27:38 by caboudar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    init_enemy_movement(t_mlx *mlx)
{
    int     i;
    int     j;

    i = -1;
    while (mlx->game->map[++i])
	{
		j = -1;
        while (mlx->game->map[i][++j])
		{
            if (mlx->game->map[i][j] == 'V')
            {
                if (mlx->game->enemy_direction == UP_DIR)
                {
	                enemy_move_up(mlx, i , j);
                    break;
                }
                else if (mlx->game->enemy_direction == DOWN_DIR)
	           	{    
                    enemy_move_down(mlx, i , j);
                    if (mlx->game->map[i + 2])
                        i += 2;
                    else
                    {
                        display_images(mlx);
                        return;
                    }
                    break;
                }
                else if (mlx->game->enemy_direction == LEFT_DIR)
                {
	                enemy_move_left(mlx, i , j);
                    break;
                }
                else if (mlx->game->enemy_direction == RIGHT_DIR)
                {
                    enemy_move_right(mlx, i , j);
                    break;
                }
            }
        }
    }
    display_images(mlx);
}

void    enemy_move_up(t_mlx *mlx, int i, int j)
{    
	if (mlx->game->map[i - 1][j] == '0')
        ft_swap(&mlx->game->map[i - 1][j], &mlx->game->map[i][j]);
    else if (mlx->game->map[i - 1][j] == 'P')
        free_all(mlx);
    else
    {
        mlx->game->enemy_direction = LEFT_DIR;
        if (mlx->game->map[i][j - 1] == '0')
            enemy_move_left(mlx, i , j);
        if (mlx->game->map[i][j + 1] == '0')
            enemy_move_right(mlx, i ,j);
        if (mlx->game->map[i + 1][j] == '0')
            enemy_move_down(mlx, i , j);
    }
}

void    enemy_move_down(t_mlx *mlx, int i, int j)
{
    if (mlx->game->map[i + 1][j] == '0')
        ft_swap(&mlx->game->map[i + 1][j], &mlx->game->map[i][j]);
    else if (mlx->game->map[i + 1][j] == 'P')
        free_all(mlx);
    else
    {
        mlx->game->enemy_direction = RIGHT_DIR;
        if (mlx->game->map[i][j + 1] == '0')
            enemy_move_right(mlx, i ,j);
        if (mlx->game->map[i][j - 1] == '0')
            enemy_move_left(mlx, i , j);
        if (mlx->game->map[i - 1][j] == '0')
            enemy_move_up(mlx, i ,j);
    }
}

void    enemy_move_left(t_mlx *mlx, int i, int j)
{
    if (mlx->game->map[i][j - 1] == '0')
        ft_swap(&mlx->game->map[i][j - 1], &mlx->game->map[i][j]);
    else if (mlx->game->map[i][j - 1] == 'P')
        free_all(mlx);
    else
    {
        mlx->game->enemy_direction = DOWN_DIR;
        if (mlx->game->map[i - 1][j] == '0')
            enemy_move_up(mlx, i ,j);
        if (mlx->game->map[i][j + 1] == '0')
            enemy_move_right(mlx, i ,j);
        if (mlx->game->map[i + 1][j] == '0')
            enemy_move_down(mlx, i , j);
    }
}

void    enemy_move_right(t_mlx *mlx, int i, int j)
{
    if (mlx->game->map[i][j + 1] == '0')
        ft_swap(&mlx->game->map[i][j + 1], &mlx->game->map[i][j]);
    else if (mlx->game->map[i][j + 1] == 'P')
        free_all(mlx);
    else
    {
        mlx->game->enemy_direction = UP_DIR;
        if (mlx->game->map[i - 1][j] == '0')
            enemy_move_up(mlx, i , j);
        if (mlx->game->map[i][j - 1] == '0')
            enemy_move_left(mlx, i , j);
        if (mlx->game->map[i + 1][j] == '0')
            enemy_move_down(mlx, i , j);
    }
}
