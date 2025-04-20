#ifndef CUB_H
#define CUB_H

#include "libft/libft.h"
#include "mlx/mlx.h"

#include <stdbool.h> 
# include <curses.h>
# include <errno.h>
# include <limits.h>
# include <linux/limits.h>
# include <signal.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <term.h>
# include <unistd.h>
# include <math.h>

#define W 119
#define S 115
#define D 100
#define A 97
#define LEFT 65361
#define RIGHT 65363
#define LESS 45
#define PLUSS 61
#define BLOCK 25

#define PI 3.14159

#define WIDTH 800
#define HEIGH 600
#define PIXEL 32

#define NORTH -(3.14159/2)
#define SOUTH (3.14159/2)
#define WEST -(3.14159)
#define EAST (3.14159)
/* static float calc_dist(float x,float y)
{
	return (sqrt(x*x+y*y));
} */


typedef struct s_rays
{

    int mapX;
    int mapY;
    double fov;
    double planeLength;
    
    double dirX;
    double dirY;
    
    double planeX;
    double planeY;
    
    double cameraX;
    
    double rayDirX;
    double rayDirY;

    double deltaDistX;
    double deltaDistY;

    double sideDistX;
    double sideDistY;

    int stepX;
    int stepY;

    int hit;
    int side;

    double perpWallDist;
    double lineHeight;
    int drawStart;
    int drawEnd;
    double xwall;
    int texX;
    int y;
    float step;
    float texPos;
    int texY;
    int color;
}t_rays;

typedef struct s_img
{
    void *img;
    char *addr;
    int x;
    int y;
    int bpp;
    int size_line;
    int endian;

}t_img;

typedef struct s_cub
{
    
    char *img_address;
    int bpp;
    int size_line;
    int endian;
    void *mlx_con;
    void *mlx_win;
    void *img;
    int map_x;
    int map_y;

    /* player info */
    int fov;
    int pos;
    char **map;

    double dist;

    float cos;
    float sin;
    float px;
    float py;
    
    float angle;

    float speed;

    bool k_plus;
    bool k_less;
    bool k_up;
    bool k_down;
    bool k_left;
    bool k_right;
    bool right_r;
    bool left_r;

    int direction;

    t_img imgs[2];
    t_rays *rays;
}t_cub;


void init_keys(t_cub *cub);
void init_cub(t_cub *cub);
void close_window(void);
int key_press(int kcode, t_cub *cub);
int key_release(int kcode, t_cub *cub);
void move_player(t_cub *cub);
void move_player_utils(t_cub *cub, float cos, float sin);

void    start_cub(t_cub *cub);
void init_cub(t_cub *cub);
void exit_msg(t_cub *cub, char *str);
void put_square(t_cub *cub, int x, int y, int size, int color);
int key_press(int kcode, t_cub *cub);
void move_player(t_cub *cub);
void close_window(void);
int  draw_loop(t_cub *cub);
char **get_map(void);
void cast_rays(t_cub *cub);
void my_mlx_pixel_put(t_img *img, int x, int y, int color);

void init_rays( t_cub *cub, t_rays *rays, int i);
void draw_line(t_cub *cub, t_rays *rays, int i);
bool colision(float px, float py, t_cub *cub);
void exit_msg(t_cub *cub, char *str);
void my_mlx_pixel_put(t_img *img, int x, int y, int color); // img = cub->imgs[1] // [1] e o que corresponde ao ecra


void set_null_window_vars(t_cub *cub);
void set_null_key_vars(t_cub *cub);
void set_null_player_vars(t_cub *cub);
void set_null(t_cub *cub);
void set_null_texture_vars(t_cub *cub, int i);
void end_game(t_cub *cub);
void calc_text_wall_pixel(t_cub *cub, t_rays **ray);
void ft_calc_dist_wall(t_cub *cub, t_rays **ray, int i);
void refresh_frames(t_cub *cub);

/* unused funct headers */
void draw_map(t_cub *game);
void clear_win(t_cub *cub);
void put_pixel(t_cub *cub, int x, int y, int color);
#endif