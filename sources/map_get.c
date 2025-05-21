/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloureir <mloureir@42porto.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 15:37:26 by mloureir          #+#    #+#             */
/*   Updated: 2025/05/16 14:45:40 by mloureir         ###   ########.pt       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	gnl_finish(int fd, char *buffer)
{
	while (buffer)
	{
		free(buffer);
		buffer = get_next_line(fd);
	}
}

int	count_map(int fd)
{
	char	*buffer;
	int		i;

	i = 0;
	buffer = get_next_line(fd);
	while (buffer)
	{
		if (is_line_empty(buffer) == 0)
			break ;
		free(buffer);
		buffer = get_next_line(fd);
	}
	while (buffer)
	{
		if (is_line_empty(buffer) == 1)
			break ;
		i++;
		free(buffer);
		buffer = get_next_line(fd);
	}
	gnl_finish(fd, buffer);
	return (i);
}

int	get_map(t_map *map, char *map_dir)
{
	int		fd;
	char	*buffer;
	int		i;

	i = 0;
	fd = open(map_dir, O_RDONLY);
	buffer = get_next_line(fd);
	while (buffer)
	{
		if (is_a_param(buffer) != 1)
			i++;
		free(buffer);
		if (i == 6)
			break ;
		buffer = get_next_line(fd);
	}
	map->map_y = count_map(fd);
	close(fd);
	if (map->map_y <= 0)
		return (1);
	return (0);
}
