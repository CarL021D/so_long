/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_name.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caboudar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 08:02:05 by caboudar          #+#    #+#             */
/*   Updated: 2022/08/27 14:13:53 by caboudar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	file_name_extension_error(char *file)
{
	char	*extension;
	int		i;
	int		j;

	extension = ".ber";
	i = 0;
	while ((extension[i] && file[i]) && extension[i] == file[i])
		i++;
	if (!extension[i])
		return (write(1, "Error! the map can not be named '.ber'\n", 39), 1);
	i = 0;
	j = ft_strlen(file) - 4;
	while ((extension[i] && file[j]) && extension[i] == file[j])
	{
		i++;
		j++;
	}
	if (extension[i])
		return (write(1, "Error!, map name must end up with '.ber'\n", 41), 1);
	return (0);
}
