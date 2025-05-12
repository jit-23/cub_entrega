/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 00:10:02 by fde-jesu          #+#    #+#             */
/*   Updated: 2025/05/12 18:50:07 by fde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/cub.h"
#include "../libs/mlx/mlx.h"

void	exit_msg(t_cub *cub, char *str)
{
	ft_putstr_fd(2, str);
	exit(1);
}

void	close_window(void)
{
	exit(0);
}

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

char	**get_map(void)
{
	char	**map;

	map = malloc(sizeof(char *) * 22);
	map[0] = "111111111111111111111111111111";
	map[1] = "110100000000000000000000000001";
	map[2] = "100000000000000000000000000001";
	map[3] = "110000000000000000000000000001";
	map[4] = "100000000001111110000000000001";
	map[5] = "100000000001000000000000000001";
	map[6] = "100000000001010000000000000001";
	map[7] = "100000000001000000000000000001";
	map[8] = "100000000001000000000000000001";
	map[9] = "100000000000000000000000000001";
	map[10] = "100000000000000000000000000001";
	map[11] = "100000000000000000000000000001";
	map[12] = "100000000000000000000000000001";
	map[13] = "100000000000000000000000000001";
	map[14] = "100000000000000000000000000001";
	map[15] = "100000000000000000000000000001";
	map[16] = "100000000000000000000000000001";
	map[17] = "111111111111111111111111111111";
	map[18] = NULL;
	return (map);
}

void	init_textures(t_cub *cub)
{
	cub->imgs[0].img = mlx_new_image(cub->mlx_con, WIDTH, HEIGH);
	cub->imgs[0].addr = mlx_get_data_addr(cub->imgs[0].img, &cub->imgs[0].bpp,
			&cub->imgs[0].size_line, &cub->imgs[0].endian);
	cub->imgs[1].img = mlx_xpm_file_to_image(cub->mlx_con, "textures/NORTH.xpm",
			&(cub->imgs[1].x), &(cub->imgs[1].y));
	cub->imgs[1].addr = mlx_get_data_addr(cub->imgs[1].img, &cub->imgs[1].bpp,
			&cub->imgs[1].size_line, &cub->imgs[1].endian);
	cub->imgs[2].img = mlx_xpm_file_to_image(cub->mlx_con, "textures/SOUTH.xpm",
			&(cub->imgs[2].x), &(cub->imgs[2].y));
	cub->imgs[2].addr = mlx_get_data_addr(cub->imgs[2].img, &cub->imgs[2].bpp,
			&cub->imgs[2].size_line, &cub->imgs[2].endian);
	cub->imgs[3].img = mlx_xpm_file_to_image(cub->mlx_con, "textures/EAST.xpm",
			&(cub->imgs[3].x), &(cub->imgs[3].y));
	cub->imgs[3].addr = mlx_get_data_addr(cub->imgs[3].img, &cub->imgs[3].bpp,
			&cub->imgs[3].size_line, &cub->imgs[3].endian);
	cub->imgs[4].img = mlx_xpm_file_to_image(cub->mlx_con, "textures/WEST.xpm",
			&(cub->imgs[4].x), &(cub->imgs[4].y));
	cub->imgs[4].addr = mlx_get_data_addr(cub->imgs[4].img, &cub->imgs[4].bpp,
			&cub->imgs[4].size_line, &cub->imgs[4].endian);
}
