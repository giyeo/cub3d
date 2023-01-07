/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 01:12:15 by anjose-d          #+#    #+#             */
/*   Updated: 2023/01/07 19:15:44 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	this_point_is_in_a_circle(int i, int j, int x_position, int y_position, int radius);
void	update(t_config *config);
float	normalize_angle(float angle)
{
	angle = remainder(angle, TWO_PI);
	if (angle < 0)
		angle = TWO_PI + angle;
	return angle;
}

int    mlx_get_hex_trgb(int r, int g, int b)
{
    return ((r << 16) | (g << 8) | (b));
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	raycast_calc(t_config *config, int i);

int	load_game(t_config *config)
{
	int pixel_i = 0;
	int pixel_j = 0;
	int map_y = 0;
	int map_x = 0;

	float	backup_y = config->player.y;
	float	backup_x = config->player.x;

	update(config);
	//the collision detector should be here!
	while(map_y < config->map_num_rows)
	{
		while(map_x < config->map_num_cols)
		{
			//create horizontal grid lines
			if(pixel_i % (TILE_SIZE) == 0 && pixel_i != 0)
				map_x++;
			
			if (map_x < config->map_num_cols)
				render_map(
					config,
					map_y,
					map_x,
					MINIMAP_SCALE_FACTOR * pixel_i,
					MINIMAP_SCALE_FACTOR * pixel_j);

			// render player
			if(this_point_is_in_a_circle(pixel_i, pixel_j, config->player.x * TILE_SIZE, config->player.y * TILE_SIZE, 10))
			{
				// wall collision
				if (config->map[map_y][map_x] != '1')
					img_pix_put(config,
						MINIMAP_SCALE_FACTOR * pixel_i,
						MINIMAP_SCALE_FACTOR * pixel_j,
						YELLOW_PIXEL
					);
				else
				{
					config->player.x = backup_x;
					config->player.y = backup_y;
				}
			}
			pixel_i++;
		}
		map_x = 0;
		pixel_i = 0;
		pixel_j++;
		if(pixel_j % (TILE_SIZE) == 0)
			map_y++;
	}
	
	render_line(config,
			MINIMAP_SCALE_FACTOR * (config->player.x * TILE_SIZE),
			MINIMAP_SCALE_FACTOR * (config->player.y * TILE_SIZE),
			MINIMAP_SCALE_FACTOR * (config->player.x * TILE_SIZE + cos(config->player.rotation_angle) * 50),
			MINIMAP_SCALE_FACTOR * (config->player.y * TILE_SIZE + sin(config->player.rotation_angle) * 50),
			RED_PIXEL
		);
	
	//cast_all_rays
	int i = 0;
	// start first ray subtracting half of the FOV
	float	ray_angle = config->player.rotation_angle - (config->player.fov / 2);
	while (i < 1)
	{
		config->rays[i].angle = normalize_angle(ray_angle);
		// CAST A RAY
		raycast_calc(config, i);
		render_line(config,
			MINIMAP_SCALE_FACTOR * (config->player.x * TILE_SIZE),
			MINIMAP_SCALE_FACTOR * (config->player.y * TILE_SIZE),
			MINIMAP_SCALE_FACTOR * (config->rays[i].wall_hit_x * TILE_SIZE),
			MINIMAP_SCALE_FACTOR * (config->rays[i].wall_hit_y * TILE_SIZE),
			// MINIMAP_SCALE_FACTOR * (config->player.x * TILE_SIZE + cos(config->rays[i].angle) * 50),
			// MINIMAP_SCALE_FACTOR * (config->player.y * TILE_SIZE + sin(config->rays[i].angle) * 50),
			RED_PIXEL
		);
		
		// trace the ray until it intersects with a wall
		// record the intersection (x, y) and the distance (ray length)
		// add the angle increment so the ray moves to the right (rayAngle += 60(convert_radians)/320 == FOV / NUM_RAYS)
		ray_angle += config->player.fov / config->num_rays;
		i++;
	}
	
	// float FOV = 60.0 * (PI / 180);

	// float distance;
	// // float wallstrip;
	// float angle = config->player.rotation_angle - (FOV / 2.0);
	// int	ray_range;

	// ray_range = config->window_width;
	// int	i = 0;
	// while (i < config->num_rays) // num_rays
	// {
	// 	distance =
	// 	render_line(config,
	// 		MINIMAP_SCALE_FACTOR * (config->player.x * TILE_SIZE),
	// 		MINIMAP_SCALE_FACTOR * (config->player.y * TILE_SIZE),
	// 		MINIMAP_SCALE_FACTOR * ((config->player.x * TILE_SIZE) + cos(angle) * (ray_range / MINIMAP_SCALE_FACTOR)),
	// 		MINIMAP_SCALE_FACTOR * ((config->player.y * TILE_SIZE) + sin(angle) * (ray_range / MINIMAP_SCALE_FACTOR)),
	// 		create_trgb(1, 128, 0, 0)
	// 	);
	// 	i++;
	// 	angle += (FOV / config->window_width);
	// }
	
	mlx_put_image_to_window(config->conn_mlx.mlx_ptr,
		config->conn_mlx.win_ptr,
		config->img.mlx_img, 0, 0
	);
	return (0);
}

int	this_point_is_in_a_circle(int i, int j, int x_position, int y_position, int radius)
{
	if(((i - x_position) * (i - x_position)) + ((j - y_position) * (j - y_position)) < (radius * radius))
		return 1;
	return 0; 
}

void	update(t_config *config)
{
	float	new_x;
	float	new_y;
	float	move_step;
	t_player	*player;

	player = &config->player;
	player->rotation_angle += player->turn_direction * player->turn_speed;

	move_step = player->walk_direction * config->player.walk_speed;

	new_x = player->x + cos(player->rotation_angle) * move_step;
	new_y = player->y + sin(player->rotation_angle) * move_step;

	player->x = new_x;
	player->y = new_y;
}

void	raycast_calc(t_config *config, int i)
{
	t_player	*player;
	t_ray		*ray;
	float	xintercept, yintercept;
	float	xstep, ystep;
	int		foundHorzWallHit = FALSE;
	float	horzWallHitX = 0;
	float 	horzwallHitY = 0;
	
	ray = &config->rays[i];
	player = &config->player; 
	ray->is_fdown = ray->angle > 0 && ray->angle < PI;
	ray->is_fup = !ray->is_fdown;
	ray->is_fleft = ray->angle > PI * 0.5 && ray->angle < PI * 1.5;
	ray->is_fright = !ray->is_fleft;

	
	// horizontal distance hit checking
		
		//find coordinates of the intersection (x and y of A)
		// find the y-coordinate of the closest horizontal grid intersection
		yintercept = floor(player->y / TILE_SIZE) * TILE_SIZE;
		// compensation depending where the ray is facing
		yintercept += ray->is_fdown ? TILE_SIZE : 0;
		// if (ray->is_fdown)
		// 	yintercept += TILE_SIZE;
		
		// find the x-coordinate of the closest horizontal grid intersection
		xintercept = player->x + ((yintercept - player->y) / tan(ray->angle)); // pq a subtração não é ao contrario?
		
		// find ystep and xstep (coordinates of every intersection) | delta distance between intersections;
		ystep = TILE_SIZE;
		if (ray->is_fup)
			ystep *= -1;
		xstep = TILE_SIZE / tan(ray->angle);
		xstep *= ray->is_fleft && xstep > 0 ? -1 : 0;
		xstep *= ray->is_fright && xstep < 0 ? -1 : 0;
		// if (ray->is_fleft && xstep > 0)
		// 	xstep *= -1;
		// if (ray->is_fright && xstep < 0)
		// 	xstep *= -1;
		
		// if (ray->is_fup)
		// {
		// 	if (ray->is_fright) {/* +xstep */}
		// 	else {/* -xstep */}
		// }
		// else
		// {
		// 	if (ray->is_fright) {/* +xstep */}
		// 	else {/* -xstep */}
		// }
	
		// convert intersection point (x,y) into map_index[i,j]
		float	nextHorzTouchX = xintercept;
		float	nextHorzTouchY = yintercept;

		// if (ray->is_fup)
		// 	nextHorzTouchY--;
		while (nextHorzTouchX >= 0 && nextHorzTouchX < config->window_width
			&& nextHorzTouchY >= 0 && nextHorzTouchY < config->window_height)
		{
		// there is a wall?
			int decrement = 0;
			if (ray->is_fup)
				decrement = 1;
			if (map_has_wall_at(config, nextHorzTouchX, nextHorzTouchY - (ray->is_fup ? 1 : 0)))
				//config->map[ (int)floor(nextHorzTouchY / TILE_SIZE) ][(int)floor(nextHorzTouchX / TILE_SIZE)] == '1')
			{
				foundHorzWallHit = TRUE;
				// store horizontal hit distance
				horzWallHitX = nextHorzTouchX;
				horzwallHitY = nextHorzTouchY;
				// stop
				break ;
			}
				// else
			else
			{
			// find next horizontal intersection
				nextHorzTouchX += xstep;
				nextHorzTouchY += ystep;
			}
		}
	// vertical distance hit checking
	int	foundVertWallHit = FALSE;
	float	vertWallHitX = 0;
	float	vertWallHitY = 0;
	
	xintercept = floor(player->x / TILE_SIZE) * TILE_SIZE;
	xintercept += ray->is_fright ? TILE_SIZE : 0;

	yintercept = player->y + (xintercept - player->x) * tan(ray->angle);


	xstep = TILE_SIZE;
	xstep *= ray->is_fleft ? -1 : 1;
	
	ystep = TILE_SIZE * tan(ray->angle);
	ystep *= (ray->is_fup && ystep > 0) ? -1 : 1;
	ystep *= (ray->is_fdown && ystep < 0) ? -1 : 1;

	float	nextVertTouchX = xintercept;
	float	nextVertTouchY = yintercept;

	while (nextVertTouchX >= 0 && nextVertTouchX <= config->window_width
		&& nextVertTouchY >= 0 && nextVertTouchY <= config->window_height)
	{
		// there is a wall?
		if (map_has_wall_at(config, nextVertTouchX, nextVertTouchY))
		{
			foundVertWallHit = TRUE;
			vertWallHitX = nextVertTouchX;
			vertWallHitY = nextVertTouchY;
		 	// stops
			break ;
		}
		else
		{
			nextVertTouchX += xstep;
			nextVertTouchY += ystep;
		}
	}

	float horzHitDistance = (foundHorzWallHit)
		? distance_between_points(player->x, player->y, horzWallHitX, horzwallHitY) 
		: __INT_MAX__;
	float vertHitDistance = (foundVertWallHit)
		? distance_between_points(player->x, player->y, vertWallHitX, vertWallHitY)
		: __INT_MAX__;
	
	ray->wall_hit_x = (horzHitDistance < vertHitDistance) ? horzWallHitX : vertWallHitX;
	ray->wall_hit_y = (horzHitDistance < vertHitDistance) ? horzwallHitY : vertWallHitY;
	ray->distance = (horzHitDistance < vertHitDistance) ? horzHitDistance : vertHitDistance;
	
	// compare both
	// choose the closest one
	
	
}