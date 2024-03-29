/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caboudar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 08:29:54 by caboudar          #+#    #+#             */
/*   Updated: 2022/08/27 13:24:45 by caboudar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	set_game_variable(t_mlx *mlx)
{
	init_struct_and_var(mlx);
	set_imgs_to_null(mlx);
}

void	init_struct_and_var(t_mlx *mlx)
{
	mlx->game->movement_count = 0;
	mlx->game->coin_counter = 0;
	mlx->game->enemy_anim_counter = 0;
	mlx->game->enemy_direction = UP_DIR;
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
	mlx->mlx_enemy1_img = NULL;
	mlx->mlx_enemy2_img = NULL;
	mlx->mlx_exit_img = NULL;
}
