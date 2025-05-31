/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 10:37:34 by mloureir          #+#    #+#             */
/*   Updated: 2025/05/31 15:31:17 by fde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	verify_colors(t_colors *colors)
{
	int	i;

	i = 0;
	while (i < COLOR)
	{
		if (colors[i].red > 255)
			return (1);
		if (colors[i].blue > 255)
			return (1);
		if (colors[i].green > 255)
			return (1);
		i++;
	}
	return (0);
}

int	verify_paths(t_textures *texture)
{
	int	i;

	i = 0;
	while (i < MAX_TEXTURE)
	{
		if (open(texture[i].path, O_RDONLY) == -1)
		{
			printf("%s has no texture\n", texture[i].identifier);
			return (1);
		}
		if (check_xpm(texture[i].path) != 0)
		{
			printf("%s texture is in the wrong format", texture[i].identifier);
			return (1);
		}
		i++;
	}
	return (0);
}

static void	init_player_pos(t_map *map, int x, int y, char player_chard)
{
	if (player_chard == 'N')
		map->player_initial_dir = -PI / 2;
	else if (player_chard == 'S')
		map->player_initial_dir = PI / 2;
	else if (player_chard == 'E')
		map->player_initial_dir = -PI;
	else if (player_chard == 'W')
		map->player_initial_dir = 0;
	map->x = x * BLOCK_SCALE + (BLOCK_SCALE / 2);
	map->y = y * BLOCK_SCALE + (BLOCK_SCALE / 2);
	return ;
}

int	verify_map(t_map *map)
{
	t_counters	c;
	int			d;

	start_counters(&c);
	while (c.f <= map->map_y)
	{
		c.c = 0;
		while (c.c < (int)ft_strlen(map->map[c.f]))
		{
			if (is_player(map->map[c.f][c.c]))
				init_player_pos(map, c.c, c.f, map->map[c.f][c.c]);
			d = map->map[c.f][c.c];
			if (map_chars(d) == 3)
				c.ea++;
			else if (map_chars(d) == 1)
				return (1);
			c.c++;
		}
		c.f++;
	}
	if (c.ea != 1)
		return (1);
	return (0);
}

int	verify_values(t_map *map)
{
	if (verify_colors(map->color) != 0)
		return (1);
	if (verify_paths(map->texture) != 0)
		return (1);
	change_spaces(map);
	if (verify_map(map) != 0)
		return (1);
	if (verify_ff(map) != 0)
		return (1);
	return (0);
}
