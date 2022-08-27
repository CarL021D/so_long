/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caboudar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 06:02:18 by caboudar          #+#    #+#             */
/*   Updated: 2022/08/26 09:39:55 by caboudar         ###   ########.fr       */
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
	return (1);
}
