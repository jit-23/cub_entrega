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
    bool left_r;
    bool right_r;
    bool k_up;
    bool k_down;
    bool k_left;
    bool k_right;

    int direction;

    t_img imgs[2];
    t_rays *rays;
}t_cub;

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

void init_keys(t_cub *cub);
void init_cub(t_cub *cub);
void close_window(void);
int key_press(int kcode, t_cub *cub);
int key_release(int kcode, t_cub *cub);
void move_player(t_cub *cub);
void move_player_utils(t_cub *cub, float cos, float sin);
void draw_line(t_cub *cub, float angl_start, int i);




#endif