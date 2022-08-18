/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caboudar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 03:12:03 by caboudar          #+#    #+#             */
/*   Updated: 2022/08/16 11:57:56 by caboudar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map_errors(t_game *game)
{
	if (!game->map[0])
		return (write(1, "Error!, no map at all\n", 22), 0);
	if (!check_map_characters(game->map))
		return (write(1, "Error!, there are some invalid characters\n", 41), 0);
	if (!check_rectangular_map(game->map))
		return (write(1, "Error!, map not rectangular\n", 28), 0);
	if (!check_map_surrounded_by_walls(game->map))
		return (write(1, "Error!, map must be surrounded by walls\n", 40), 0);
	if (!check_number_of_player(game->map))
		return (write(1, "Error!, there is more than one player\n", 38), 0);
	if (!check_number_of_collectible_and_exit(game))
		return (write(1, "Error!, missing collectibles or exits\n", 38), 0);
	return (1);
}

int	check_map_characters(char **map)
{
	int		i;
	int		j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
			if ((map[i][j] != '1') && (map[i][j] != '0')
				&& (map[i][j] != 'C') && (map[i][j]) != 'P'
				&& (map[i][j] != 'E') && (map[i][j] != 'V'))
				return (0);
	}
	return (1);
}

int	check_rectangular_map(char **map)
{
	int		i;
	int		first_row_length;
	int		row_length;

	i = 1;
	first_row_length = ft_strlen(map[0]);
	while (map[i])
	{
		row_length = ft_strlen(map[i]);
		if (first_row_length != row_length)
			return (0);
		i++;
	}
	return (1);
}

int	check_map_surrounded_by_walls(char **map)
{
	int		i;
	int		j;
	int		row_count;
	int		row_last_index;

	i = -1;
	row_count = 0;
	while (map[++i])
		row_count++;
	row_count -= 1;
	i = -1;
	row_last_index = (ft_strlen(map[0]) - 1);
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if ((i == 0 || i == row_count) && map[i][j] != '1')
				return (0);
			else if ((i != 0 && i != row_count)
				&& (map[i][0] != '1' || map[i][row_last_index] != '1'))
				return (0);
		}
	}
	return (1);
}
