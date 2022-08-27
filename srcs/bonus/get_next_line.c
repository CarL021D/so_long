/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caboudar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 00:10:11 by caboudar          #+#    #+#             */
/*   Updated: 2022/08/27 13:24:20 by caboudar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

char	*ft_get_line(char *stash)
{
	char	*line;
	int		i;

	if (!stash[0])
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
		i--;
	line = malloc(sizeof(char) * i + 2);
	if (!line)
		return (NULL);
	line[i + 1] = '\0';
	while (i >= 0)
	{
		line[i] = stash[i];
		i--;
	}
	return (line);
}

char	*ft_set_stash(char *stash)
{
	char	*remaining_chars;
	int		i;
	int		j;
	int		len;

	i = 0;
	j = -1;
	while (stash[i] && stash[i] != '\n')
		i++;
	len = ft_strlen(stash) - i;
	if (stash[i] == '\n')
	{
		remaining_chars = malloc(sizeof(char) * len);
		if (!remaining_chars)
			return (free(stash), NULL);
		remaining_chars[len - 1] = '\0';
		while (--len)
			remaining_chars[++j] = stash[++i];
		return (free(stash), remaining_chars);
	}
	else
		return (free(stash), NULL);
}

char	*get_next_line(int fd)
{
	static char		*stash;
	char			*buffer;
	int				read_char;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	read_char = 1;
	while (read_char && !still_on_line(stash))
	{
		read_char = read(fd, buffer, BUFFER_SIZE);
		if (read_char == -1)
			return (free(stash), free(buffer), NULL);
		buffer[read_char] = '\0';
		stash = ft_strjoin(stash, buffer);
		if (!stash)
			return (free(buffer), NULL);
	}
	line = ft_get_line(stash);
	stash = ft_set_stash(stash);
	return (free(buffer), line);
}
