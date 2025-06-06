/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 15:37:26 by mloureir          #+#    #+#             */
/*   Updated: 2025/06/04 03:34:42 by fde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include <unistd.h>

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
	{
		ft_putstr_fd("No map\n", STDERR_FILENO);
		return (1);
	}
	return (0);
}
