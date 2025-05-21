/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 00:13:55 by fde-jesu          #+#    #+#             */
/*   Updated: 2025/05/20 15:33:36 by mloureir         ###   ########.pt       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	key_press(int kcode, t_cub *cub)
{
	if (kcode == W)
		cub->k_up = true;
	if (kcode == S)
		cub->k_down = true;
	if (kcode == A)
		cub->k_left = true;
	if (kcode == D)
		cub->k_right = true;
	if (kcode == LEFT)
		cub->left_r = true;
	if (kcode == RIGHT)
		cub->right_r = true;
	if (kcode == LESS && cub->speed - 1 > 0)
		cub->speed -= 1;
	if (kcode == PLUSS && cub->speed + 1 < 5)
		cub->speed += 1;
	if (kcode == 113 || kcode == 65307)
		end_game(cub);
	return (0);
}

int	key_release(int kcode, t_cub *cub)
{
	if (kcode == W)
		cub->k_up = false;
	if (kcode == S)
		cub->k_down = false;
	if (kcode == A)
		cub->k_left = false;
	if (kcode == D)
		cub->k_right = false;
	if (kcode == LEFT)
		cub->left_r = false;
	if (kcode == RIGHT)
		cub->right_r = false;
	return (0);
}

/* add the collision function here to stop the player from passing walls */
void	move_player_utils(t_cub *cub, float cos, float sin)
{
	if ((cub->k_up) && !colision(cub->px + cos * cub->speed, cub->py + sin
			* cub->speed, cub, 0))
	{
		cub->px += cos * cub->speed;
		cub->py += sin * cub->speed;
	}
	if ((cub->k_down) && !colision(cub->px - cos * cub->speed, cub->py - sin
			* cub->speed, cub, 0))
	{
		cub->px -= cos * cub->speed;
		cub->py -= sin * cub->speed;
	}
	if ((cub->k_right) && !colision(cub->px - sin * cub->speed, cub->py + cos
			* cub->speed, cub, 0))
	{
		cub->px -= sin * cub->speed;
		cub->py += cos * cub->speed;
	}
	if ((cub->k_left) && !colision(cub->px + sin * cub->speed, cub->py - cos
			* cub->speed, cub, 0))
	{
		cub->px += sin * cub->speed;
		cub->py -= cos * cub->speed;
	}
}
