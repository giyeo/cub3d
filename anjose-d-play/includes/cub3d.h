#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "mlx.h"
# include <fcntl.h>
# include "errors.h"
# include "defines.h"
# include <X11/X.h>
# include "math.h"
// open();
# include <stdio.h>
// perror();
# include <string.h>
// strerror();
# include <errno.h>

typedef struct s_conn
{
	void	*mlx_ptr;
	void	*win_ptr;
}				t_conn;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;	/* bits per pixel */
	int		line_len;
	int		endian;
}				t_img;

typedef struct s_player
{
	float	x;
	float	y;
	float	width;
	float	height;
	int		turn_direction; // -1 for left, +1 for right | 0 to still
	int		walk_direction; // -1 for back, +1 for front | 0 to still
	float	rotation_angle;
	float	walk_speed;
	float	turn_speed;
	float	fov;
}				t_player;

typedef	struct s_ray
{
	float	angle;
	int		wall_hit_x;
	int		wall_hit_y;
	float	distance; // between player and the collision coordinate

	int		is_fdown;
	int		is_fup;
	int		is_fright;
	int		is_fleft;
}				t_ray;

typedef struct	s_config
{
	char	*NO;
	char	*SO;
	char	*WE;
	char	*EA;
	int		F[3];
	int		C[3];
	char	**map;
	int		map_num_rows;
	int		map_num_cols;
	int		window_width;
	int		window_height;
	int		num_rays;
	int		player_position[2];
	char	player_direction;
	t_conn	conn_mlx;
	t_img	img;
	t_player	player;
	t_ray	*rays;

}			t_config;




/* PARSER */
int		file_validate(char *file, int argc);

int		file_check(char *file);
int		extension_check(char *file);
char	**read_file(int	fd, char *file);
int		line_count(char *file);
void	parser_and_validate(char **buffer, t_config *config);
int		find_split_line(char **read_file);

/* UTILS */
void	throw_error(char *error);
int		only_these(char *str, char *needles);
void	config_init(t_config *config);
void	check_struct(t_config *config, int i);
int		is_one_of_these(char c, char *these);
int		find_player(char **buffer, int first_line, t_config *config);

/* VALIDATE*/
int		validate_config(char **buffer, t_config *config);
int		validate_map(char **buffer, t_config *config);

/* FREE */
void	free_config(t_config *config);

/* MLX */
// hooks
int		key_pressed(int keysym, t_config *config);
int		key_released(int keysym, t_config *config);
int		end_game(t_config *config);
int		load_game(t_config *config);

// render
int		render_background(t_config *config, int color, t_img *img);
void	render_map(t_config *config, int map_y, int map_x, int pixel_i, int pixel_j);
void	render_player(t_config *config);
void	img_pix_put(t_config *config, int x, int y, int color);
int	render_rect(t_config *config, int x, int y, int rect_height, int rect_width, int color);
int		render_line(t_config *config, float x1, float y1, float x2, float y2, int color);

// player
void	move_player(t_config *config);

#endif
