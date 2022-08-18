/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caboudar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 11:01:15 by caboudar          #+#    #+#             */
/*   Updated: 2022/08/18 16:16:59 by caboudar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_movement_count_on_terminal(t_mlx *mlx)
{
	ft_putnbr(mlx->game->movement_count);
	write(1, "\n", 1);
}

void	print_movement_count_on_window(t_mlx *mlx)
{
	char	*num;

	num = ft_itoa(mlx->game->movement_count);
	if (!num)
		free_all(mlx);
	mlx_string_put(mlx->mlx, mlx->window, 15, 15, 0x00FFFFFF, num);
}

void	update_player_position(t_game *game)
{
	int		i;
	int		j;

	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (game->map[i][j] == 'P')
			{
				game->p_vrt_pos = i;
				game->p_hrz_pos = j;
				return;
			}
		}
	}
}

void	free_mlx_and_map(t_mlx *mlx)
{
	ft_free_map(mlx->game->map);
	mlx_destroy_display(mlx->mlx);
	free(mlx->mlx);
	exit(EXIT_SUCCESS);
}

int	free_all(t_mlx *mlx)
{
	ft_free_map(mlx->game->map);
	mlx_destroy_window(mlx->mlx, mlx->window);
	mlx_destroy_image(mlx->mlx, mlx->mlx_wall_img);
	mlx_destroy_image(mlx->mlx, mlx->mlx_ground_img);
	mlx_destroy_image(mlx->mlx, mlx->mlx_player_front_img);
	mlx_destroy_image(mlx->mlx, mlx->mlx_player_left_img);
	mlx_destroy_image(mlx->mlx, mlx->mlx_player_right_img);
	mlx_destroy_image(mlx->mlx, mlx->mlx_collectible1_img);
	mlx_destroy_image(mlx->mlx, mlx->mlx_collectible2_img);
	mlx_destroy_image(mlx->mlx, mlx->mlx_collectible3_img);
	mlx_destroy_image(mlx->mlx, mlx->mlx_collectible4_img);
	mlx_destroy_image(mlx->mlx, mlx->mlx_enemy1_img);
	mlx_destroy_image(mlx->mlx, mlx->mlx_enemy2_img);
	mlx_destroy_image(mlx->mlx, mlx->mlx_exit_img);
	mlx_destroy_display(mlx->mlx);
	free(mlx->mlx);
	exit(EXIT_SUCCESS);
}

void	ft_free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}
