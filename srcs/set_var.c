/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caboudar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 08:29:54 by caboudar          #+#    #+#             */
/*   Updated: 2022/08/27 13:50:17 by caboudar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	set_game_variable(t_mlx *mlx)
{
	init_struct_and_var(mlx);
	set_imgs_to_null(mlx);
}

void	init_struct_and_var(t_mlx *mlx)
{
	mlx->game->movement_count = 0;
	mlx->game->coin_counter = 0;
}

void	set_imgs_to_null(t_mlx *mlx)
{
	mlx->mlx_wall_img = NULL;
	mlx->mlx_ground_img = NULL;
	mlx->mlx_player_front_img = NULL;
	mlx->mlx_player_left_img = NULL;
	mlx->mlx_player_right_img = NULL;
	mlx->mlx_collectible1_img = NULL;
	mlx->mlx_collectible2_img = NULL;
	mlx->mlx_collectible3_img = NULL;
	mlx->mlx_collectible4_img = NULL;
	mlx->mlx_exit_img = NULL;
}
