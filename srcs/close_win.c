/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_win.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 00:11:29 by fde-jesu          #+#    #+#             */
/*   Updated: 2025/04/20 00:11:45 by fde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/cub.h"
#include "../libs/mlx/mlx.h"


void end_game(t_cub *cub)
{
	int i;

	i = -1;
	if (cub->img_address)
		mlx_destroy_image(cub->mlx_con, cub->img);
	if(cub->imgs[0].img)
		mlx_destroy_image(cub->mlx_con, cub->imgs[0].img);
	if(cub->imgs[1].img)
		mlx_destroy_image(cub->mlx_con, cub->imgs[1].img);
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
	exit(0);
		
}