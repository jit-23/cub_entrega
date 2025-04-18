/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:55:36 by fde-jesu          #+#    #+#             */
/*   Updated: 2025/04/19 00:38:11 by fde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/cub.h"

void init_rays( t_cub *cub, t_rays *rays, int i);

int key_press(int kcode, t_cub *cub)
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
	if(kcode == LESS)
	    cub->speed-=2;
	if(kcode == PLUSS)
        cub->speed+=2;
	if (kcode == 113 ||kcode == 65307) 
		exit(1);
	return 0;
}

int key_release(int kcode, t_cub *cub)
{
    if(kcode == W)
        cub->k_up = false;
    if(kcode == S)
        cub->k_down = false;
    if(kcode == A)
        cub->k_left = false;
    if(kcode == D)
        cub->k_right = false;
    if(kcode == LEFT)
        cub->left_r = false;
    if(kcode == RIGHT)
        cub->right_r = false;
    return 0;
}

void close_window(void)
{
	exit(0);
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
	if (!(cub->imgs[0].x))
		perror("non existent");
	if (!(cub->imgs[0].y))
		perror("non existent");
	cub->imgs[0].img = mlx_xpm_file_to_image(cub->mlx_con, "textures/3.xpm", &(cub->imgs[0].x), &(cub->imgs[0].y));
	cub->imgs[0].addr = mlx_get_data_addr(cub->imgs[0].img, &cub->imgs[0].bpp, &cub->imgs[0].size_line, &cub->imgs[0].endian);
	cub->imgs[1].img = mlx_new_image(cub->mlx_con, WIDTH, HEIGH);
	cub->imgs[1].addr = mlx_get_data_addr(cub->imgs[1].img, &cub->imgs[1].bpp, &cub->imgs[1].size_line, &cub->imgs[1].endian);
}

void init_keys(t_cub *cub)
{
    cub->k_up = false;
    cub->k_down = false;
    cub->k_left = false;
    cub->k_right = false;
	cub->k_plus = false;
	cub->k_less = false;
	cub->left_r = false;
	cub->right_r = false;
	
    cub->angle  = NORTH;
	cub->speed = 0.2;
    cub->sin = 1;
	cub->cos = 0;
}


void move_player_utils(t_cub *cub, float cos, float sin)
{
    if ((cub->k_up )) 
	{
		cub->px += cos * cub->speed;
		cub->py += sin * cub->speed;
	}
	if ((cub->k_down))
	{
		cub->px -= cos * cub->speed;
		cub->py -= sin * cub->speed;
	}
	if ((cub->k_right))
	{
		cub->px -= sin * cub->speed;
		cub->py += cos * cub->speed;
	}
	if ((cub->k_left))
	{
		cub->px += sin * cub->speed;
		cub->py -= cos * cub->speed;
	}
}

void cast_rays(t_cub *cub)
{

	double fraction = PI / 3 / WIDTH;
    float start_x = cub->angle - PI / 6;
    int i = 0;
    while(i < WIDTH)
    {
		init_rays( cub, cub->rays, i);
        draw_line(cub,  cub->rays, i);
        start_x += fraction;
        i++;
    }
}

void move_player(t_cub *cub)
{
	float angle_speed = 0.01;
	float cos_angl = cos(cub->angle);
	float sin_angl = sin(cub->angle);

	if (cub->left_r)
		cub->angle -= angle_speed;
	if (cub->right_r)
		cub->angle += angle_speed;
	if (cub->angle <=  0)
		cub->angle += 2 * PI;
	if (cub->angle > 2 * PI)
		cub->angle = 0;
	move_player_utils(cub, cos_angl, sin_angl);
}

void draw_line(t_cub *cub, t_rays *rays, int i)
{

	int	column;

	column = -1;
	// ceiling
	while( ++column < rays->drawStart)
		my_mlx_pixel_put(&cub->imgs[1], i, column, 0xFF);
	// floor
	column = -1;
	while( ++column < rays->drawEnd)
		my_mlx_pixel_put(&cub->imgs[1], i, column, 0xFFFF);
	// walls
	while (rays->y < rays->drawEnd) {
	rays->texY = (int)rays->texPos;
	if (rays->texY < 0)
        rays->texY = 0;
	if (rays->texY >= cub->imgs[0].y) 
        rays->texY = cub->imgs[0].y - 1;

	rays->color = *(int *)(cub->imgs[0].addr +
                (rays->texY * cub->imgs[0].size_line + rays->texX * (cub->imgs[0].bpp / 8)));
	my_mlx_pixel_put(&cub->imgs[1], i, rays->y, rays->color);
	rays->texPos += rays->step;
	rays->y++;
}
}

void ft_calc_ray_side(t_cub *cub, t_rays *rays)
{
	if (rays->rayDirX < 0) { //esquerda
	rays->stepX = -1; // valor para 
	rays->sideDistX = (cub->px - rays->mapX) * rays->deltaDistX;
 } else {
	 rays->stepX = 1;
	 rays->sideDistX = (rays->mapX + 1.0 - cub->px) * rays->deltaDistX;
}

if (rays->rayDirY < 0)
	{
		rays->stepY = -1; // baixo
		rays->sideDistY = (cub->py - rays->mapY) * rays->deltaDistY;
	} 
else {
	rays->stepY = 1; // cima
	rays->sideDistY = (rays->mapY + 1.0 - cub->py) * rays->deltaDistY;
 }
}

void ft_calc_dda(t_cub *cub, t_rays *rays)
{
	rays->hit = 0;
	 while (rays->hit == 0) {
	 // Move in the direction of the shortest step
	if (rays->sideDistX < rays->sideDistY) {
		 rays->sideDistX += rays->deltaDistX;
		 rays->mapX += rays->stepX;
		 rays->side = 0;
	} else {
		 rays->sideDistY += rays->deltaDistY;
		 rays->mapY += rays->stepY;
		 rays->side = 1;
	}
	 // Check for a collision (wall hit)
	 if (colision(rays->mapX, rays->mapY, cub)) {
		 rays->hit = 1;
	}
	}
}

ft_calc_dist_wall(t_cub *cub, t_rays *rays, int i)
{
	if (rays->side == 0)
   		rays->perpWallDist = (rays->mapX - cub->px + (1 - rays->stepX) / 2) / rays->rayDirX;
	else
    	rays->perpWallDist = (rays->mapY - cub->py + (1 - rays->stepY) / 2) / rays->rayDirY;
rays->lineHeight = (BLOCK * HEIGH ) / rays->perpWallDist ;
  rays->drawStart = -rays->lineHeight / 2 + HEIGH / 2;
 if (rays->drawStart < 0) 
	rays->drawStart = 0;
rays->drawEnd = rays->lineHeight / 2 + HEIGH / 2;
if (rays->drawEnd >= HEIGH)
	rays->drawEnd = HEIGH - 1;
if (rays->side == 0)
    rays->xwall = cub->py + rays->perpWallDist * rays->rayDirY;
else
    rays->xwall = cub->px + rays->perpWallDist * rays->rayDirX;
rays->xwall = fmod(rays->xwall, BLOCK)/BLOCK ;
rays->texX =  (int) ((rays->xwall) * ((double)cub->imgs[0].x));
if ((rays->side == 0 && rays->rayDirX < 0))
    rays->texX = cub->imgs[0].x - rays->texX - 1;
if (rays->side == 1 && rays->rayDirY > 0)
    rays->texX = cub->imgs[0].x - rays->texX - 1;
rays->y = rays->drawStart;
rays->step = 1.0 * cub->imgs[0].y /rays->lineHeight ;//BLOCK;
rays->texPos = (rays->drawStart - HEIGH / 2 + rays->lineHeight / 2) * rays->step;
}

void init_rays( t_cub *cub, t_rays *rays, int i)
{
	rays = (t_rays *)malloc(sizeof(t_rays));
	ft_memset((void *)rays, 0, sizeof(rays));
	rays->mapX = (int)cub->px;  
	rays->mapY = (int)cub->py; 
	rays->fov = PI/3;
	rays->planeLength = tan(rays->fov / 2);
	rays->dirX = cos(cub->angle);
	rays->dirY = sin(cub->angle);
	rays->planeX = -rays->dirY * rays->planeLength;
	rays->planeY =  rays->dirX * rays->planeLength;
	rays->cameraX = 2 * i / (double)WIDTH - 1;
	rays->rayDirX = rays->dirX + rays->planeX * rays->cameraX;
	rays->rayDirY = rays->dirY + rays->planeY * rays->cameraX;
	rays->deltaDistX = sqrt(1 + (rays->rayDirY * rays->rayDirY) / (rays->rayDirX * rays->rayDirX));
	rays->deltaDistY = sqrt(1 + (rays->rayDirX * rays->rayDirX) / (rays->rayDirY * rays->rayDirY));
	ft_calc_ray_side(cub, rays);
	ft_calc_dda(cub, rays);
	
}

int draw_loop(t_cub *cub)
{
	move_player(cub);
	//put_square(cub, cub->px,cub->py, BLOCK, 0xfff000); // funcoes para o mini map(probably)
	//draw_map(cub);
	cast_rays(cub);
	mlx_put_image_to_window(cub->mlx_con, cub->mlx_win,cub->img,0,0);
	mlx_put_image_to_window(cub->mlx_con, cub->mlx_win, cub->imgs[1].img, 0, 0);
	return 0;
	return 0;
}
char **get_map(void)
{
    char **map = malloc(sizeof(char *) * 22);
    map[0] = "111111111111111111111111111111";
    map[1] = "100000000000000000000000000011";
    map[2] = "100000000000000000000000000011";
    map[3] = "100000000000000000000000000011";
    map[4] = "100000000000000000000000000011";
    map[5] = "100000000000000000000000000011";
    map[6] = "100000000000000000000000000011";
    map[7] = "100000000000000000000000000011";
    map[8] = "100000000001111100000000000011";
    map[9] = "100000000000000000000000000011";
    map[10] = "100000000000100000000000000011";
    map[11] = "100000000000000000000000000011";
    map[12] = "100000000000000000000000000011";
    map[13] = "100000000000000000000000000011";
    map[14] = "100000000000000000000000000011";
    map[15] = "100000000000000000000000000011";
    map[16] = "100000000000000000000000000011";
    map[17] = "111111111111111111111111111111";
    map[18] = NULL;
    return (map);
}

void start_cub(t_cub *cub)
{
    cub->mlx_con = mlx_init();
	cub->mlx_win = mlx_new_window(cub->mlx_con, WIDTH , HEIGH, "cub");
	if (!cub->mlx_win)
		exit_msg(cub, "Can't init win.\n");
	mlx_hook(cub->mlx_win, 17, 0, (void *)close_window, cub);
	cub->img = mlx_new_image(cub->mlx_con, WIDTH, HEIGH);
	cub->img_address = mlx_get_data_addr(cub->img , &cub->bpp,  &cub->size_line, &cub->endian);
	mlx_put_image_to_window(cub->mlx_con, cub->mlx_win, cub->img, 0, 0);
	if (!(cub->imgs[0].x))
		perror("non existent");
	if (!(cub->imgs[0].y))
		perror("non existent");
	if (access("textures/grass.xpm", F_OK) == -1)
		perror("File access error");
	else
		printf("done \n");
	cub->imgs[0].img = mlx_xpm_file_to_image(cub->mlx_con, "textures/3.xpm", &(cub->imgs[0].x), &(cub->imgs[0].y));
	cub->imgs[0].addr = mlx_get_data_addr(cub->imgs[0].img, &cub->imgs[0].bpp, &cub->imgs[0].size_line, &cub->imgs[0].endian);
	cub->imgs[1].img = mlx_new_image(cub->mlx_con, WIDTH, HEIGH);
	cub->imgs[1].addr = mlx_get_data_addr(cub->imgs[1].img, &cub->imgs[1].bpp, &cub->imgs[1].size_line, &cub->imgs[1].endian);
}

void init_cub(t_cub *cub)
{
    ft_memset((void *)cub, 0, sizeof(cub));
    init_keys(cub);
	cub->px = WIDTH / 2;
	cub->py = HEIGH / 2;
	cub->map = get_map();
	start_cub(cub);
}

int main(int argc, char const *argv[])
{
    t_cub cub;
    init_cub(&cub);
    mlx_hook(cub.mlx_win,2, 1L<<0, key_press, &cub);
	mlx_hook(cub.mlx_win,3, 1L<<1, key_release, &cub);
	mlx_loop_hook(cub.mlx_con, draw_loop, &cub);

    return 0;
}
