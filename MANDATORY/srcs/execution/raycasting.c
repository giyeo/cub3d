/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaulino <rpaulino@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 07:29:17 by rpaulino          #+#    #+#             */
/*   Updated: 2023/01/12 07:29:17 by rpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		get_color_from_texture(t_config *config, double wall_strip, int x_hit,
			int *y_wall);
void	paint_wall(t_config *config, int x, double wall_strip, int x_hit);
int		ray_cast(t_config *config, double angle);
int		*find_wall_texture(t_config *config);

void	raycaster(t_config *config)
{
	double	fov;
	double	distances;
	double	wall_strip;
	double	angle;
	int		x;

	x = 0;
	fov = config->fov * (PI / 180);
	angle = normalize_angle(config->player.rotation_angle - (fov / 2.0));
	while (x < WINDOW_WIDTH)
	{
		distances = ray_cast(config, angle);
		distances *= cos(angle - config->player.rotation_angle);
		angle += normalize_angle((fov / WINDOW_WIDTH));
		wall_strip = (TILE_SIZE / distances)
			* (WINDOW_WIDTH / 2)
			/ tan(fov / 2);
		if (config->texture_col[1] == 0 || config->texture_col[1] == 63)
			paint_wall(config, x++, wall_strip, config->texture_col[0]);
		else
			paint_wall(config, x++, wall_strip, config->texture_col[1]);
	}
}

int	ray_cast(t_config *config, double angle)
{
	double	ray_range;

	ray_range = (WINDOW_WIDTH + WINDOW_HEIGHT) * 1.5;
	return (render_line(config,
			((config->player.x * TILE_SIZE) + cos(angle) * (ray_range)),
			((config->player.y * TILE_SIZE) + sin(angle) * (ray_range))));
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
				mlx_get_hex_trgb(config->c[0], config->c[1], config->c[2]));
		else if (y < y_end_wall)
			img_pix_put(&config->img, x, y,
				get_color_from_texture(config, wall_strip, x_hit, &y_wall));
		else
			img_pix_put(&config->img, x, y,
				mlx_get_hex_trgb(config->f[0], config->f[1], config->f[2]));
		y++;
	}
}

int	get_color_from_texture(t_config *config, double wall_strip, int x, int *y)
{
	double	offset;
	int		is_over_screen;
	int		column;
	int		line;
	int		*texture;

	is_over_screen = 0;
	if (wall_strip > WINDOW_HEIGHT)
		is_over_screen = 1;
	offset = ((wall_strip - WINDOW_HEIGHT) / 2.0) * is_over_screen + *y;
	column = x % 64;
	line = (int)(offset / wall_strip * 64);
	*y += 1;
	texture = find_wall_texture(config);
	return (*(texture + column + line * 64));
}

int	*find_wall_texture(t_config *config)
{
	if (config->side[1] == 1)
		return (config->textures.no);
	else if (config->side[1] == -1)
		return (config->textures.so);
	else if (config->side[0] == 1)
		return (config->textures.we);
	else if (config->side[0] == -1)
		return (config->textures.ea);
	return (0);
}
