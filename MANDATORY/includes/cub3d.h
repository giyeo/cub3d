/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 00:10:51 by anjose-d          #+#    #+#             */
/*   Updated: 2023/01/14 17:50:56 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "mlx.h"
# include <fcntl.h>
# include "errors.h"
# include "defines.h"
# include <X11/X.h>
# include "math.h"
# include <stdio.h>
# include <string.h>
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
	int		bpp;
	int		line_len;
	int		endian;
}				t_img;

typedef struct s_player
{
	double	x;
	double	y;
	double	width;
	double	height;
	int		turn_direction;
	int		walk_direction;
	int		walk_side_direction;
	double	rotation_angle;
	double	walk_speed;
	double	turn_speed;
	int		mouse_x;
	int		mouse_y;
}				t_player;

typedef struct s_textures
{
	int		*no;
	int		*so;
	int		*we;
	int		*ea;
	void	*img_no;
	void	*img_so;
	void	*img_we;
	void	*img_ea;
}			t_textures;

typedef struct s_render_line
{
	double	delta_x;
	double	delta_y;
	double	pixel_x;
	double	pixel_y;
	int		pos_x;
	int		pos_y;
	int		pos_x_old;
	int		pos_y_old;
	double	player_x;
	double	player_y;
}			t_render_line;

typedef struct s_config
{
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	int			f[3];
	int			c[3];
	char		**map;
	int			side[2];
	int			texture_col[2];
	int			map_num_rows;
	int			map_num_cols;
	int			player_position[2];
	char		player_direction;
	double		fov;
	t_conn		conn_mlx;
	t_img		img;
	t_player	player;
	t_textures	textures;
}			t_config;

/* PARSER */
int		file_validate(char *file, int argc);

int		file_check(char *file);
int		extension_check(char *file);
char	**read_file(int fd, char *file);
int		line_count(char *file);
int		parser_and_validate(char **buffer, t_config *config);
int		find_split_line(char **read_file);
int		find_map_start(char **read_file);

/* UTILS */
int		throw_error(char *error);
int		throw_msg_error(int error);
int		only_these(char *str, char *needles);
void	config_init(t_config *config);
int		check_struct(t_config *config);
int		is_one_of_these(char c, char *these);
int		find_player(char **buffer, int first_line, t_config *config);
int		mlx_get_hex_trgb(int r, int g, int b);
double	normalize_angle(double angle);
void	config_populate(t_config *config);
int		test_path(char *path);
int		count_occur(char *str, char c);
char	*ft_skip_space(char *str);

/* VALIDATE*/
int		validate_config(char **buffer, t_config *config, int map_line);
int		validate_map(char **buffer, t_config *config);
void	assign_color(t_config *config, int color[], char type);

int		color_error_handling(char *line_content);
int		line_check(char line_cont, int *has_digit, int *count_commas);

int		parse_line_content(char *line_content, char type, t_config *config);

/* FREE */
void	free_config(t_config *config);

/* MLX */
// hooks
int		key_pressed(int keysym, t_config *config);
int		key_released(int keysym, t_config *config);
int		end_game(t_config *config);
int		load_game(t_config *config);

// render
void	img_pix_put(t_img *img, int x, int y, int color);
double	render_line(t_config *config, double x1, double y1);

//execution
void	update(t_config *config);
void	raycaster(t_config *config);

void	load_textures(t_config *config);

#endif
