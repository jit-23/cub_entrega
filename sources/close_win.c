/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_win.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 00:11:29 by fde-jesu          #+#    #+#             */
/*   Updated: 2025/05/28 12:29:57 by mloureir         ###   ########.pt       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	destroy_imgs(t_cub *cub, int i)
{
	while (++i < 5)
	{
		if (cub->imgs[i].img)
			mlx_destroy_image(cub->mlx_con, cub->imgs[i].img);
	}
}

void	end_game(t_cub *cub)
{
	destroy_imgs(cub, -1);
	if (cub->mlx_win)
		mlx_destroy_window(cub->mlx_con, cub->mlx_win);
	if (cub->mlx_con)
	{
		mlx_destroy_display(cub->mlx_con);
		free(cub->mlx_con);
	}
	if (cub->rays)
		free(cub->rays);
	if (cub->map)
		free(cub->map);
	free_all(cub->info);
	exit(0);
}
