/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caboudar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 11:25:02 by caboudar          #+#    #+#             */
/*   Updated: 2022/08/26 09:41:58 by caboudar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
		}
	}
}
