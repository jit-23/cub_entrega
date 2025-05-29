/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 10:49:45 by mloureir          #+#    #+#             */
/*   Updated: 2025/05/29 17:03:45 by fde-jesu         ###   ########.fr       */
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

/* static int	flood_fill_check(t_map *info, int x, int y)
{
	static int	flag;
	
	if (!info->map_ff[y][x])
	{
		flag++;
		return (1);
	}
	if (!info->map_ff[y][x] && (info->map_ff[y][x] == '1' || info->map_ff[y][x] == '#'))
		return (1);
	info->map_ff[y][x] = '1';
	flood_fill_check(info, x + 1, y);
	flood_fill_check(info, x - 1, y);
	flood_fill_check(info, x, y + 1);
	flood_fill_check(info, x, y - 1);
	if (flag != 0)
		return (1);
	return (0);
} */
static int	flood_fill_check(t_map *info, int x, int y, int flag)
{
	static int _flag;
	
	if (x < 0 || y < 0 || y >= info->map_ff_y || x >= WIDTH/25)
	{
		_flag++;
		return (1); // Out of bounds
	}
	if (!info->map_ff[y][x] || info->map_ff[y][x] == '#')
	{
		_flag++;
		return (1);
	}
	if ( info->map_ff[y][x] == '1')
		return (1); // Wall or already visited
	info->map_ff[y][x] = '1'; // Mark cell as visited
	// Recursive flood fill
	flood_fill_check(info, x + 1, y, 1);
	
	flood_fill_check(info, x - 1, y,2 );
	flood_fill_check(info, x, y + 1,3);
	flood_fill_check(info, x, y - 1,4 );
	if(_flag != 0)
		return (1);
	return (0); // You can adjust this depending on your needs
}

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
	//printf("map_yy -> %d\n", map->map_ff_y);
	//for (int i = 0; map->map_ff[i]; i++)
	//{
	//	for (int h = 0; map->map_ff[i][h]; h++)
	//	{
	//		printf("%c", map->map_ff[i][h]);
	//	}
	//	
	//	printf("\n");
	//}
	//
	if (flood_fill_check(map, ((int)(map->x- BLOCK_SCALE/2)/BLOCK_SCALE) ,((int)(map->y- BLOCK_SCALE/2)/BLOCK_SCALE), 0) != 0)
		return (1);
	return (0);
}
