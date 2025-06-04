/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 04:46:31 by fde-jesu          #+#    #+#             */
/*   Updated: 2025/06/04 14:10:14 by mloureir         ###   ########.pt       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	start_vars(t_map *info)
{
	int	i;

	i = 0;
	info->map_y = 0;
	info->map_ff_y = 0;
	info->x = 0;
	info->y = 0;
	while (i < MAX_TEXTURE)
	{
		info->texture[i].identifier = NULL;
		info->texture[i].count = 0;
		info->texture[i].path = NULL;
		i++;
	}
	i = 0;
	while (i < COLOR)
	{
		info->color[i].path = NULL;
		info->color[i].allocd = 0;
		i++;
	}
}

void	set_rays_null2(t_rays *ray)
{
	ray->mapx = 0;
	ray->mapy = 0;
	ray->stepx = 0;
	ray->stepy = 0;
	ray->side = 0;
	ray->drawstart = 0;
	ray->drawend = 0;
	ray->tex_x = 0;
	ray->y = 0;
	ray->texy = 0;
	ray->color = 0;
}

void	set_rays_null(t_rays *ray)
{
	ray->fov = 0;
	ray->planelength = 0;
	ray->xwall = 0;
	ray->dirx = 0;
	ray->diry = 0;
	ray->planex = 0;
	ray->planey = 0;
	ray->camerax = 0;
	ray->raydirx = 0;
	ray->raydiry = 0;
	ray->deltadistx = 0;
	ray->deltadisty = 0;
	ray->sidedistx = 0;
	ray->sidedisty = 0;
	ray->perpwalldist = 0;
	ray->lineheight = 0;
	ray->step = 0;
	ray->texpos = 0;
	set_rays_null2(ray);
}
