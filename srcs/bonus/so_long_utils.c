/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caboudar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 11:01:15 by caboudar          #+#    #+#             */
/*   Updated: 2022/08/27 13:24:47 by caboudar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

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
	free(num);
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
