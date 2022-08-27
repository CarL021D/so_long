/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_elements.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caboudar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 23:42:24 by caboudar          #+#    #+#             */
/*   Updated: 2022/08/27 13:23:53 by caboudar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

int	check_number_of_player(char **map)
{
	int				i;
	int				j;
	int				number_of_player;

	i = 0;
	number_of_player = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
			if (map[i][j] == 'P')
				number_of_player++;
	}
	if (number_of_player == 1)
		return (1);
	return (0);
}

int	check_number_of_collectible_and_exit(t_game *game)
{
	int		i;
	int		j;
	int		number_of_exits;

	i = 0;
	game->nb_collectibles = 0;
	number_of_exits = 0;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (game->map[i][j] == 'C')
				game->nb_collectibles += 1;
			if (game->map[i][j] == 'E')
				number_of_exits += 1;
		}
	}
	if (game->nb_collectibles >= 1 && number_of_exits >= 1)
		return (1);
	return (0);
}
