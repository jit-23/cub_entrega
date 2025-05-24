/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 08:37:02 by mloureir          #+#    #+#             */
/*   Updated: 2025/05/24 04:56:56 by fde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "defines.h"

typedef struct s_rays
{
	double		fov;
	double		planelength;
	double		xwall;
	double		dirx;
	double		diry;
	double		planex;
	double		planey;
	double		camerax;
	double		raydirx;
	double		raydiry;
	double		deltadistx;
	double		deltadisty;
	double		sidedistx;
	double		sidedisty;
	double		perpwalldist;
	double		lineheight;
	float		step;
	float		texpos;

	int			mapx;
	int			mapy;
	int			stepx;
	int			stepy;
	int			side;
	int			drawstart;
	int			drawend;
	int			tex_x;
	int			y;
	int			texy;
	int			color;
}				t_rays;

typedef struct s_img
{
	void		*img;
	char		*addr;
	int			x;
	int			y;
	int			bpp;
	int			size_line;
	int			endian;

}				t_img;

typedef struct s_textures
{
	char		*identifier;
	char		*path;
	int			count;
}				t_textures;

typedef struct s_colors
{
	char		*path;
	char		identifier;
	int			val;
	int			red;
	int			green;
	int			blue;
}				t_colors;

typedef struct s_counters
{
	int			no;
	int			so;
	int			we;
	int			ea;
	int			f;
	int			c;
}				t_counters;

typedef struct s_map
{
	float		x;
	float		y;
	char		**map;
	char		**map_ff;
	int			map_y;
	int			map_ff_y;
	int			map_fpos;
	t_colors	color[COLOR];
	t_textures	texture[MAX_TEXTURE];
}				t_map;

typedef struct s_cub
{
	float		angle;
	float		speed;

	t_img		imgs[5];
	t_map		*info;
	t_rays		*rays;
	void		*mlx_con;
	void		*mlx_win;
	char		**map;

	int			map_x;
	int			map_y;
	int			texture2apply;

	bool		k_plus;
	bool		k_less;
	bool		k_up;
	bool		k_down;
	bool		k_left;
	bool		k_right;
	bool		right_r;
	bool		left_r;
}				t_cub;

/* parser */

int				parser(t_map *map, char *map_dir);

/* parser - textures */

char			*get_path(char *buffer);
void			find_texture(char *buffer, t_textures *t_txt);
int				get_texture(t_textures *textures, char *map_dir);

/* parser - checker */

int				check_dotfile(char *map_dir);
int				analiser(char *buffer, t_counters *count);
int				check_content(char *map_dir);
int				check_errs(char *map_dir);

/* parser - value check */

int				check_values(char *map_dir);

/* parser - colors */

char			*get_c_path(char *buffer);
void			find_color(char *buffer, t_colors *colors);
int				startup_check(char *str);
int				check_coloms(char *str, t_colors *colors, int i);
int				seperate_colors(t_colors *colors);

/* parser - map */

int				get_map(t_map *map, char *map_dir);
int				copy_map(t_map *map, char *map_dir);

/* parser - verify values */

int				verify_values(t_map *map);
int				verify_ff(t_map *map);

/* utils */

void			start_counters(t_counters *counters);
char			*rm_nl(char *str);
int				ft_n_atoi(const char *nptr, int n, int s);
int				is_a_param(char *buffer);
int				if_space(int c);
int				is_line_empty(char *str);
char			*jump_empty(int fd);
void			print_debug(t_map *map);
int				map_chars(int c);
void			change_spaces(t_map *map);

/****************************************************************/
/*							Fernando							*/
/****************************************************************/

void			free_all(t_map *info);
void			draw_map(t_cub *game);
void			put_pixel(t_cub *cub, int x, int y, int color);
void			put_circle(t_cub *cub, int x, int y, int color);
void			init_keys(t_cub *cub);
void			init_cub(t_cub *cub);
void			close_window(void);
int				key_press(int kcode, t_cub *cub);
int				key_release(int kcode, t_cub *cub);
void			move_player(t_cub *cub);
void			move_player_utils(t_cub *cub, float cos, float sin);
void			start_cub(t_cub *cub);
void			init_cub(t_cub *cub);
void			exit_msg(t_cub *cub, char *str);
int				key_press(int kcode, t_cub *cub);
void			close_window(void);
int				draw_loop(t_cub *cub);
void			ray_casting(t_cub *cub);
void			my_mlx_pixel_put(t_img *img, int x, int y, int color);
void			init_rays(t_cub *cub, t_rays *rays, int i);
void			draw_line(t_cub *cub, t_rays *rays, int i);
bool			colision(float px, float py, t_cub *cub, int flag);
void			exit_msg(t_cub *cub, char *str);
void			my_mlx_pixel_put(t_img *img, int x, int y, int color);
void			set_null_window_vars(t_cub *cub);
void			set_null_key_vars(t_cub *cub);
void			set_null_player_vars(t_cub *cub);
void			set_null(t_cub *cub);
void			set_null_texture_vars(t_cub *cub, int i);
void			end_game(t_cub *cub);
void			calc_text_wall_pixel(t_cub *cub, t_rays *ray, int texture);
void			ft_calc_dist_wall(t_cub *cub, t_rays *ray);
void			refresh_frames(t_cub *cub);
void			init_textures(t_cub *cub);
void			put_square(t_cub *cub, int x, int y, int color);
void			show_rays(t_cub *cub, float start_x);
void			create_minimap(t_cub *cub);
void			draw_fov(t_cub *cub);
void			cub3d(t_map *info);
int				color(int t, int r, int g, int b);
void			start_vars(t_map *info);
void	set_rays_null(t_rays *ray);


#endif
