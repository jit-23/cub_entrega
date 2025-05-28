/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 00:12:08 by fde-jesu          #+#    #+#             */
/*   Updated: 2025/05/28 11:24:52 by fde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/* esquerda ; direita; baixo; cima */
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

bool	colision(float px, float py, t_cub *cub, int flag)
{
	int	x;
	int	y;

	x = (px / flag);
	y = (py / flag);
	ft_putnbr_fd(x, 1);
	ft_putnbr_fd(y, 1);
	if (x < 0 || y < 0 || x > WIDTH || y > HEIGH)
		return (true);
		if (cub->info->map[y][x] == '1')
			return (true);
		return (false);
}

// Move in the direction of the shortest step
void	ft_calc_dda(t_cub *cub, t_rays *rays)
{

	// printf("rays->mapx = %d\n", rays->mapx);
// 	printf("cub->info->x = %f\n", cub->info->x);
	// printf("rays->mapy = %d\n", rays->mapy);
	// printf("cub->info->y = %f\n", cub->info->y);
	while (!colision(rays->mapx, rays->mapy, cub, BLOCK_SCALE))
	{
		// printf("00\n");
		if (rays->sidedistx < rays->sidedisty)
		{
			// printf("--->  1\n");
			rays->sidedistx += rays->deltadistx;
			rays->mapx += rays->stepx;
			rays->side = 0;
		}
		else
		{
			// printf("---> 2\n");
			
			rays->sidedisty += rays->deltadisty;
			rays->mapy += rays->stepy;
			rays->side = 1;
		}
	}
}

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
