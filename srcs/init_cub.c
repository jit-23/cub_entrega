/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 00:10:02 by fde-jesu          #+#    #+#             */
/*   Updated: 2025/04/20 00:19:03 by fde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/cub.h"
#include "../libs/mlx/mlx.h"

void exit_msg(t_cub *cub, char *str)
{
	ft_putstr_fd(2, str);
	exit(1);
}


void close_window(void)
{
	exit(0);
}

void set_null_window_vars(t_cub *cub)
{
	cub->img_address = NULL;
	cub->bpp = 0;
	cub->size_line = 0;
	cub->endian = 0;
	cub->mlx_con = NULL;
	cub->mlx_win = NULL;
	cub->img = NULL;
	cub->map_x = 0;
	cub->map_y = 0;
}

void set_null_key_vars(t_cub *cub)
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

void set_null_player_vars(t_cub *cub)
{
	cub->fov = 0;
	cub->pos = 0;
	cub->map = NULL;
	cub->dist = 0;
	cub->cos = 0;
	cub->sin = 0;
	cub->px = 0;
	cub->py = 0;
	cub->angle = 0;
	cub->speed = 0;	
	cub->direction = 0;
}

void set_null_texture_vars(t_cub *cub, int i)
{
	cub->imgs[i].img = 0;
	cub->imgs[i].addr = NULL;
	cub->imgs[i].x = 0;
	cub->imgs[i].y = 0;
	cub->imgs[i].bpp = 0;
	cub->imgs[i].size_line = 0;
	cub->imgs[i].endian = 0;
}

void set_null(t_cub *cub)
{
	int i;

	i = -1;
	set_null_window_vars(cub);	
	set_null_player_vars(cub);	
	set_null_key_vars(cub);
	while(++i < 2)
		set_null_texture_vars(cub, i);	
	cub->rays = NULL;
}

void init_keys(t_cub *cub)
{
    cub->k_up = false;
    cub->k_down = false;
    cub->k_left = false;
    cub->k_right = false;
	cub->k_plus = false;
	cub->k_less = false;
	cub->left_r = false;
	cub->right_r = false;
	
    cub->angle  = NORTH;
	cub->speed = 0.2;
    cub->sin = 1;
	cub->cos = 0;
}

char **get_map(void)
{
    char **map = malloc(sizeof(char *) * 22);
    map[0] = "111111111111111111111111111111";
    map[1] = "100000000000000000000000000011";
    map[2] = "100000000000000000000000000011";
    map[3] = "100000000000000000000000000011";
    map[4] = "100000000000000000000000000011";
    map[5] = "100000000000000000000000000011";
    map[6] = "100000000000000000000000000011";
    map[7] = "100000000000000000000000000011";
    map[8] = "100000000001111100000000000011";
    map[9] = "100000000000000000000000000011";
    map[10] = "100000000000100000000000000011";
    map[11] = "100000000000000000000000000011";
    map[12] = "100000000000000000000000000011";
    map[13] = "100000000000000000000000000011";
    map[14] = "100000000000000000000000000011";
    map[15] = "100000000000000000000000000011";
    map[16] = "100000000000000000000000000011";
    map[17] = "111111111111111111111111111111";
    map[18] = NULL;
    return (map);
}
