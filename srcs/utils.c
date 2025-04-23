/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 00:57:09 by fde-jesu          #+#    #+#             */
/*   Updated: 2025/04/23 17:34:29 by fde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/cub.h"
#include "../libs/mlx/mlx.h"

void put_square(t_cub *cub, int x, int y, int size, int color)
{
	
	for (int  i = 0; i < size; i++)
		put_pixel(cub, x + i , y, color);
	
	for (int  i = 0; i < size; i++)
		put_pixel(cub, x  , y + i, color);
	
	for (int  i = 0; i < size; i++)
		put_pixel(cub, x + i  , y + size, color);


	for (int  i = 0; i < size; i++)
		put_pixel(cub, x + size , y + i, color);

}

void put_pixel(t_cub *cub, int x, int y, int color)

{
	if(x >= WIDTH || y >= HEIGH || x < 0 || y < 0)

        return;
	int index = y * cub->size_line + x * cub->bpp / 8;

//	mlx_pixel_put(cub->mlx_con, cub->mlx_win, x, y, color);

	cub->imgs[0].addr[index] = color & 0xFF;
    cub->imgs[0].addr[index + 1] = (color >> 8) & 0xFF;

    cub->imgs[0].addr[index + 2] = (color >> 16) & 0xFF;


}


void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->size_line + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

void	refresh_frames(t_cub *cub)
{
	mlx_put_image_to_window(cub->mlx_con, cub->mlx_win, cub->imgs[0].img, 0, 0);
}
