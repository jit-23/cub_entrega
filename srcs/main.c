/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:55:36 by fde-jesu          #+#    #+#             */
/*   Updated: 2025/04/23 18:31:06 by fde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/cub.h"
#include "../libs/mlx/mlx.h"

void draw_map(t_cub *game)
{
    char **map = game->map;
    int color = 0x0000FF;
    for(int y = 0; map[y]; y++)
        for(int x = 0; map[y][x]; x++)
            if(map[y][x] == '1')
                put_square(game, x * 5, y * 5, 5, 0xff0000);
}

void	cast_rays(t_cub *cub)
{
	double	fraction;
	float	start_x;
	int		i;

	fraction = PI / 3 / WIDTH;
	start_x = cub->angle - PI / 6;
	cub->start_x = start_x;
	i = 0;
	while (i < WIDTH)
	{
		init_rays(cub, cub->rays, i);
		draw_line(cub, cub->rays, i);
		start_x += fraction;
		i++;
	}
}

static void show_rays(t_cub *cub, float start_x)
{
	float cos_ = cos(start_x);
	float sin_ = sin(start_x);
	float ray_x = cub->px / 5;
	float ray_y = cub->py / 5;
	while(!colision(ray_x, ray_y, cub, 1))
	{
		put_pixel(cub, ray_x, ray_y, 0xFFF);
		ray_x += cos_;
		ray_y += sin_;
	}
}

int	draw_loop(t_cub *cub)
{
	int i;

	i = 0;
	move_player(cub);
	cast_rays(cub);
	draw_map(cub);
	put_square(cub, cub->px / 5,cub->py / 5, 5, 0xfff000);
	float fraction = PI/3/WIDTH;
	while(i < WIDTH)
	{
		if (i % 50 == 0)
			show_rays(cub, cub->start_x);
		cub->start_x += fraction;
		i++;
	}
	refresh_frames(cub);
	return (0);
}

void	init_cub(t_cub *cub)
{
	set_null(cub);
	cub->rays = (t_rays *)malloc(sizeof(t_rays));
	init_keys(cub);
	cub->px = WIDTH / 2;
	cub->py = HEIGH / 2;
	cub->map = get_map();
	start_cub(cub);
}

void	start_cub(t_cub *cub)
{
	cub->mlx_con = mlx_init();
	cub->mlx_win = mlx_new_window(cub->mlx_con, WIDTH, HEIGH, "cub");
	if (!cub->mlx_win)
		exit_msg(cub, "Can't init window.\n");
	mlx_hook(cub->mlx_win, 17, 0, (void *)close_window, cub);
	cub->img = mlx_new_image(cub->mlx_con, WIDTH, HEIGH);
	cub->img_address = mlx_get_data_addr(cub->img, &cub->bpp, &cub->size_line,
			&cub->endian);
	mlx_put_image_to_window(cub->mlx_con, cub->mlx_win, cub->img, 0, 0);
	init_textures(cub);
}

int	main(int argc, char const *argv[])
{
	t_cub	cub;

	ft_memset((void *)&cub, 0, sizeof(cub));
	init_cub(&cub);
	mlx_hook(cub.mlx_win, 2, 1L << 0, key_press, &cub);
	mlx_hook(cub.mlx_win, 3, 1L << 1, key_release, &cub);
	mlx_loop_hook(cub.mlx_con, draw_loop, &cub);
	mlx_hook(cub.mlx_win, 17, 0, (void *)end_game, &cub);
	mlx_loop(cub.mlx_con);
	return (0);
}
