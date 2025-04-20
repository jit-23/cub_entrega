/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:55:36 by fde-jesu          #+#    #+#             */
/*   Updated: 2025/04/20 00:58:40 by fde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/cub.h"
#include "../libs/mlx/mlx.h"

void cast_rays(t_cub *cub)
{
	double	fraction;
    float	start_x;
    int		i;
	
	fraction = PI / 3 / WIDTH;
	start_x = cub->angle - PI / 6;
	i = 0;
    while(i < WIDTH)
    {
		init_rays( cub, cub->rays, i);
		draw_line(cub,  cub->rays, i);
        start_x += fraction;
        i++;
    }
}

int draw_loop(t_cub *cub)
{
	move_player(cub);
	cast_rays(cub);
	refresh_frames(cub);
	return 0;
}

void init_cub(t_cub *cub)
{
	
	set_null(cub);
	cub->rays = (t_rays *)malloc(sizeof(t_rays));
    init_keys(cub);
	cub->px = WIDTH / 2;
	cub->py = HEIGH / 2;
	cub->map = get_map();
	start_cub(cub);
}

void start_cub(t_cub *cub)
{
    cub->mlx_con = mlx_init();
	cub->mlx_win = mlx_new_window(cub->mlx_con, WIDTH , HEIGH, "cub");
	
	if (!cub->mlx_win)
		exit_msg(cub, "Can't init win.\n");
	mlx_hook(cub->mlx_win, 17, 0, (void *)close_window, cub);
	cub->img = mlx_new_image(cub->mlx_con, WIDTH, HEIGH);
	cub->img_address = mlx_get_data_addr(cub->img , &cub->bpp,
        &cub->size_line, &cub->endian);
	mlx_put_image_to_window(cub->mlx_con, cub->mlx_win, cub->img, 0, 0);
	cub->imgs[0].img = mlx_xpm_file_to_image(cub->mlx_con, "textures/3.xpm", &(cub->imgs[0].x), &(cub->imgs[0].y));
	cub->imgs[0].addr = mlx_get_data_addr(cub->imgs[0].img, &cub->imgs[0].bpp, &cub->imgs[0].size_line, &cub->imgs[0].endian);
	cub->imgs[1].img = mlx_new_image(cub->mlx_con, WIDTH, HEIGH);
	cub->imgs[1].addr = mlx_get_data_addr(cub->imgs[1].img, &cub->imgs[1].bpp, &cub->imgs[1].size_line, &cub->imgs[1].endian);

}


int main(int argc, char const *argv[])
{
	
    t_cub	cub;

	ft_memset((void *)&cub, 0,sizeof(cub));
	init_cub(&cub);
	mlx_hook(cub.mlx_win,2, 1L<<0, key_press, &cub);
	mlx_hook(cub.mlx_win,3, 1L<<1, key_release, &cub);
	mlx_loop_hook(cub.mlx_con, draw_loop, &cub);
	mlx_hook(cub.mlx_win, 17, 0, (void *)end_game, &cub);
	mlx_loop(cub.mlx_con);
	
    return 0;
}
