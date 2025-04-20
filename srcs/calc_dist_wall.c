/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_dist_wall.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 00:12:08 by fde-jesu          #+#    #+#             */
/*   Updated: 2025/04/20 01:10:52 by fde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/cub.h"
#include "../libs/mlx/mlx.h"

void calc_text_wall_pixel(t_cub *cub, t_rays **ray)
{
    t_rays *rays;

    rays = (*ray);
    rays->xwall = fmod(rays->xwall, BLOCK)/BLOCK ;
    rays->texX =  (int) ((rays->xwall) * ((double)cub->imgs[0].x));
    if ((rays->side == 0 && rays->rayDirX < 0))
        rays->texX = cub->imgs[0].x - rays->texX - 1;
    if (rays->side == 1 && rays->rayDirY > 0)
        rays->texX = cub->imgs[0].x - rays->texX - 1;
    rays->y = rays->drawStart;
    rays->step = 1.0 * cub->imgs[0].y /rays->lineHeight ;//BLOCK;
    rays->texPos = (rays->drawStart - HEIGH / 2 + rays->lineHeight / 2) * rays->step;
}


void ft_calc_dist_wall(t_cub *cub, t_rays **ray, int i)
{
	t_rays *rays;

    rays = (*ray);
	if (rays->side == 0)
   		rays->perpWallDist = (rays->mapX - cub->px + (1 - rays->stepX) / 2) / rays->rayDirX;
	else
    	rays->perpWallDist = (rays->mapY - cub->py + (1 - rays->stepY) / 2) / rays->rayDirY;
    rays->lineHeight = (BLOCK * HEIGH ) / rays->perpWallDist ;
    rays->drawStart = -rays->lineHeight / 2 + HEIGH / 2;
    if (rays->drawStart < 0) 
	    rays->drawStart = 0;
    rays->drawEnd = rays->lineHeight / 2 + HEIGH / 2;
    if (rays->drawEnd >= HEIGH)
	    rays->drawEnd = HEIGH - 1;
    if (rays->side == 0)
        rays->xwall = cub->py + rays->perpWallDist * rays->rayDirY;
    else
        rays->xwall = cub->px + rays->perpWallDist * rays->rayDirX;
    calc_text_wall_pixel(cub, &rays);
}
