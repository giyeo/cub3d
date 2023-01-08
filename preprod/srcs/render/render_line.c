/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaulino <rpaulino@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 19:47:33 by anjose-d          #+#    #+#             */
/*   Updated: 2023/01/06 00:12:40 by rpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	distance_between_points(double x1, double y1, double x2, double y2);

double render_line(t_config *config, double x1, double y1, double x2, double y2, int color, int c)
{
	double deltaX = x2 - x1;
	double deltaY = y2 - y1;
	
	int pixels = sqrt((deltaX * deltaX) + (deltaY * deltaY));

	deltaX = deltaX / pixels;
	deltaY = deltaY / pixels;

	double pixelX = x1;
	double pixelY = y1;
	int posX = pixelX / TILE_SIZE / MINIMAP_SCALE_FACTOR;
	int posY = pixelY / TILE_SIZE / MINIMAP_SCALE_FACTOR;
	while (pixels)
	{
		int posX_old =  posX;
		int posY_old =  posY;
		posX = (pixelX / TILE_SIZE / MINIMAP_SCALE_FACTOR);
		posY = (pixelY / TILE_SIZE / MINIMAP_SCALE_FACTOR);
		if((posX != posX_old || posY != posY_old) && config->player.interact &&
		config->player.is_middle)
		{
			config->player.interact = 0;
			config->map[posY][posX] = '1';
		}
		if (config->map[posY][posX] == '1')
		{
			config->texture_col[0] = (int)((int)pixelX % 64);
			config->texture_col[1] = (int)((int)pixelY % 64);
			config->side[0] = (posX_old - posX);
			config->side[1] = (posY_old - posY);
			return (distance_between_points(x1, y1, pixelX, pixelY));
		}
		if (c == 1)
			img_pix_put(&config->img, pixelX, pixelY, color);
		pixelX += deltaX;
		pixelY += deltaY;
		pixels--;
	}
	return (0);
}

double	distance_between_points(double x1, double y1, double x2, double y2)
{
	double	distance;

	distance = sqrt(((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1)));
	return (distance);
}

// double	find_horizontal_intersection(double px, double py, double angle)
// {
// 	double y_intercept;
// 	double x_intercept;
// 	double y_step;
// 	double x_step;

// 	y_intercept = floor(py / TILE_SIZE) * TILE_SIZE;
// 	x_intercept = px + ((py - y_intercept) / tan(angle));

// 	y_step = TILE_SIZE;
// 	x_step = y_step / tan(angle);

// 	while(1)
// 	{
// 		if (config->map[(int)y_intercept][(int)x_intercept] == '1')
// 			return(distance_between_points(px, py, x_intercept, y_intercept));
// 		y_intercept += y_step;
// 		x_intercept += x_step;
// 	}
// }

// double	find_vertical_intersection(double px, double py, double angle)
// {
// 	double y_intercept;
// 	double x_intercept;
// 	double y_step;
// 	double x_step;

// 	y_intercept = floor(py / TILE_SIZE) * TILE_SIZE;
// 	x_intercept = px + ((py - y_intercept) / tan(angle));

// 	x_step = TILE_SIZE;
// 	y_step = TILE_SIZE * tan(angle);

// 	while(1)
// 	{
// 		if (config->map[(int)y_intercept][(int)x_intercept] == '1')
// 			return(distance_between_points(px, py, x_intercept, y_intercept));
// 		y_intercept += y_step;
// 		x_intercept += x_step;
// 	}
// }

// double	render_line2(t_config *config, double px, double py, double angle)
// {
// 	double horizontal_intersect = find_horizontal_intersection(px, py, angle);
// 	double vertical_intersect = find_vertical_intersection(px, py, angle);

// 	if(horizontal_intersect < vertical_intersect)
// 		return (horizontal_intersect);
// 	return(vertical_intersect);
// }