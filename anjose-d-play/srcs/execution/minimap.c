#include "cub3d.h"

double	render_line2(t_config *config, int beginX, int beginY, int endX, int endY, int color);
double	ray_calc(t_config *config, t_ray * ray);
int	this_point_is_in_a_circle(int i, int j, int x_position, int y_position, int radius);

char	get_map_at(char **map, double next_touch_x, double next_touch_y);

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
	// double angle = config->player.rotation_angle - (FOV / 2.0);
	// while(i < WINDOW_WIDTH)
	// {
	// 	render_line(config,
	// 		MINIMAP_SCALE_FACTOR * (config->player.x * TILE_SIZE),
	// 		MINIMAP_SCALE_FACTOR * (config->player.y * TILE_SIZE),
	// 		MINIMAP_SCALE_FACTOR * ((config->player.x * TILE_SIZE) + cos(angle) * (RAY_RANGE / MINIMAP_SCALE_FACTOR)),
	// 		MINIMAP_SCALE_FACTOR * ((config->player.y * TILE_SIZE) + sin(angle) * (RAY_RANGE / MINIMAP_SCALE_FACTOR)),
	// 		mlx_get_hex_trgb(255, 0, 0),
	// 		1
	// 	);
	// 	angle += (FOV / WINDOW_WIDTH);
	// 	i++;
	// }
	i = 0;
	double angle1 = config->player.rotation_angle - (FOV / 2.0);
	while (i < 1)
	{
		config->rays[i].angle = normalize_angle(angle1);

		ray_calc(config, &config->rays[i]);
		// printf("y: %f x: %f\n",
		// 	config->rays[i].wallHitX,
		// 	config->rays[i].wallHitY);
		render_line2(config,
			MINIMAP_SCALE_FACTOR * (TILE_SIZE * config->player.x),
			MINIMAP_SCALE_FACTOR * (TILE_SIZE * config->player.y),
			// MINIMAP_SCALE_FACTOR * (TILE_SIZE * config->player.x) + cos(angle) * 50,
			// MINIMAP_SCALE_FACTOR * (TILE_SIZE * config->player.y) + sin(angle) * 50,
			MINIMAP_SCALE_FACTOR * (TILE_SIZE * config->rays[i].wallHitX),
			MINIMAP_SCALE_FACTOR * (TILE_SIZE * config->rays[i].wallHitY),
			RED_PIXEL
		);
		angle1 += (FOV / WINDOW_WIDTH);
		i++;
	}
}

int	this_point_is_in_a_circle(int i, int j, int x_position, int y_position, int radius)
{
	if(((i - x_position) * (i - x_position)) + ((j - y_position) * (j - y_position)) < (radius * radius))
		return 1;
	return 0; 
}

double	find_horizontal_distance(t_config *config, t_ray *ray)
{
	double y_intercept;
	double x_intercept;
	double y_step;
	double x_step;
	int		found_wall_hit = FALSE;

	t_player	*player = &config->player;

	// find the y-coordinate of the closest horizontal grid intersection
	y_intercept = floor(player->y / TILE_SIZE) * TILE_SIZE;
	y_intercept += ray->is_fdown ? TILE_SIZE : 0;

	// find the x-coordinate of the closest horizontal grid intersection
	x_intercept = player->x + ((y_intercept - player->y) / tan(ray->angle));

	// calculate the increment xstep and ystep
	y_step = TILE_SIZE;
	y_step *= ray->is_fup ? -1: 1;

	x_step = TILE_SIZE / tan(ray->angle);
	x_step *= (ray->is_fleft && x_step > 0) ? -1 : 1;
	x_step *= (ray->is_fright && x_step < 0) ? -1 : 1;

	double next_touch_x = x_intercept;
	double next_touch_y = y_intercept;

	while(next_touch_x >= 0 && next_touch_x <= WINDOW_WIDTH
		&& next_touch_y >= 0 && next_touch_y <= WINDOW_HEIGHT)
	{
		double x_check = next_touch_x;
		double y_check = next_touch_y + ray->is_fup ? -1 : 0;
		char grid_content = get_map_at(config->map, x_check, y_check); // if ray is fup, force one pixel up, so we are inside a grid cell
		if (grid_content != '0' && !is_one_of_these(grid_content, PLAYER_DIRECTIONS))
		{
			found_wall_hit = TRUE;
			break ;
		}
		else{
			next_touch_x += x_step;
			next_touch_y += y_step;
		}
	}
	ray->wallHitX = 0;
	ray->wallHitY = 0;
	ray->distance = 0;
	ray->wasHitVertical = FALSE;
	if (found_wall_hit)
	{
		ray->wallHitX = next_touch_x;
		ray->wallHitY = next_touch_y;
		ray->distance = distance_between_points(
							player->x,
							player->y,
							next_touch_x,
							next_touch_y
						);
		ray->wasHitVertical = TRUE;
	}
	else
	{
		ray->distance = __INT_MAX__;
	}
}


void	find_vertical_distance(t_config *config, t_ray *ray)
{
	double y_intercept;
	double x_intercept;
	double y_step;
	double x_step;
	int		found_wall_hit = FALSE;

	t_player	*player = &config->player;

	// printf("px: %d py: %d\n", (int)floor(config->player.x), (int)floor(config->player.y));
	// find the y-coordinate of the closest horizontal grid intersection
	x_intercept = floor(player->x / TILE_SIZE) * TILE_SIZE;
	x_intercept += ray->is_fright ? TILE_SIZE : 0;

	// find the x-coordinate of the closest horizontal grid intersection
	y_intercept = player->y + ((x_intercept - player->x) * tan(ray->angle));
	
	// calculate the increment xstep and ystep
	x_step = TILE_SIZE;
	x_step *= ray->is_fleft ? -1: 1;

	y_step = TILE_SIZE * tan(ray->angle);
	y_step *= (ray->is_fup && y_step > 0) ? -1 : 1;
	y_step *= (ray->is_fdown && y_step < 0) ? -1 : 1;

	double next_touch_x = x_intercept;
	double next_touch_y = y_intercept;

	while(next_touch_x >= 0 && next_touch_x <= WINDOW_WIDTH
		&& next_touch_y >= 0 && next_touch_y <= WINDOW_HEIGHT)
	{
		double x_check = next_touch_x + (ray->is_fleft ? -1 : 0);
		double y_check = next_touch_y;
		char grid_content = get_map_at(config->map, x_check, y_check); // if ray is fup, force one pixel up, so we are inside a grid cell
		if (grid_content != '0' && !is_one_of_these(grid_content, PLAYER_DIRECTIONS))
		{
			found_wall_hit = TRUE;
			break ;
		}
		else{
			next_touch_x += x_step;
			next_touch_y += y_step;
		}
	}
	ray->wallHitX = 0;
	ray->wallHitY = 0;
	ray->distance = 0;
	ray->wasHitVertical = FALSE;
	if (found_wall_hit)
	{
		ray->wallHitX = next_touch_x;
		ray->wallHitY = next_touch_y;
		ray->distance = distance_between_points(
							player->x,
							player->y,
							next_touch_x,
							next_touch_y
						);
		ray->wasHitVertical = TRUE;
	}
	else
	{
		ray->distance = __INT_MAX__;
	}
}

double	ray_calc(t_config *config, t_ray *ray)
{
	t_player	*player;
	t_ray		horz_hit;
	t_ray		vert_hit;

	ray->is_fdown = ray->angle > 0 && ray->angle < PI;
	ray->is_fup = !ray->is_fdown;

	ray->is_fright = ray->angle < 0.5 * PI || ray->angle > 1.5 * PI;
	ray->is_fleft = !ray->is_fright;

	horz_hit.angle = ray->angle;
	horz_hit.is_fdown = ray->is_fdown;
	horz_hit.is_fup = ray->is_fup;
	horz_hit.is_fleft = ray->is_fleft;
	horz_hit.is_fright = ray->is_fright;

	vert_hit.angle = ray->angle;
	vert_hit.is_fdown = ray->is_fdown;
	vert_hit.is_fup = ray->is_fup;
	vert_hit.is_fleft = ray->is_fleft;
	vert_hit.is_fright = ray->is_fright;

	find_horizontal_distance(config, &horz_hit);
	find_vertical_distance(config, &vert_hit);

	if (vert_hit.distance < horz_hit.distance)
	{
		ray->wallHitX = vert_hit.wallHitX;
		ray->wallHitY = vert_hit.wallHitY;
		ray->distance = vert_hit.distance;
		ray->wasHitVertical = TRUE;
	}
	else
	{
		ray->wallHitX = horz_hit.wallHitX;
		ray->wallHitY = horz_hit.wallHitY;
		ray->distance = horz_hit.distance;
		ray->wasHitVertical = FALSE;	
	}
	printf("up: %d | down: %d | left: %d | right: %d\n",
		ray->is_fup,
		ray->is_fdown,
		ray->is_fleft,
		ray->is_fright
	);
	printf("ray_angle: %f | player_angle: %f\n", ray->angle, config->player.rotation_angle);
	printf("hit_y: %f | hit_x: %f\n", ray->wallHitY, ray->wallHitX);
	// printf("angle %f\n", ray->angle);
	// printf("hit_x: %f | hit_y: %f\n", ray->wallHitX, ray->wallHitY);
	// render_line2(config,
	// 	MINIMAP_SCALE_FACTOR * (TILE_SIZE * config->player.x),
	// 	MINIMAP_SCALE_FACTOR * (TILE_SIZE * config->player.y),
	// 	// MINIMAP_SCALE_FACTOR * (TILE_SIZE * config->player.x) + cos(angle) * 50,
	// 	// MINIMAP_SCALE_FACTOR * (TILE_SIZE * config->player.y) + sin(angle) * 50,
	// 	MINIMAP_SCALE_FACTOR * (TILE_SIZE * ray->wallHitX),
	// 	MINIMAP_SCALE_FACTOR * (TILE_SIZE * ray->wallHitY),
	// 	RED_PIXEL
	// );
	return(0);
}

double	render_line2(t_config *config, int beginX, int beginY, int endX, int endY, int color)
{
	double deltaX = endX - beginX;
	double deltaY = endY - beginY;

	int pixels = sqrt((deltaX * deltaX) + (deltaY * deltaY));

	deltaX /= pixels;
	deltaY /= pixels;

	double pixelX = beginX;
	double pixelY = beginY;
	while (pixels)
	{
		img_pix_put(&config->img,
			pixelX, pixelY, color);
		pixelX += deltaX;
		pixelY += deltaY;
		--pixels;
	}
}


char	get_map_at(char **map, double next_touch_x, double next_touch_y)
{
	int	x;
	int	y;

	if (next_touch_x < 0 || next_touch_x > WINDOW_WIDTH
		|| next_touch_y < 0 || next_touch_y > WINDOW_HEIGHT)
		return (0);
	// printf("next_y: %f next_x: %f\n", next_touch_y, next_touch_x);
	x = (int)floor(next_touch_x / TILE_SIZE);
	y = (int)floor(next_touch_y / TILE_SIZE);
	// printf("y: %d x: %d\n", y, x);
	return (map[(int)floor(y)][(int)floor(x)]);
}
