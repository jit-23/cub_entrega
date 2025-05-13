/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:58:41 by fde-jesu          #+#    #+#             */
/*   Updated: 2025/05/13 18:49:54 by fde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/cub.h"
#include "../libs/mlx/mlx.h"

void	draw_right_texture(t_cub *cub, t_rays *rays, int i, int texture)
{
	rays->texy = (int)rays->texpos;
	if (rays->texy < 0)
		rays->texy = 0;
	if (rays->texy >= cub->imgs[texture].y)
		rays->texy = cub->imgs[texture].y - 1;
	rays->color = *(int *)(cub->imgs[texture].addr + (rays->texy
				* cub->imgs[texture].size_line + rays->tex_x
				* (cub->imgs[texture].bpp / 8)));
	my_mlx_pixel_put(&cub->imgs[0], i, rays->y, rays->color);
	rays->texpos += rays->step;
	rays->y++;
}

void	draw_line(t_cub *cub, t_rays *rays, int i)
{
	int	column;

	column = -1;
	while (++column < rays->drawstart)
		my_mlx_pixel_put(&cub->imgs[0], i, column, 0xFFFF);
	column = rays->drawend;
	while (++column < HEIGH)
		my_mlx_pixel_put(&cub->imgs[0], i, column, 0x0F0F);
	while (rays->y < rays->drawend + 1)
	{
		if (cub->texture2apply == NORTH_TEXTURE)
			draw_right_texture(cub, rays, i, NORTH_TEXTURE);
		else if (cub->texture2apply == SOUTH_TEXTURE)
			draw_right_texture(cub, rays, i, SOUTH_TEXTURE);
		else if (cub->texture2apply == EAST_TEXTURE)
			draw_right_texture(cub, rays, i, EAST_TEXTURE);
		else if (cub->texture2apply == WEST_TEXTURE)
			draw_right_texture(cub, rays, i, WEST_TEXTURE);
	}
}
