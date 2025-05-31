/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:25:17 by mloureir          #+#    #+#             */
/*   Updated: 2025/05/31 03:17:07 by fde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	draw_loop(t_cub *cub)
{
	move_player(cub);
	ray_casting(cub);
	create_minimap(cub);
	refresh_frames(cub);

	return (0);
}

void	start_cub(t_cub *cub)
{
	cub->mlx_con = mlx_init();
	cub->mlx_win = mlx_new_window(cub->mlx_con, WIDTH, HEIGH, "cub");
	if (!cub->mlx_win)
		exit_msg(cub, "Can't init window.\n");
	if (init_textures(cub) != 0)
	{
		end_game(cub);
		exit_msg(cub, "No img.\n");
	}
}

void	cub3d(t_map *info)
{
	t_cub	cub;

	cub.info = info;
	init_cub(&cub);

	mlx_hook(cub.mlx_win, 2, 1L << 0, key_press, &cub);
	mlx_hook(cub.mlx_win, 3, 1L << 1, key_release, &cub);
	mlx_loop_hook(cub.mlx_con, draw_loop, &cub);
	mlx_hook(cub.mlx_win, 17, 0, (void *)end_game, &cub);
	mlx_loop(cub.mlx_con);
}

void	refresh_frames(t_cub *cub)
{
	mlx_put_image_to_window(cub->mlx_con, cub->mlx_win, cub->imgs[0].img, 0, 0);
}
