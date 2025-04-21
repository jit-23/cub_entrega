/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 00:12:08 by fde-jesu          #+#    #+#             */
/*   Updated: 2025/04/21 19:44:38 by fde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/cub.h"
#include "../libs/mlx/mlx.h"


void draw_line(t_cub *cub, t_rays *rays, int i)
{
	int	column;

	column = -1;
	// ceiling
	while(++column < rays->drawStart)
		my_mlx_pixel_put(&cub->imgs[1], i, column, 0xFFFF);
	// floor
	column = rays->drawEnd;
	while(++column < HEIGH)
		my_mlx_pixel_put(&cub->imgs[1], i, column, 0x0F0F);
	// walls
	while (rays->y < rays->drawEnd) 
	{
		rays->texY = (int)rays->texPos;
		if (rays->texY < 0)
    	    rays->texY = 0;
		if (rays->texY >= cub->imgs[0].y) 
    	    rays->texY = cub->imgs[0].y - 1;
	
		rays->color = *(int *)(cub->imgs[0].addr +
    	            (rays->texY * cub->imgs[0].size_line + rays->texX * (cub->imgs[0].bpp / 8)));
		my_mlx_pixel_put(&cub->imgs[1], i, rays->y, rays->color);
		rays->texPos += rays->step;
		rays->y++;
	}
}

void ft_calc_ray_side(t_cub *cub, t_rays **ray)
{
	t_rays *rays;

	rays = (*ray);
	if (rays->rayDirX < 0) 
    { //esquerda
	    rays->stepX = -1; // valor para 
	    rays->sideDistX = (cub->px - rays->mapX) * rays->deltaDistX;
    }
    else
    {
	    rays->stepX = 1;
	    rays->sideDistX = (rays->mapX + 1.0 - cub->px) * rays->deltaDistX;
    }

    if (rays->rayDirY < 0)
    {
    	rays->stepY = -1; // baixo
		rays->sideDistY = (cub->py - rays->mapY) * rays->deltaDistY;
	} 
    else
    {
		rays->stepY = 1; // cima
	    rays->sideDistY = (rays->mapY + 1.0 - cub->py) * rays->deltaDistY;
	}
}

bool	colision(float px, float py, t_cub *cub)
{
	int	x;
	int	y;

	x = (px / BLOCK);
	y = (py / BLOCK);
	if (cub->map[y][x] == '1')
		return true;
	return (false);
}

void	ft_calc_dda(t_cub *cub, t_rays **ray)
{
	t_rays	*rays;

	rays = (*ray);
	rays->hit = 0;
	while (rays->hit == 0) // Move in the direction of the shortest step 
	{
		if (rays->sideDistX < rays->sideDistY)
		{
			rays->sideDistX += rays->deltaDistX;
			rays->mapX += rays->stepX;
			rays->side = 0;
		}
		else
		{
			rays->sideDistY += rays->deltaDistY;
			rays->mapY += rays->stepY;
			rays->side = 1;
		}
		if (colision(rays->mapX, rays->mapY, cub)) // Check for a collision (wall hit)
			rays->hit = 1;
	}
}

void	init_rays( t_cub *cub, t_rays *rays, int i)
{
	rays->mapX = (int)cub->px;
	rays->mapY = (int)cub->py;
	rays->fov = PI / 3;
	rays->planeLength = tan(rays->fov / 2);
	rays->dirX = cos(cub->angle);
	rays->dirY = sin(cub->angle);
	rays->planeX = -rays->dirY * rays->planeLength;
	rays->planeY = rays->dirX * rays->planeLength;
	rays->cameraX = 2 * i / (double)WIDTH - 1;
	rays->rayDirX = rays->dirX + rays->planeX * rays->cameraX;
	rays->rayDirY = rays->dirY + rays->planeY * rays->cameraX;
	rays->deltaDistX = sqrt(1 + (rays->rayDirY * rays->rayDirY) \
		/ (rays->rayDirX * rays->rayDirX));
	rays->deltaDistY = sqrt(1 + (rays->rayDirX * rays->rayDirX) \
		/ (rays->rayDirY * rays->rayDirY));
	ft_calc_ray_side(cub, &rays);
	ft_calc_dda(cub, &rays);
	ft_calc_dist_wall(cub, &rays, i);
}
