/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_animations_and_images.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caboudar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 08:42:12 by caboudar          #+#    #+#             */
/*   Updated: 2022/08/26 09:56:52 by caboudar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_player_animation(t_mlx *mlx, int direction)
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

void	coin_animation(t_mlx *mlx, int i, int j)
{
	if (mlx->game->coin_counter < 17500)
		mlx_put_image_to_window(mlx->mlx, mlx->window,
			mlx->mlx_collectible1_img, (j * 32), (i * 32));
	else if (mlx->game->coin_counter >= 17500
		&& mlx->game->coin_counter < 35000)
		mlx_put_image_to_window(mlx->mlx, mlx->window,
			mlx->mlx_collectible2_img, (j * 32), (i * 32));
	else if (mlx->game->coin_counter >= 35000
		&& mlx->game->coin_counter < 47500)
		mlx_put_image_to_window(mlx->mlx, mlx->window,
			mlx->mlx_collectible3_img, (j * 32), (i * 32));
	else if (mlx->game->coin_counter >= 47500
		&& mlx->game->coin_counter < 62500)
		mlx_put_image_to_window(mlx->mlx, mlx->window,
			mlx->mlx_collectible4_img, (j * 32), (i * 32));
	mlx->game->coin_counter++;
	if (mlx->game->coin_counter == 62500)
		mlx->game->coin_counter = 0;
}

int	set_coin_animation(t_mlx *mlx)
{
	int		i;
	int		j;

	i = -1;
	while (mlx->game->map[++i])
	{
		j = -1;
		while (mlx->game->map[i][++j])
			if (mlx->game->map[i][j] == 'C')
				coin_animation(mlx, i, j);
	}
	return (0);
}
