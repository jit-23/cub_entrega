/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_rays.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 19:08:41 by fde-jesu          #+#    #+#             */
/*   Updated: 2025/06/03 17:14:54 by fde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ray_casting(t_cub *cub)
{
	int		i;

	i = -1;
	while (++i < WIDTH)
	{
		init_rays(cub, cub->rays, i);
		draw_line(cub, cub->rays, i);
	}
}

void	show_rays(t_cub *cub, float start_x)
{
	float	cos_;
	float	sin_;
	float	ray_x;
	float	ray_y;

	cos_ = cos(start_x);
	sin_ = sin(start_x);
	ray_x = cub->info->x / MINIMAP_SCALE;
	ray_y = cub->info->y / MINIMAP_SCALE;
	while (!colision(ray_x, ray_y, cub, MINIMAP_SCALE))
	{
		put_pixel(cub, ray_x, ray_y, 0xFFF);
		ray_x += cos_;
		ray_y += sin_;
	}
}
