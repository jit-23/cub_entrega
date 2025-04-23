/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_mov.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 00:15:13 by fde-jesu          #+#    #+#             */
/*   Updated: 2025/04/20 00:23:39 by fde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/cub.h"
#include "../libs/mlx/mlx.h"

void	move_player(t_cub *cub)
{
	float	angle_speed;
	float	cos_angl;
	float	sin_angl;

	angle_speed = 0.01;
	sin_angl = sin(cub->angle);
	cos_angl = cos(cub->angle);
	if (cub->left_r)
		cub->angle -= angle_speed;
	if (cub->right_r)
		cub->angle += angle_speed;
	if (cub->angle <= 0)
		cub->angle += 2 * PI;
	if (cub->angle > 2 * PI)
		cub->angle = 0;
	move_player_utils(cub, cos_angl, sin_angl);
}
