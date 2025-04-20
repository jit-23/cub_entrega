/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 00:57:09 by fde-jesu          #+#    #+#             */
/*   Updated: 2025/04/20 00:57:38 by fde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/cub.h"
#include "../libs/mlx/mlx.h"

void my_mlx_pixel_put(t_img *img, int x, int y, int color) // img = cub->imgs[1] // [1] e o que corresponde ao ecra
{
	char *dst = img->addr + (y * img->size_line + x * (img->bpp / 8));
	*(unsigned int*)dst = color;
}



void refresh_frames(t_cub *cub)
{
	mlx_put_image_to_window(cub->mlx_con, cub->mlx_win, cub->imgs[1].img, 0, 0);
}