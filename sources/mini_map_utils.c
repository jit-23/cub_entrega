/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 03:52:19 by fde-jesu          #+#    #+#             */
/*   Updated: 2025/05/21 19:11:58 by fde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	create_minimap(t_cub *cub)
{
	draw_map(cub);
	put_circle(cub, cub->px, cub->py, 0xFF);
	draw_fov(cub);
}

void	draw_map(t_cub *game)
{
	(void)game;
/* 	char	**map;
	int		x;
	int		y;

	x = -1;
	y = -1;
	map = game->map;
	printf("game->info->map_y - %d\n", game->info->map_y);
	while (++y < game->info->map_y)
	{// map[++y] 
		x = -1;
		while (map[y][++x])
		{
			printf("asd\n");
			if (map[y][x] == '1')
				put_square(game, x * MINIMAP_SCALE, y * MINIMAP_SCALE, MINIMAP_SCALE);
				
		}
	} */
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
		put_pixel(cub, x / MINIMAP_SCALE, y / MINIMAP_SCALE, color);
		theta += 0.01;
	}
}
