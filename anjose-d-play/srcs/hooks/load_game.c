/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 01:12:15 by anjose-d          #+#    #+#             */
/*   Updated: 2023/01/03 17:41:41 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	this_point_is_in_a_circle(int i, int j, int x_position, int y_position, int radius);

int	load_game(t_config *config)
{
	int pixel_i = 0;
	int pixel_j = 0;
	int map_y = 0;
	int map_x = 0;

	float	backup_y = config->player.y;
	float	backup_x = config->player.x;
	if (config->player.walk_direction == 1)
	{
		config->player.y += 1 * 0.1;
	}
	else if (config->player.walk_direction == -1)
	{
		config->player.y -= 1 * 0.1;
	}
	//the collision detector should be here!
	while(map_y < config->map_num_rows)
	{
		while(map_x < config->map_num_cols)
		{
			//create horizontal grid lines
			if(pixel_i % (TILE_SIZE) == 0 && pixel_i != 0)
				map_x++;
			
			if (map_x < config->map_num_cols)
				render_map(config, map_y, map_x, pixel_i, pixel_j);

			// render player
			if(this_point_is_in_a_circle(pixel_i, pixel_j, config->player.x * TILE_SIZE, config->player.y * TILE_SIZE, 10))
			{
				// wall collision
				if (config->map[map_y][map_x] != '1')
					img_pix_put(&config->img, pixel_i, pixel_j, YELLOW_PIXEL);
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
			MINIMAP_SCALE_FACTOR * (config->player.x * TILE_SIZE) + cos(config->player.rotation_angle) * 20,
			MINIMAP_SCALE_FACTOR * (config->player.y * TILE_SIZE) + sin(config->player.rotation_angle) * 20,
			RED_PIXEL
		);
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
