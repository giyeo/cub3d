#include "cub3d.h"

int		get_color_from_texture(t_config *config, double wall_strip, int x_hit,
			int *y_wall);
void	paint_wall(t_config *config, int x, double wall_strip, int x_hit);
int		ray_trace(t_config *config, double angle);

void	raycaster(t_config *config)
{
	double	fov;
	double	distances;
	double	wall_strip;
	double	angle;
	int		x;

	x = 0;
	fov = config->FOV * (PI / 180);
	angle = normalize_angle(config->player.rotation_angle - (fov / 2.0));
	while (x < WINDOW_WIDTH)
	{
		config->player.is_middle = 0;
		if (x == WINDOW_WIDTH / 2)
			config->player.is_middle = 1;
		distances = ray_trace(config, angle);
		distances *= cos(angle - config->player.rotation_angle);
		angle += normalize_angle((fov / WINDOW_WIDTH));
		wall_strip = (TILE_SIZE / distances)
			* (WINDOW_WIDTH / 2)
			/ tan(fov / 2);
		int	x_hit = config->texture_col[1];
		if (config->texture_col[1] == 0 || config->texture_col[1] == 63)
			x_hit = config->texture_col[0];
		paint_wall(config, x++, wall_strip, x_hit);
	}
}

int	ray_trace(t_config *config, double angle)
{
	return (render_line(config,
			(config->player.x * TILE_SIZE), (config->player.y * TILE_SIZE),
			((config->player.x * TILE_SIZE) + cos(angle) * (RAY_RANGE)),
			((config->player.y * TILE_SIZE) + sin(angle) * (RAY_RANGE)),
			mlx_get_hex_trgb(0, 0, 0),
			0));
}

void	paint_wall(t_config *config, int x, double wall_strip, int x_hit)
{
	int	y_start_wall;
	int	y_end_wall;
	int	y_wall;
	int	y;

	y_start_wall = (WINDOW_HEIGHT - wall_strip) / 2.0;
	y_end_wall = y_start_wall + wall_strip;
	y_wall = 0;
	y = 0;
	while (y < WINDOW_HEIGHT)
	{
		if (y < y_start_wall)
			img_pix_put(&config->img, x, y,
				mlx_get_hex_trgb(50, 50, 50));
		else if (y < y_end_wall)
			img_pix_put(&config->img, x, y,
				get_color_from_texture(config, wall_strip, x_hit, &y_wall));
		else
			img_pix_put(&config->img, x, y,
				mlx_get_hex_trgb(150, 150, 150));
		y++;
	}
}

int	get_color_from_texture(t_config *config, double wall_strip, int x, int *y)
{
	double	offset;
	int		is_over_screen;
	int		column;
	int		line;

	is_over_screen = 0;
	if (wall_strip > WINDOW_HEIGHT)
		is_over_screen = 1;
	offset = ((wall_strip - WINDOW_HEIGHT) / 2.0) * is_over_screen + *y;
	column = x % 64;
	line = (int)(offset / wall_strip * 64);
	*y += 1;
	return (*(config->texture_test + column + line * 64));
}
