/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaulino <rpaulino@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 19:47:33 by anjose-d          #+#    #+#             */
/*   Updated: 2023/01/13 22:37:43 by rpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	distance_between_points(double x1, double y1, double x2, double y2);
double	find_distance(t_config *config, t_render_line *values, int pixels);
void	optimize(t_render_line *values);

double	render_line(t_config *config, double x2, double y2)
{
	t_render_line	values;
	int				pixels;

	values.player_x = (config->player.x * TILE_SIZE);
	values.player_y = (config->player.y * TILE_SIZE);
	values.deltaX = x2 - values.player_x;
	values.deltaY = y2 - values.player_y;
	pixels = sqrt((values.deltaX * values.deltaX)
			+ (values.deltaY * values.deltaY));
	values.deltaX = values.deltaX / pixels;
	values.deltaY = values.deltaY / pixels;
	values.pixelX = values.player_x;
	values.pixelY = values.player_y;
	values.posX = values.pixelX / TILE_SIZE;
	values.posY = values.pixelY / TILE_SIZE;
	return (find_distance(config, &values, pixels * 2));
}

double	find_distance(t_config *config, t_render_line *values, int pixels)
{
	while (pixels)
	{
		values->posX_old = values->posX;
		values->posY_old = values->posY;
		values->posX = (values->pixelX / TILE_SIZE);
		values->posY = (values->pixelY / TILE_SIZE);
		if (config->map[values->posY][values->posX] == '1')
		{
			config->texture_col[0] = (int)((int)values->pixelX % 64);
			config->texture_col[1] = (int)((int)values->pixelY % 64);
			config->side[0] = (values->posX_old - values->posX);
			config->side[1] = (values->posY_old - values->posY);
			return (distance_between_points(
					values->player_x, values->player_y,
					values->pixelX, values->pixelY));
		}
		optimize(values);
		if (pixels % 2 == 0)
			values->pixelX += values->deltaX;
		else
			values->pixelY += values->deltaY;
		pixels--;
	}
}

void	optimize(t_render_line *values)
{
	if ((values->posX_old != values->posX || values->posY_old != values->posY)
		&& (values->posX == (int)((values->pixelX + values->deltaX * 63)
			/ TILE_SIZE))
		&& (values->posY ==
			(int)((values->pixelY + values->deltaY * 63)
			/ TILE_SIZE)))
	{
		values->pixelX += values->deltaX * 63;
		values->pixelY += values->deltaY * 63;
	}
}

double	distance_between_points(double x1, double y1, double x2, double y2)
{
	double	distance;

	distance = sqrt(((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1)));
	return (distance);
}
