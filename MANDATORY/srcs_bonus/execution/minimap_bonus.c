/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaulino <rpaulino@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 19:40:20 by anjose-d          #+#    #+#             */
/*   Updated: 2023/01/15 15:42:17 by rpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	this_point_is_in_a_circle(int i, int j, int x_position, int y_position)
{
	if (((i - x_position) * (i - x_position))
		+ ((j - y_position) * (j - y_position)) < (100))
		return (1);
	return (0);
}

void	render_map(t_config *config, t_minimap_iterators *iterator)
{
	if (config->map[iterator->map_y][iterator->map_x] == '1')
		img_pix_put(&config->img, config->scale * iterator->pixel_i,
			config->scale * iterator->pixel_j, WHITE_PIXEL);
	else
		img_pix_put(&config->img, config->scale * iterator->pixel_i,
			config->scale * iterator->pixel_j, BLACK_PIXEL);
}

void	render_minimap_background(t_config *config,
	t_minimap_iterators	*iterator)
{
	while (iterator->map_y < config->map_num_rows)
	{
		while (iterator->map_x < config->map_num_cols)
		{
			if (iterator->pixel_i % (TILE_SIZE) == 0 && iterator->pixel_i != 0)
				iterator->map_x++;
			if (iterator->map_x < config->map_num_cols)
				render_map(config, iterator);
			if (this_point_is_in_a_circle(iterator->pixel_i, iterator->pixel_j,
					config->player.x * TILE_SIZE,
					config->player.y * TILE_SIZE))
				img_pix_put(&config->img, config->scale * iterator->pixel_i,
					config->scale * iterator->pixel_j, YELLOW_PIXEL);
			iterator->pixel_i++;
		}
		iterator->map_x = 0;
		iterator->pixel_i = 0;
		iterator->pixel_j++;
		if (iterator->pixel_j % (TILE_SIZE) == 0)
			iterator->map_y++;
	}
}

void	cast_minimap_ray(t_config *config)
{
	double	ray_range;
	double	fov;
	double	angle;
	int		i;

	ray_range = (WINDOW_WIDTH + WINDOW_HEIGHT) * 1.5;
	fov = 60.0 * (PI / 180);
	angle = config->player.rotation_angle - (fov / 2.0);
	i = 0;
	while (i < WINDOW_WIDTH)
	{
		render_line_minimap(config,
			config->scale * ((config->player.x * TILE_SIZE)
				+ cos(angle) * (ray_range / config->scale)),
			config->scale * ((config->player.y * TILE_SIZE)
				+ sin(angle) * (ray_range / config->scale))
			);
		angle += (fov / WINDOW_WIDTH) * 32;
		i += 32;
	}
}

void	minimap(t_config *config)
{
	t_minimap_iterators	iterator;

	iterator.pixel_i = 0;
	iterator.pixel_j = 0;
	iterator.map_y = 0;
	iterator.map_x = 0;
	render_minimap_background(config, &iterator);
	cast_minimap_ray(config);
}
