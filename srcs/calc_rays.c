/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 00:12:08 by fde-jesu          #+#    #+#             */
/*   Updated: 2025/05/14 20:17:43 by fde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/cub.h"

void	ft_calc_ray_side(t_cub *cub, t_rays *rays)
{
	if (rays->raydirx < 0)
	{
		// esquerda
		rays->stepx = -1; // valor para
		rays->sidedistx = (cub->px - rays->mapx) * rays->deltadistx;
	}
	else
	{
		rays->stepx = 1;
		rays->sidedistx = (rays->mapx + 1.0 - cub->px) * rays->deltadistx;
	}
	if (rays->raydiry < 0)
	{
		rays->stepy = -1; // baixo
		rays->sidedisty = (cub->py - rays->mapy) * rays->deltadisty;
	}
	else
	{
		rays->stepy = 1; // cima
		rays->sidedisty = (rays->mapy + 1.0 - cub->py) * rays->deltadisty;
	}
}

bool	colision(float px, float py, t_cub *cub, int flag)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (flag == 1) // para mini mapa
	{
		x = (px / MINIMAP_SCALE);
		y = (py / MINIMAP_SCALE);
		if (cub->map[y][x] == '1')
			return (true);
		return (false);
	}
	else
	{
		x = (px / BLOCK_SCALE);
		y = (py / BLOCK_SCALE);
		if (cub->map[y][x] == '1')
			return (true);
		return (false);
	}
}

// Move in the direction of the shortest step
void	ft_calc_dda(t_cub *cub, t_rays *rays)
{
	while (!colision(rays->mapx, rays->mapy, cub, 0))
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

void	init_rays(t_cub *cub, t_rays *rays, int i)
{
	rays->mapx = (int)cub->px;
	rays->mapy = (int)cub->py;
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
	ft_calc_dist_wall(cub, rays, i);
}