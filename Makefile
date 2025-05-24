#Compile Options
NAME = cub3d
CC = cc
CFLAGS =  -g -Wall -Wextra -Werror
MLXFLAGS = -L/usr/X11R6/lib -lX11 -lXext -lm
# Directories
MLX = mlx/libmlx_Linux.a
LIBFT = includes/libft/libft.a
SRC = sources/main.c\
		sources/set_null.c\
		sources/calc_dist_wall.c\
		sources/calc_rays.c\
		sources/close_win.c\
		sources/display_rays.c\
		sources/draw_map.c\
		sources/exit_functions.c\
		sources/init_cub.c\
		sources/keys.c\
		sources/flood_fill.c\
		sources/verify.c\
		sources/copy_map.c\
		sources/map_get.c\
		sources/colors.c\
		sources/map_values_check.c\
		sources/map_checker.c\
		sources/map_content_check.c\
		sources/parsing.c\
		sources/textures.c\
		sources/utils.c\
		sources/utils2.c\
		sources/utils3.c\
		sources/utils4.c\
		sources/draw_utils.c\
		sources/mini_map_utils.c\
# Commands
RM = rm -rf
OBJ = $(SRC:.c=.o)
# Defs
GREEN=\e[38;5;118m
END= $<\e[0m

all: checker $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $*.c -o $*.o

$(NAME) : $(OBJ) $(LIBFT) $(PRINTF) $(MLX)
	@$(CC) $(CFLAGS) $(MLXFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(MLX) $(MLXFLAGS)

$(LIBFT):
	@make --silent -C includes/libft

$(MLX):
	make -C mlx

checker:
	@if [ -d "mlx" ]; then echo "$(GREEN)[MLX FOLDER FOUND]$(END)"; else make download; fi

download:
	git clone git@github.com:42Paris/minilibx-linux.git mlx

mlx_clean:
	rm -rf mlx

clean:
	$(RM) $(OBJ)
	@make --silent -C includes/libft clean

fclean: clean mlx_clean
	$(RM) $(NAME)
	@make --silent -C includes/libft fclean

re: fclean all
