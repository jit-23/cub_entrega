/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_values_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloureir <mloureir@42porto.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 13:59:21 by mloureir          #+#    #+#             */
/*   Updated: 2025/04/30 15:13:57 by mloureir         ###   ########.pt       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_for_textures(char *buffer)
{
	int	i;

	i = 2;
	while (buffer[i] == 32 || ((buffer[i] >= 9 && buffer[i] <= 13)))
		i++;
	if (buffer[i] == '\0' || buffer[i] == '\n')
		return (1);
	return (0);
}

int	check_for_colors(char *buffer)
{
	int	i;

	i = 1;
	while (buffer[i] == 32 || ((buffer[i] >= 9 && buffer[i] <= 13)))
		i++;
	if (buffer[i] == '\0' || buffer[i] == '\n')
		return (1);
	return (0);
}

int	v_checker(char *buffer)
{
	if (is_a_param(buffer) == 3)
	{
		if (check_for_textures(buffer) != 0)
			return (1);
	}
	else if (is_a_param(buffer) == 2)
	{
		if (check_for_colors(buffer) != 0)
			return (1);
	}
	return (0);
}

int	check_values(char *map_dir)
{
	int		fd;
	char	*buffer;

	fd = open(map_dir, O_RDONLY);
	buffer = get_next_line(fd);
	while (buffer)
	{
		if (v_checker(buffer) != 0)
		{
			close(fd);
			free(buffer);
			return (1);
		}
		free(buffer);
		buffer = get_next_line(fd);
	}
	close(fd);
	return (0);
}
