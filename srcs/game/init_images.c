/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caboudar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 06:02:18 by caboudar          #+#    #+#             */
/*   Updated: 2022/08/18 21:01:11 by caboudar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_images(t_mlx *mlx)
{
	mlx->mlx_wall_img = mlx_xpm_file_to_image(mlx->mlx,
			"./assets/brick_wall.xpm", &mlx->game->width, &mlx->game->height);
	if (!mlx->mlx_wall_img)
		return (0);
	mlx->mlx_ground_img = mlx_xpm_file_to_image(mlx->mlx,
			"./assets/ground.xpm", &mlx->game->width, &mlx->game->height);
	if (!mlx->mlx_ground_img)
		return (0);
	mlx->mlx_player_front_img = mlx_xpm_file_to_image(mlx->mlx,
			"./assets/player_front.xpm", &mlx->game->width, &mlx->game->height);
	if (!mlx->mlx_player_front_img)
		return (0);
	mlx->mlx_player_left_img = mlx_xpm_file_to_image(mlx->mlx,
			"./assets/player_left.xpm", &mlx->game->width, &mlx->game->height);
	if (!mlx->mlx_player_left_img)
		return (0);
	mlx->mlx_player_right_img = mlx_xpm_file_to_image(mlx->mlx,
			"./assets/player_right.xpm", &mlx->game->width, &mlx->game->height);
	if (!mlx->mlx_player_right_img)
		return (0);
	mlx->mlx_exit_img = mlx_xpm_file_to_image(mlx->mlx,
			"./assets/exit.xpm", &mlx->game->width, &mlx->game->height);
	if (!mlx->mlx_exit_img)
		return (0);
	return (1);
}

int	init_images2(t_mlx *mlx)
{
	mlx->mlx_collectible1_img = mlx_xpm_file_to_image(mlx->mlx,
			"./assets/collectible1.xpm", &mlx->game->width, &mlx->game->height);
	if (!mlx->mlx_collectible1_img)
		return (0);
	mlx->mlx_collectible2_img = mlx_xpm_file_to_image(mlx->mlx,
			"./assets/collectible2.xpm", &mlx->game->width, &mlx->game->height);
	if (!mlx->mlx_collectible2_img)
		return (0);
	mlx->mlx_collectible3_img = mlx_xpm_file_to_image(mlx->mlx,
			"./assets/collectible3.xpm", &mlx->game->width, &mlx->game->height);
	if (!mlx->mlx_collectible3_img)
		return (0);
	mlx->mlx_collectible4_img = mlx_xpm_file_to_image(mlx->mlx,
			"./assets/collectible4.xpm", &mlx->game->width, &mlx->game->height);
	if (!mlx->mlx_collectible4_img)
		return (0);
	mlx->mlx_enemy1_img = mlx_xpm_file_to_image(mlx->mlx,
			"./assets/enemy1.xpm", &mlx->game->width, &mlx->game->height);
	if (!mlx->mlx_enemy1_img)
		return (0);
	mlx->mlx_enemy2_img = mlx_xpm_file_to_image(mlx->mlx,
			"./assets/enemy2.xpm", &mlx->game->width, &mlx->game->height);
	if (!mlx->mlx_enemy2_img)
		return (0);
	return (1);
}






void	player_animation(t_mlx *mlx, int direction)
{
	int		i;
	int		j;

	i = -1;
	while (mlx->game->map[++i])
	{
		j = -1;
		while (mlx->game->map[i][++j])
		{
			if (mlx->game->map[i][j] == 'P' && direction == 1)
				mlx_put_image_to_window(mlx->mlx, mlx->window,
					mlx->mlx_player_front_img, (j * 32), (i * 32));
			if (mlx->game->map[i][j] == 'P' && direction == 2)
				mlx_put_image_to_window(mlx->mlx, mlx->window,
					mlx->mlx_player_left_img, (j * 32), (i * 32));
			if (mlx->game->map[i][j] == 'P' && direction == 3)
				mlx_put_image_to_window(mlx->mlx, mlx->window,
					mlx->mlx_player_right_img, (j * 32), (i * 32));
		}
	}
}

int	looping_func(t_mlx *mlx)
{	
	coin_animation(mlx);
	// enemy_animation(mlx);
	init_enemy_movement(mlx);
	print_movement_count_on_window(mlx);
	return (0);
}

void	enemy_animation(t_mlx *mlx)
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
				if (mlx->game->enemy_counter_anim < 3000)
					mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->mlx_enemy1_img, (j * 32), (i * 32));
				if (mlx->game->enemy_counter_anim >= 3000 && mlx->game->enemy_counter_anim < 6000)
					mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->mlx_enemy2_img, (j * 32), (i * 32));
				mlx->game->enemy_counter_anim++;
				if (mlx->game->enemy_counter_anim == 6000)
					mlx->game->enemy_counter_anim = 0;
			}		
		}				
	}		
}

void coin_animation(t_mlx *mlx)
{
	int		i;
	int		j;
	
	i = -1;
	while (mlx->game->map[++i])
	{
		j = -1;
		while (mlx->game->map[i][++j])
		{
			if (mlx->game->map[i][j] == 'C')
			{
				if (mlx->game->coin_counter < 17500)
					mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->mlx_collectible1_img, (j * 32), (i * 32));
				else if (mlx->game->coin_counter >= 17500 && mlx->game->coin_counter < 35000)
					mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->mlx_collectible2_img, (j * 32), (i * 32));
				else if (mlx->game->coin_counter >= 35000 && mlx->game->coin_counter < 47500)
					mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->mlx_collectible3_img, (j * 32), (i * 32));
				else if (mlx->game->coin_counter >= 47500 && mlx->game->coin_counter <  62500)
					mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->mlx_collectible4_img, (j * 32), (i * 32));
				mlx->game->coin_counter++;
				if (mlx->game->coin_counter == 62500)
					mlx->game->coin_counter = 0;
			}		
		}				
	}	
}


void	display_images(t_mlx *mlx)
{
	int	i;
	int	j;

	i = -1;
	while (mlx->game->map[++i])
	{
		j = -1;
		while (mlx->game->map[i][++j])
		{
			if (mlx->game->map[i][j] == '1')
				mlx_put_image_to_window(mlx->mlx, mlx->window,
					mlx->mlx_wall_img, (j * 32), (i * 32));
			if (mlx->game->map[i][j] == '0')
				mlx_put_image_to_window(mlx->mlx, mlx->window,
					mlx->mlx_ground_img, (j * 32), (i * 32));
			if (mlx->game->map[i][j] == 'E')					
				mlx_put_image_to_window(mlx->mlx, mlx->window,
					mlx->mlx_exit_img, (j * 32), (i * 32));
			if (mlx->game->map[i][j] == 'V')
				mlx_put_image_to_window(mlx->mlx, mlx->window,
					mlx->mlx_enemy1_img, (j * 32), (i * 32));
		}
	}
}
