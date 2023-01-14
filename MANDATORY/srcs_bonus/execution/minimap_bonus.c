/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 19:40:20 by anjose-d          #+#    #+#             */
/*   Updated: 2023/01/14 20:22:30 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int		this_point_is_in_a_circle(int i, int j, int x_position, int y_position, int radius);
void	render_map(t_config *config, int map_y, int map_x, int pixel_i, int pixel_j);

void    minimap(t_config *config)
{
    int pixel_i = 0;
    int pixel_j = 0;
    int map_y = 0;
    int map_x = 0;
	double ray_range = (WINDOW_WIDTH + WINDOW_HEIGHT) * 1.5;

    while(map_y < config->map_num_rows)
    {
        while(map_x < config->map_num_cols)
        {
            if(pixel_i % (TILE_SIZE) == 0 && pixel_i != 0)
                map_x++;
            if (map_x < config->map_num_cols)
                render_map(config, map_y, map_x, config->scale * pixel_i, config->scale * pixel_j);
            if(this_point_is_in_a_circle(pixel_i, pixel_j, config->player.x * TILE_SIZE, config->player.y * TILE_SIZE, 10))
                img_pix_put(&config->img, config->scale * pixel_i, config->scale * pixel_j, YELLOW_PIXEL);
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
        render_line_minimap(config,
            config->scale * ((config->player.x * TILE_SIZE) + cos(angle) * (ray_range / config->scale)),
            config->scale * ((config->player.y * TILE_SIZE) + sin(angle) * (ray_range / config->scale))
        );
        angle += (FOV / WINDOW_WIDTH) * 32;
        i += 32;
    }
}

int    this_point_is_in_a_circle(int i, int j, int x_position, int y_position, int radius)
{
    if(((i - x_position) * (i - x_position)) + ((j - y_position) * (j - y_position)) < (radius * radius))
        return 1;
    return 0; 
}

void	render_map(t_config *config, int map_y, int map_x, int pixel_i, int pixel_j)
{
	if (config->map[map_y][map_x] == '1')
		img_pix_put(&config->img, pixel_i, pixel_j, WHITE_PIXEL);
	else
		img_pix_put(&config->img, pixel_i, pixel_j, BLACK_PIXEL);
}
