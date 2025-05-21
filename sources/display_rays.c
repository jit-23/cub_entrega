/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_rays.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 19:08:41 by fde-jesu          #+#    #+#             */
/*   Updated: 2025/05/20 15:32:53 by mloureir         ###   ########.pt       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ray_casting(t_cub *cub)
{
	double	fraction;
	float	start_x;
	int		i;

	fraction = PI / 3 / WIDTH;
	start_x = cub->angle - PI / 6;
	i = -1;
	while (++i < WIDTH)
	{
		init_rays(cub, cub->rays, i);
		draw_line(cub, cub->rays, i);
		start_x += fraction;
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
	ray_x = cub->px / MINIMAP_SCALE;
	ray_y = cub->py / MINIMAP_SCALE;
	while (!colision(ray_x, ray_y, cub, 1))
	{
		put_pixel(cub, ray_x, ray_y, 0xFFF);
		ray_x += cos_;
		ray_y += sin_;
	}
}
