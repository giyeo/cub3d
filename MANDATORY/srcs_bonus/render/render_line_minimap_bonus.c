/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_line_minimap_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaulino <rpaulino@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 19:47:33 by anjose-d          #+#    #+#             */
/*   Updated: 2023/01/15 15:38:24 by rpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

double	distance_between_points(double x1, double y1, double x2, double y2);
void	optimize(t_render_line *values);

static double	find_distance(t_config *config,
	t_render_line *values, int pixels)
{
	while (pixels)
	{
		values->pos_x_old = values->pos_x;
		values->pos_y_old = values->pos_y;
		values->pos_x = (values->pixel_x / TILE_SIZE / config->scale);
		values->pos_y = (values->pixel_y / TILE_SIZE / config->scale);
		if (config->map[values->pos_y][values->pos_x] == '1')
		{
			config->texture_col[0] = (int)((int)values->pixel_x % 64);
			config->texture_col[1] = (int)((int)values->pixel_y % 64);
			config->side[0] = (values->pos_x_old - values->pos_x);
			config->side[1] = (values->pos_y_old - values->pos_y);
			return (distance_between_points(
					values->player_x, values->player_y,
					values->pixel_x, values->pixel_y));
		}
		img_pix_put(&config->img, values->pixel_x, values->pixel_y, RED_PIXEL);
		optimize(values);
		if (pixels % 2 == 0)
			values->pixel_x += values->delta_x;
		else
			values->pixel_y += values->delta_y;
		pixels--;
	}
	return (0);
}

double	render_line_minimap(t_config *config, double x2, double y2)
{
	t_render_line	values;
	int				pixels;

	values.player_x = (config->player.x * TILE_SIZE * config->scale);
	values.player_y = (config->player.y * TILE_SIZE * config->scale);
	values.delta_x = x2 - values.player_x;
	values.delta_y = y2 - values.player_y;
	pixels = sqrt((values.delta_x * values.delta_x)
			+ (values.delta_y * values.delta_y));
	values.delta_x = values.delta_x / pixels;
	values.delta_y = values.delta_y / pixels;
	values.pixel_x = values.player_x;
	values.pixel_y = values.player_y;
	values.pos_x = values.pixel_x / TILE_SIZE / config->scale;
	values.pos_y = values.pixel_y / TILE_SIZE / config->scale;
	return (find_distance(config, &values, pixels * 2));
}
