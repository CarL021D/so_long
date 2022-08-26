/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caboudar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 11:01:15 by caboudar          #+#    #+#             */
/*   Updated: 2022/08/26 10:06:04 by caboudar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_movement_count_on_terminal(t_mlx *mlx)
{
	ft_putnbr(mlx->game->movement_count);
	write(1, "\n", 1);
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
				return ;
			}
		}
	}
}
