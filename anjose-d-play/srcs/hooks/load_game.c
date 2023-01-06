/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaulino <rpaulino@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 01:12:15 by anjose-d          #+#    #+#             */
/*   Updated: 2023/01/06 00:39:22 by rpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	this_point_is_in_a_circle(int i, int j, int x_position, int y_position, int radius);
void	update(t_config *config);

int    mlx_get_hex_trgb(int r, int g, int b)
{
    return ((r << 16) | (g << 8) | (b));
}

double	dg_to_rad(double dg)
{
	return (PI / 180 * dg);
}

static double    normalize_angle(double angle)
{
    angle = remainder(angle, TWO_PI);
    if (angle < 0)
        angle = TWO_PI + angle;
    return (angle);
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	find_color_wall(int side[2], double distances)
{
	int total_dist = WINDOW_WIDTH * 1.42;
	int color;
	//as vezes fica bugado com 1, -1  1, 1    -1 -1, para arrumar preciso do angulo dps faço
	if(side[1] == 1)//norte
		return mlx_get_hex_trgb(0, 0, 125 - (distances * 125 / total_dist));//azul
	else if(side[1] == -1 )//sul
		return mlx_get_hex_trgb(0, 255 - (distances * 254 / total_dist), 0);//green
	else if(side[0] == 1)//oeste
		return mlx_get_hex_trgb(255 - (distances * 254 / total_dist), 0, 0);//red
	else if(side[0] == -1)//leste white
		return mlx_get_hex_trgb(255 - (distances * 254 / total_dist), 255 - (distances * 254 / total_dist), 255 - (distances * 254 / total_dist));
}

int	load_game(t_config *config)
{
	int pixel_i = 0;
	int pixel_j = 0;
	int map_y = 0;
	int map_x = 0;

	double	backup_y = config->player.y;
	double	backup_x = config->player.x;

	update(config);
	while(map_y < config->map_num_rows)
	{
		while(map_x < config->map_num_cols)
		{
			if(pixel_i % (TILE_SIZE) == 0 && pixel_i != 0)
				map_x++;
			// if (map_x < config->map_num_cols)
			// 	render_map(config, map_y, map_x, MINIMAP_SCALE_FACTOR * pixel_i, MINIMAP_SCALE_FACTOR * pixel_j);
			if(this_point_is_in_a_circle(pixel_i, pixel_j, config->player.x * TILE_SIZE, config->player.y * TILE_SIZE, 10))
			{
				if (config->map[map_y][map_x] != '1')
					img_pix_put(&config->img, MINIMAP_SCALE_FACTOR * pixel_i, MINIMAP_SCALE_FACTOR * pixel_j, YELLOW_PIXEL);
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
	// int i = 0;
	// double FOV = 60.0 * (PI / 180);
	// double angle = config->player.rotation_angle - (FOV / 2.0);
	// while(i < WINDOW_WIDTH)
	// {
	// 	render_line(config,
	// 		MINIMAP_SCALE_FACTOR * (config->player.x * TILE_SIZE),
	// 		MINIMAP_SCALE_FACTOR * (config->player.y * TILE_SIZE),
	// 		MINIMAP_SCALE_FACTOR * ((config->player.x * TILE_SIZE) + cos(angle) * (RAY_RANGE / MINIMAP_SCALE_FACTOR)),
	// 		MINIMAP_SCALE_FACTOR * ((config->player.y * TILE_SIZE) + sin(angle) * (RAY_RANGE / MINIMAP_SCALE_FACTOR)),
	// 		create_trgb(1, 255, 0, 0),
	// 		1
	// 	);
	// 	angle += (FOV / WINDOW_WIDTH);
	// 	i++;
	// }
		
	double FOV = 60.0 * (PI / 180);

	double distances;
	double angle = normalize_angle(config->player.rotation_angle - (FOV / 2.0));
	double wallstrip;
	int y = 0;
	int x = 0;
	int offsize = 0;
	while(x < WINDOW_WIDTH) //pegar angulo e ver em qual parte do circulo trig ele fica.
	{
		if(x % 1 == 0)
		{
			distances =
			render_line(config,
				MINIMAP_SCALE_FACTOR * (config->player.x * TILE_SIZE),
				MINIMAP_SCALE_FACTOR * (config->player.y * TILE_SIZE),
				MINIMAP_SCALE_FACTOR * ((config->player.x * TILE_SIZE) + cos(angle) * (RAY_RANGE / MINIMAP_SCALE_FACTOR)),
				MINIMAP_SCALE_FACTOR * ((config->player.y * TILE_SIZE) + sin(angle) * (RAY_RANGE / MINIMAP_SCALE_FACTOR)),
				create_trgb(1, 0, 0, 0),
				0
			);
		}
		angle += normalize_angle((FOV / WINDOW_WIDTH));
		//fix fishball effect
		distances = distances * cos(angle - config->player.rotation_angle);
		wallstrip = (TILE_SIZE / distances) * ((WINDOW_WIDTH / 2) / tan(FOV / 2)) * MINIMAP_SCALE_FACTOR;
		//wallstrip = wallstrip * cos(angle);
		int colorwall = BLACK_PIXEL;
		if (x != (WINDOW_WIDTH / 2))
			colorwall = find_color_wall(config->side, distances);
		
		while(y < WINDOW_HEIGHT)
		{
			offsize = (WINDOW_HEIGHT - wallstrip) / 2.0;
			if(x == WINDOW_WIDTH / 2 && y == WINDOW_HEIGHT / 2)
				printf("#ANGLE:%f @SIDE:[%d,%d]\n", angle, config->side[0], config->side[1] );
			//if(y < (int)(WINDOW_HEIGHT * MINIMAP_SCALE_FACTOR) && x < (int)(WINDOW_WIDTH * MINIMAP_SCALE_FACTOR));
			if(offsize <= 0)
				img_pix_put(&config->img, x, y, colorwall);
			else if(y < offsize)
				img_pix_put(&config->img, x, y, mlx_get_hex_trgb(50, 50, 50));
			else if(y < offsize + wallstrip)
				img_pix_put(&config->img, x, y, colorwall);
			else
				img_pix_put(&config->img, x, y, mlx_get_hex_trgb(150, 150, 150));
			y++;
		}
		y = 0;
		x++;
	}
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
	double	new_x;
	double	new_y;
	double	move_step;
	t_player	*player;

	player = &config->player;
	player->rotation_angle += player->turn_direction * player->turn_speed;

	move_step = player->walk_direction * config->player.walk_speed;

	new_x = player->x + cos(player->rotation_angle) * move_step;
	new_y = player->y + sin(player->rotation_angle) * move_step;

	player->x = new_x;
	player->y = new_y;
}
