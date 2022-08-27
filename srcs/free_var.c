/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_var.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caboudar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 08:10:52 by caboudar          #+#    #+#             */
/*   Updated: 2022/08/27 13:49:06 by caboudar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_mlx_and_map(t_mlx *mlx)
{
	ft_free_map(mlx->game->map);
	mlx_destroy_display(mlx->mlx);
	free(mlx->mlx);
	exit(EXIT_SUCCESS);
}

void	free_img(t_mlx *mlx)
{
	if (mlx->mlx_wall_img != NULL)
		mlx_destroy_image(mlx->mlx, mlx->mlx_wall_img);
	if (mlx->mlx_ground_img != NULL)
		mlx_destroy_image(mlx->mlx, mlx->mlx_ground_img);
	if (mlx->mlx_player_front_img != NULL)
		mlx_destroy_image(mlx->mlx, mlx->mlx_player_front_img);
	if (mlx->mlx_player_left_img != NULL)
		mlx_destroy_image(mlx->mlx, mlx->mlx_player_left_img);
	if (mlx->mlx_player_right_img != NULL)
		mlx_destroy_image(mlx->mlx, mlx->mlx_player_right_img);
	if (mlx->mlx_collectible1_img != NULL)
		mlx_destroy_image(mlx->mlx, mlx->mlx_collectible1_img);
	if (mlx->mlx_collectible2_img != NULL)
		mlx_destroy_image(mlx->mlx, mlx->mlx_collectible2_img);
	if (mlx->mlx_collectible3_img != NULL)
		mlx_destroy_image(mlx->mlx, mlx->mlx_collectible3_img);
	if (mlx->mlx_collectible4_img != NULL)
		mlx_destroy_image(mlx->mlx, mlx->mlx_collectible4_img);
	if (mlx->mlx_exit_img != NULL)
		mlx_destroy_image(mlx->mlx, mlx->mlx_exit_img);
}

void	ft_free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}

int	free_all(t_mlx *mlx)
{
	ft_free_map(mlx->game->map);
	mlx_destroy_window(mlx->mlx, mlx->window);
	free_img(mlx);
	mlx_destroy_display(mlx->mlx);
	free(mlx->mlx);
	exit(EXIT_SUCCESS);
}
