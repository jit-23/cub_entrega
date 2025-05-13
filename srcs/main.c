/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:55:36 by fde-jesu          #+#    #+#             */
/*   Updated: 2025/05/13 19:38:54 by fde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/cub.h"
#include "../libs/mlx/mlx.h"



int	draw_loop(t_cub *cub)
{
	
	move_player(cub);
	ray_casting(cub);
	create_minimap(cub);
	refresh_frames(cub);
	return (0);
}

void set_player_atributes(t_cub *cub)
{
	cub->px = WIDTH / 2;
	cub->py = HEIGH / 2;
	cub->angle = PI / 2;
	cub->speed = 1.3;
}


void	init_cub(t_cub *cub)
{
	set_null(cub);
	init_keys(cub);
	cub->rays = (t_rays *)malloc(sizeof(t_rays));
	cub->map = get_map();
	set_player_atributes(cub);
	start_cub(cub);
}

void	start_cub(t_cub *cub)
{
	cub->mlx_con = mlx_init();
	cub->mlx_win = mlx_new_window(cub->mlx_con, WIDTH, HEIGH, "cub");
	if (!cub->mlx_win)
		exit_msg(cub, "Can't init window.\n");
	init_textures(cub);
}

void	cub3d()
{
	t_cub	cub;

	init_cub(&cub);
	mlx_hook(cub.mlx_win, 2, 1L << 0, key_press, &cub);
	mlx_hook(cub.mlx_win, 3, 1L << 1, key_release, &cub);
	mlx_loop_hook(cub.mlx_con, draw_loop, &cub);
	mlx_hook(cub.mlx_win, 17, 0, (void *)end_game, &cub);
	mlx_loop(cub.mlx_con);	
}

int	main(int argc, char const *argv[])
{
	cub3d();
	return (0);
}
