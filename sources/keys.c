/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 00:13:55 by fde-jesu          #+#    #+#             */
/*   Updated: 2025/06/03 18:24:56 by fde-jesu         ###   ########.fr       */
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
void	move_player_utils(t_cub *cub, float _cos, float _sin)
{
	if ((cub->k_up) && !colision(cub->info->x + _cos * cub->speed, cub->info->y
			+ _sin * cub->speed, cub, BLOCK_SCALE))
	{
		cub->info->x += _cos * cub->speed;
		cub->info->y += _sin * cub->speed;
	}
	if ((cub->k_down) && !colision(cub ->info->x - _cos * cub->speed,
			cub->info->y - _sin * cub->speed, cub, BLOCK_SCALE))
	{
		cub->info->x -= _cos * cub->speed;
		cub->info->y -= _sin * cub->speed;
	}
	if ((cub->k_right) && !colision(cub ->info->x - _sin * cub->speed,
			cub->info->y + _cos * cub->speed, cub, BLOCK_SCALE))
	{
		cub->info->x -= _sin * cub->speed;
		cub->info->y += _cos * cub->speed;
	}
	if ((cub->k_left) && !colision(cub ->info->x + _sin * cub->speed,
			cub->info->y - _cos * cub->speed, cub, BLOCK_SCALE))
	{
		cub->info->x += _sin * cub->speed;
		cub->info->y -= _cos * cub->speed;
	}
}

bool	is_player(char player_chard)
{
	if (player_chard == 'N' || player_chard == 'S'\
		|| player_chard == 'W' || player_chard == 'E')
		return (true);
	return (false);
}
