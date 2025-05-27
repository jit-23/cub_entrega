/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_dist_wall.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 00:12:08 by fde-jesu          #+#    #+#             */
/*   Updated: 2025/05/27 18:07:10 by fde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	calc_text_wall_pixel(t_cub *cub, t_rays *rays, int texture)
{
	rays->xwall = fmod(rays->xwall, BLOCK_SCALE) / BLOCK_SCALE;
	rays->tex_x = (int)((rays->xwall) * ((double)cub->imgs[texture].x));
	if ((rays->side == 0 && rays->raydirx < 0))
		rays->tex_x = cub->imgs[texture].x - rays->tex_x - 1;
	if (rays->side == 1 && rays->raydiry > 0)
		rays->tex_x = cub->imgs[texture].x - rays->tex_x - 1;
	rays->y = rays->drawstart;
	rays->step = 1.0 * cub->imgs[texture].y / rays->lineheight;
	rays->texpos = (rays->drawstart - HEIGH / 2 + rays->lineheight / 2)
		* rays->step;
}

void	handle_texture_calcs(t_cub *cub, t_rays *rays)
{
	if (cub->texture2apply == NORTH_TEXTURE)
		calc_text_wall_pixel(cub, rays, NORTH_TEXTURE);
	else if (cub->texture2apply == SOUTH_TEXTURE)
		calc_text_wall_pixel(cub, rays, SOUTH_TEXTURE);
	else if (cub->texture2apply == EAST_TEXTURE)
		calc_text_wall_pixel(cub, rays, EAST_TEXTURE);
	else if (cub->texture2apply == WEST_TEXTURE)
		calc_text_wall_pixel(cub, rays, WEST_TEXTURE);
}

void	ft_calc_draw_limitations_for_walls(t_cub *cub, t_rays *rays)
{
	rays->lineheight = (BLOCK_SCALE * HEIGH) / rays->perpwalldist;
	printf("rays->perpwalldist = %f\n", rays->perpwalldist);
	printf("rays->lineheight = %f\n", rays->lineheight);
	rays->drawstart = -rays->lineheight / 2 + HEIGH / 2;
	if (rays->drawstart < 0)
		rays->drawstart = 0;
	rays->drawend = rays->lineheight / 2 + HEIGH / 2;
	if (rays->drawend >= HEIGH)
		rays->drawend = HEIGH - 1;
	if (rays->side == 0)
		rays->xwall = cub->info->y + rays->perpwalldist * rays->raydiry;
	else
		rays->xwall = cub->info->x + rays->perpwalldist * rays->raydirx;
}

// conserta as direcoes para aplicar textura nortes e sul e e w
void	ft_calc_dist_wall(t_cub *cub, t_rays *rays)
{
	//printf("rays->mapx -> %d\n", rays->mapx);
	//printf("- cub->info->x -> %f\n", - cub->info->x);
	//printf("rays->stepx) -> %d\n", rays->stepx);
//
	//printf("(1 - rays->stepx) -> %d\n", (1 - rays->stepx));
	//printf("------------------\n");
	//printf("rays->mapx - cub->info->x + (1 - rays->stepx) = %f\n", rays->mapx - cub->info->x + (1 - rays->stepx));
	//printf("primeira parte -> %f\n", (rays->mapx - cub->info->x + (1 - rays->stepx) / 2));
	//printf("segunda parte -> %f\n", rays->raydirx);
	if (rays->side == 0)
	{
		rays->perpwalldist = (rays->mapx - cub->info->x + (1 - rays->stepx) / 2) / rays->raydirx;

		if (rays->raydirx > 0)
			cub->texture2apply = WEST_TEXTURE;
		else
			cub->texture2apply = EAST_TEXTURE;
	}
	else
	{
		rays->perpwalldist = (rays->mapy - cub->info->y + (1 - rays->stepy) / 2)
			/ rays->raydiry;
		if (rays->raydiry > 0)
			cub->texture2apply = NORTH_TEXTURE;
		else
			cub->texture2apply = SOUTH_TEXTURE;
	}
	ft_calc_draw_limitations_for_walls(cub, rays);
	handle_texture_calcs(cub, rays);
}
