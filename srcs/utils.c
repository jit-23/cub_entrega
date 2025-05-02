/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 00:57:09 by fde-jesu          #+#    #+#             */
/*   Updated: 2025/05/02 19:17:51 by fde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/cub.h"
#include "../libs/mlx/mlx.h"


static void put_square_yline(t_cub *cub, int x, int y,int  color)
{
	int	i;

	i = -1;
	while(++i < 5)
		put_pixel(cub, x + i, y, color);
}

static void put_square_xline(t_cub *cub, int x, int y,int  color)
{
	int	i;

	i = -1;
	while(++i < 5)
		put_pixel(cub, x, y + i, color);
}

void	put_square(t_cub *cub, int x, int y, int color)
{
	put_square_xline(cub, x , y, color);
	put_square_xline(cub, x + 5, y, color);
	put_square_yline(cub, x, y , color);
	put_square_yline(cub, x, y + 5, color);
}

void	put_circle(t_cub *cub, int x, int y, int color)
{

	double	theta;

	theta = 0;
    while (theta <= 2 * PI)
    {
        x = cub->px + 20 * cos(theta);
        y = cub->py + 20 * sin(theta);
		put_pixel(cub, x / MINIMAP_SCALE, y / MINIMAP_SCALE, 0xFF);
		theta += 0.01;
	}
}

void	put_pixel(t_cub *cub, int x, int y, int color)

{
	int	index;

	index = 0;
	if (x >= WIDTH || y >= HEIGH || x < 0 || y < 0)
		return ;
	index = y * cub->size_line + x * cub->bpp / 8;
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
