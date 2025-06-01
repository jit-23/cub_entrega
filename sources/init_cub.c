/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 00:10:02 by fde-jesu          #+#    #+#             */
/*   Updated: 2025/06/01 03:02:31 by fde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_keys(t_cub *cub)
{
	cub->k_up = false;
	cub->k_down = false;
	cub->k_left = false;
	cub->k_right = false;
	cub->k_plus = false;
	cub->k_less = false;
	cub->left_r = false;
	cub->right_r = false;
}

int	verify_img(t_cub *cub)
{
	int	i;

	i = 1;
	while (i <= 4)
	{
		if (!cub->imgs[i].img)
			return (1);
		i++;
	}
	return (0);
}

int	init_textures(t_cub *cub)
{
	cub->imgs[0].img = mlx_new_image(cub->mlx_con, WIDTH, HEIGH);
	cub->imgs[0].addr = mlx_get_data_addr(cub->imgs[0].img, &cub->imgs[0].bpp,
			&cub->imgs[0].size_line, &cub->imgs[0].endian);
	cub->imgs[1].img = mlx_xpm_file_to_image(cub->mlx_con,
			cub->info->texture[0].path, &(cub->imgs[1].x), &(cub->imgs[1].y));
	cub->imgs[2].img = mlx_xpm_file_to_image(cub->mlx_con,
			cub->info->texture[3].path, &(cub->imgs[2].x), &(cub->imgs[2].y));
	cub->imgs[3].img = mlx_xpm_file_to_image(cub->mlx_con,
			cub->info->texture[1].path, &(cub->imgs[3].x), &(cub->imgs[3].y));
	cub->imgs[4].img = mlx_xpm_file_to_image(cub->mlx_con,
			cub->info->texture[2].path, &(cub->imgs[4].x), &(cub->imgs[4].y));
	if (verify_img(cub) != 0)
		return (1);
	cub->imgs[1].addr = mlx_get_data_addr(cub->imgs[1].img, &cub->imgs[1].bpp,
			&cub->imgs[1].size_line, &cub->imgs[1].endian);
	cub->imgs[2].addr = mlx_get_data_addr(cub->imgs[2].img, &cub->imgs[2].bpp,
			&cub->imgs[2].size_line, &cub->imgs[2].endian);
	cub->imgs[3].addr = mlx_get_data_addr(cub->imgs[3].img, &cub->imgs[3].bpp,
			&cub->imgs[3].size_line, &cub->imgs[3].endian);
	cub->imgs[4].addr = mlx_get_data_addr(cub->imgs[4].img, &cub->imgs[4].bpp,
			&cub->imgs[4].size_line, &cub->imgs[4].endian);
	return (0);
}

void	set_player_atributes(t_cub *cub)
{
	cub->angle = cub->info->player_initial_dir;
	cub->speed = 0.5;
}

void	init_cub(t_cub *cub)
{
	set_null(cub);
	init_keys(cub);
	cub->rays = (t_rays *)malloc(sizeof(t_rays));
	set_rays_null(cub->rays);
	set_player_atributes(cub);
	start_cub(cub);
}
