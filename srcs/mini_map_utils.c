/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 19:37:57 by fde-jesu          #+#    #+#             */
/*   Updated: 2025/05/14 20:18:03 by fde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/cub.h"

void	create_minimap(t_cub *cub)
{
	draw_map(cub);
	put_circle(cub, cub->px, cub->py, 0xFF);
	draw_fov(cub);
}

void	draw_map(t_cub *game)
{
	char	**map;
	int		color;
	int		x;
	int		y;

	x = -1;
	y = -1;
	map = game->map;
	color = 0x0000FF;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
			if (map[y][x] == '1')
				put_square(game, x * MINIMAP_SCALE, y * MINIMAP_SCALE,
					MINIMAP_SCALE);
	}
}

void	draw_fov(t_cub *cub)
{
	int		i;
	float	start_x;

	i = -1;
	start_x = cub->angle - PI / 6;
	while (++i < WIDTH)
	{
		if (i % 40 == 0)
			show_rays(cub, start_x);
		start_x += PI / 3 / WIDTH;
	}
}

void	put_circle(t_cub *cub, int x, int y, int color)
{
	double theta;

	theta = 0;
	while (theta <= 2 * PI)
	{
		x = cub->px + 20 * cos(theta);
		y = cub->py + 20 * sin(theta);
		put_pixel(cub, x / MINIMAP_SCALE, y / MINIMAP_SCALE, 0xFF);
		theta += 0.01;
	}
}