/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 08:36:09 by mloureir          #+#    #+#             */
/*   Updated: 2025/05/31 10:40:55 by mloureir         ###   ########.pt       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	move_player(t_cub *cub)
{
	float	angle_speed;
	float	cos_angl;
	float	sin_angl;

	angle_speed = 0.02;
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

void	free_maps(t_map *info)
{
	int	i;

	i = 0;
	while (i <= info->map_y && info->map_y > 0)
	{
		free(info->map[i]);
		i++;
	}
	if (info->map_y > 0)
		free(info->map);
	i = 0;
	while (i <= info->map_ff_y && info->map_ff_y > 0)
	{
		free(info->map_ff[i]);
		i++;
	}
	if (info->map_ff_y > 0)
		free(info->map_ff);
}

void	free_all(t_map *info)
{
	int	i;

	i = 0;
	while (i < MAX_TEXTURE)
	{
		if (info->texture[i].identifier)
			free(info->texture[i].identifier);
		if (info->texture[i].path)
			free(info->texture[i].path);
		i++;
	}
	free_maps(info);
}

int	main(int argc, char **argv)
{
	t_map	info;

	start_vars(&info);
	if (argc != 2)
	{
		ft_putstr_fd("Error on arguments\n", STDERR_FILENO);
		return (1);
	}
	if (parser(&info, argv[1]) != 0)
	{
		ft_putstr_fd("Map error\n", STDERR_FILENO);
		free_all(&info);
		return (1);
	}
	info.color[0].val = color(0, info.color[0].red, info.color[0].green,
			info.color[0].blue);
	info.color[1].val = color(0, info.color[1].red, info.color[1].green,
			info.color[1].blue);
	cub3d(&info);
	free_all(&info);
}
