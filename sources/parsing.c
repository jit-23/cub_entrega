/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 10:49:45 by mloureir          #+#    #+#             */
/*   Updated: 2025/05/27 18:31:48 by fde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	get_color(t_colors *colors, char *map_dir)
{
	int		fd;
	char	*buffer;

	fd = open(map_dir, O_RDONLY);
	buffer = get_next_line(fd);
	while (buffer)
	{
		find_color(buffer, colors);
		free(buffer);
		buffer = get_next_line(fd);
	}
	close(fd);
	free(buffer);
	if (seperate_colors(colors) != 0)
		return (1);
	return (0);
}

//static int	flood_fill_check(t_map *info, int x, int y)
//{
//	static int	flag;
//	
//	if (!info->map_ff[y][x])
//	{
//		flag++;
//		return (1);
//	}
//	if (info->map_ff[y][x] == '1' || info->map_ff[y][x] == '#')
//		return (1);
//	info->map_ff[y][x] = '1';
//	flood_fill_check(info, x + 1, y);
//	flood_fill_check(info, x - 1, y);
//	flood_fill_check(info, x, y + 1);
//	flood_fill_check(info, x, y - 1);
//	if (flag != 0)
//		return (1);
//	return (0);
//}

int	parser(t_map *map, char *map_dir)
{
	if (check_errs(map_dir) != 0)
		return (1);
	if (get_texture(map->texture, map_dir) != 0)
		return (1);
	if (get_color(map->color, map_dir) != 0)
		return (1);
	if (get_map(map, map_dir) != 0)
		return (1);
	if (copy_map(map, map_dir) != 0)
		return (1);
	if (verify_values(map) != 0)
		return (1);
	return (0);
}
