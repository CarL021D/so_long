/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_enemy_movement.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caboudar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 11:12:59 by caboudar          #+#    #+#             */
/*   Updated: 2022/08/18 20:59:13 by caboudar         ###   ########.fr       */
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
            if (mlx->game->map[i][j] == 'V' && mlx->game->enemy_direction == 1)
                {
	                enemy_move_up(mlx, i, j);
                
                }
            if (mlx->game->map[i][j] == 'V' && mlx->game->enemy_direction == 2
                && (mlx->game->enemy_counter_move >= 100000 && mlx->game->enemy_counter_move < 200000))
	            {   
                    enemy_move_down(mlx, i, j);
                
                }
            if (mlx->game->map[i][j] == 'V' && mlx->game->enemy_direction == 3
                && (mlx->game->enemy_counter_move >= 200000 && mlx->game->enemy_counter_move < 300000))
	       	    {
                    enemy_move_left(mlx, i, j);
                
                }
            if (mlx->game->map[i][j] == 'V' && mlx->game->enemy_direction == 4)
	           	{   
                    enemy_move_right(mlx, i, j);
                
                }
            
            if (mlx->game->enemy_counter_move >= 40000)
                mlx->game->enemy_counter_move = 0;
            mlx->game->enemy_counter_move++;
            // printf("%d\n", mlx->game->enemy_counter_move);
	        // if (mlx->game->enemy_counter_move >= 40000)
        }
        
    }
    
    printf("%d\n", mlx->game->enemy_direction);
}


void    enemy_move_up(t_mlx *mlx, int i, int j)
{     
    if (mlx->game->map[i - 1][j] == '1' || mlx->game->map[i - 1][j] == 'C'
        || mlx->game->map[i - 1][j] == 'E' || mlx->game->map[i - 1][j] == 'V')
    {   
        mlx->game->enemy_direction = 3;
        return;
    }
    else
    {
        mlx->game->map[i - 1][j] = 'V';
        mlx->game->map[i][j] = '0';
    }
}

void    enemy_move_down(t_mlx *mlx, int i, int j)
{
    if (mlx->game->map[i + 1][j] == '1' || mlx->game->map[i + 1][j] == 'C' 
        || mlx->game->map[i + 1][j] == 'E' || mlx->game->map[i + 1][j] == 'V')
    {   
        mlx->game->enemy_direction = 4;
        return;
    }        
    else
    {
        mlx->game->map[i + 1][j] = 'V';
        mlx->game->map[i][j] = '0';
    }
}


void    enemy_move_left(t_mlx *mlx, int i, int j)
{
    if (mlx->game->map[i][j] == 'V' && (mlx->game->map[i][j - 1] == '1'
        || mlx->game->map[i][j - 1] == 'C' || mlx->game->map[i][j - 1] == 'E'
            || mlx->game->map[i][j - 1] == 'V'))
    {
        mlx->game->enemy_direction = 2;
        return;
    }
    else
    {
        mlx->game->map[i][j - 1] = 'V';
        mlx->game->map[i][j] = '0';
    }     
}

void    enemy_move_right(t_mlx *mlx, int i, int j)
{
    while (mlx->game->map[i][++j])
    {
	    if (mlx->game->map[i][j] == 'V' && (mlx->game->map[i][j + 1] == '1'
            || mlx->game->map[i][j + 1] == 'C' || mlx->game->map[i][j + 1] == 'E'
                || mlx->game->map[i][j + 1] == 'V'))
        {
            mlx->game->enemy_direction = 1;
            return;
        }
        else
        {
            mlx->game->map[i][j + 1] = 'V';
            mlx->game->map[i][j] = '0';
        }
    }
}
