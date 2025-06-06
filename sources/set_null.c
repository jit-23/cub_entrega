/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_null.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 14:31:27 by fde-jesu          #+#    #+#             */
/*   Updated: 2025/05/31 10:39:44 by mloureir         ###   ########.pt       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	set_null_window_vars(t_cub *cub)
{
	cub->mlx_con = NULL;
	cub->mlx_win = NULL;
	cub->map_x = 0;
	cub->map_y = 0;
}

void	set_null_key_vars(t_cub *cub)
{
	cub->k_plus = false;
	cub->k_less = false;
	cub->k_left = false;
	cub->k_right = false;
	cub->k_up = false;
	cub->k_down = false;
	cub->right_r = false;
	cub->left_r = false;
}

void	set_null_player_vars(t_cub *cub)
{
	cub->map = NULL;
	cub->angle = 0;
	cub->speed = 0;
	cub->texture2apply = 0;
}

void	set_null_texture_vars(t_cub *cub, int i)
{
	cub->imgs[i].img = 0;
	cub->imgs[i].addr = NULL;
	cub->imgs[i].y = 0;
	cub->imgs[i].x = 0;
	cub->imgs[i].bpp = 0;
	cub->imgs[i].size_line = 0;
	cub->imgs[i].endian = 0;
}

void	set_null(t_cub *cub)
{
	int	i;

	i = -1;
	set_null_window_vars(cub);
	set_null_player_vars(cub);
	set_null_key_vars(cub);
	while (++i < 2)
		set_null_texture_vars(cub, i);
	cub->rays = NULL;
}
