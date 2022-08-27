/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caboudar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 02:49:11 by caboudar          #+#    #+#             */
/*   Updated: 2022/08/27 13:24:15 by caboudar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

int	nb_map_row(char *name)
{
	char	*str;
	int		fd;
	int		nb_line;

	nb_line = 0;
	fd = open(name, O_RDONLY);
	str = get_next_line(fd);
	while (str)
	{
		free(str);
		str = get_next_line(fd);
		nb_line++;
	}
	free(str);
	close(fd);
	return (nb_line);
}

char	**del_carriage_return(char **map, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '\n')
				map[i][j] = '\0';
			j++;
		}
		i++;
	}
	game->map_width = ft_strlen(map[0]);
	return (map);
}

char	**del_double_null_char(char **map, int map_nb_line)
{
	char	**final_map;
	int		i;
	int		j;

	final_map = malloc(sizeof(char *) * (map_nb_line + 1));
	if (!final_map)
		return (NULL);
	i = -1;
	while (map[++i])
	{
		j = -1;
		final_map[i] = malloc(sizeof(char) * (ft_strlen(map[i]) + 1));
		if (!final_map[i])
			return (ft_free_map(final_map), ft_free_map(map), NULL);
		while (map[i][++j])
			final_map[i][j] = map[i][j];
		final_map[i][j] = 0;
	}
	final_map[i] = NULL;
	ft_free_map(map);
	return (final_map);
}

char	**set_map(char *map_file, t_game *game)
{
	int		i;
	char	**map;
	int		fd;
	int		map_nb_line;

	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	map_nb_line = nb_map_row(map_file);
	game->map_height = map_nb_line;
	map = malloc(sizeof(char *) * (map_nb_line + 1));
	if (!map)
		return (NULL);
	i = -1;
	map[++i] = get_next_line(fd);
	while (map[i++])
		map[i] = get_next_line(fd);
	map = del_carriage_return(map, game);
	map = del_double_null_char(map, map_nb_line);
	return (close(fd), map);
}
