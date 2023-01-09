#include "cub3d.h"

int	this_point_is_in_a_circle(int i, int j, int x_position, int y_position, int radius);

void	minimap(t_config *config)
{
	int pixel_i = 0;
	int pixel_j = 0;
	int map_y = 0;
	int map_x = 0;

	while(map_y < config->map_num_rows)
	{
		while(map_x < config->map_num_cols)
		{
			if(pixel_i % (TILE_SIZE) == 0 && pixel_i != 0)
				map_x++;
			if (map_x < config->map_num_cols)
				render_map(config, map_y, map_x, MINIMAP_SCALE_FACTOR * pixel_i, MINIMAP_SCALE_FACTOR * pixel_j);
			if(this_point_is_in_a_circle(pixel_i, pixel_j, config->player.x * TILE_SIZE, config->player.y * TILE_SIZE, 10))
				img_pix_put(&config->img, MINIMAP_SCALE_FACTOR * pixel_i, MINIMAP_SCALE_FACTOR * pixel_j, YELLOW_PIXEL);
			pixel_i++;
		}
		map_x = 0;
		pixel_i = 0;
		pixel_j++;
		if(pixel_j % (TILE_SIZE) == 0)
			map_y++;
	}

	int i = 0;
	double FOV = 60.0 * (PI / 180);
	double angle = config->player.rotation_angle - (FOV / 2.0);
	while(i < WINDOW_WIDTH)
	{
		render_line(config,
			MINIMAP_SCALE_FACTOR * (config->player.x * TILE_SIZE),
			MINIMAP_SCALE_FACTOR * (config->player.y * TILE_SIZE),
			MINIMAP_SCALE_FACTOR * ((config->player.x * TILE_SIZE) + cos(angle) * (RAY_RANGE / MINIMAP_SCALE_FACTOR)),
			MINIMAP_SCALE_FACTOR * ((config->player.y * TILE_SIZE) + sin(angle) * (RAY_RANGE / MINIMAP_SCALE_FACTOR)),
			mlx_get_hex_trgb(255, 0, 0),
			1
		);
		angle += (FOV / WINDOW_WIDTH);
		i++;
	}
}

int	this_point_is_in_a_circle(int i, int j, int x_position, int y_position, int radius)
{
	if(((i - x_position) * (i - x_position)) + ((j - y_position) * (j - y_position)) < (radius * radius))
		return 1;
	return 0; 
}