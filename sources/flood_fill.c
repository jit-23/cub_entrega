/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 09:20:35 by mloureir          #+#    #+#             */
/*   Updated: 2025/06/01 03:04:04 by fde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	get_big_x(t_map *map)
{
	t_counters	c;

	start_counters(&c);
	while (c.c <= map->map_y)
	{
		if ((int)ft_strlen(map->map[c.c]) > c.we)
			c.we = ft_strlen(map->map[c.c]);
		c.c++;
	}
	return (c.we);
}

void	get_ff_map(t_map *map)
{
	t_counters	c;

	start_counters(&c);
	c.c = get_big_x(map);
	map->map_ff = ft_calloc(map->map_y + 1, sizeof(char *));
	while (c.f < map->map_y)
	{
		c.ea = 0;
		map->map_ff[c.f] = ft_calloc(c.c + 1, sizeof(char));
		while (map->map[c.f][c.ea])
		{
			map->map_ff[c.f][c.ea] = map->map[c.f][c.ea];
			c.ea++;
		}
		while (c.ea < c.c)
		{
			map->map_ff[c.f][c.ea] = '#';
			c.ea++;
		}
		c.f++;
		map->map_ff_y++;
	}
}

int	verify_ff(t_map *map)
{
	get_ff_map(map);
	return (0);
}
