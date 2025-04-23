/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_rays.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 19:08:41 by fde-jesu          #+#    #+#             */
/*   Updated: 2025/04/23 19:13:42 by fde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/cub.h"
#include "../libs/mlx/mlx.h"

void	cast_rays(t_cub *cub)
{
	double	fraction;
	float	start_x;
	int		i;

	fraction = PI / 3 / WIDTH;
	start_x = cub->angle - PI / 6;
	cub->start_x = start_x;
	i = 0;
	while (i < WIDTH)
	{
		init_rays(cub, cub->rays, i);
		draw_line(cub, cub->rays, i);
		start_x += fraction;
		i++;
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
	ray_x = cub->px / 5;
	ray_y = cub->py / 5;
	while (!colision(ray_x, ray_y, cub, 1))
	{
		put_pixel(cub, ray_x, ray_y, 0xFFF);
		ray_x += cos_;
		ray_y += sin_;
	}
}
