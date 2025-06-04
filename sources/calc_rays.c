/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 00:12:08 by fde-jesu          #+#    #+#             */
/*   Updated: 2025/06/04 03:22:40 by fde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/* esquerda ; direita; baixo; cima */
void	init_rays(t_cub *cub, t_rays *rays, int i)
{
	rays->mapx = (int)cub->info->x;
	rays->mapy = (int)cub->info->y;
	rays->dirx = cos(cub->angle);
	rays->diry = sin(cub->angle);
	rays->raydirx = rays->dirx + ((-rays->diry * tan((PI / 6))) * ((i << 1)
				/ (double)WIDTH - 1));
	rays->raydiry = rays->diry + ((rays->dirx * tan((PI / 6))) * ((i << 1)
				/ (double)WIDTH - 1));
	rays->deltadistx = sqrt(1 + (rays->raydiry * rays->raydiry)
			/ (pow(rays->raydirx, 2)));
	rays->deltadisty = sqrt(1 + (rays->raydirx * rays->raydirx)
			/ (pow(rays->raydiry, 2)));
	ft_calc_ray_side(cub, rays);
	ft_calc_dda(cub, rays);
	ft_calc_dist_wall(cub, rays);
}

void	ft_calc_ray_side(t_cub *cub, t_rays *rays)
{
	if (rays->raydirx < 0)
	{
		rays->stepx = -1;
		rays->sidedistx = (cub->info->x - rays->mapx) * rays->deltadistx;
	}
	else
	{
		rays->stepx = 1;
		rays->sidedistx = (rays->mapx + 1.0 - cub->info->x) * rays->deltadistx;
	}
	if (rays->raydiry < 0)
	{
		rays->stepy = -1;
		rays->sidedisty = (cub->info->y - rays->mapy) * rays->deltadisty;
	}
	else
	{
		rays->stepy = 1;
		rays->sidedisty = (rays->mapy + 1.0 - cub->info->y) * rays->deltadisty;
	}
}

// Move in the direction of the shortest step
void	ft_calc_dda(t_cub *cub, t_rays *rays)
{
	while (!colision(rays->mapx, rays->mapy, cub, BLOCK_SCALE))
	{
		if (rays->sidedistx < rays->sidedisty)
		{
			rays->sidedistx += rays->deltadistx;
			rays->mapx += rays->stepx;
			rays->side = 0;
		}
		else
		{
			rays->sidedisty += rays->deltadisty;
			rays->mapy += rays->stepy;
			rays->side = 1;
		}
	}
}

bool	colision(float px, float py, t_cub *cub, int scale)
{
	int	x;
	int	y;

	x = ((float)px / scale);
	y = ((float)py / scale);
	if (x < 0 || y < 0)
		return (true);
	if (cub->info->map[y][x] == '1')
		return (true);
	return (false);
}
