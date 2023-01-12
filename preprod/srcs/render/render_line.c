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
	int iterator = pixels * 2;
	while (iterator)
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
		if(iterator % 2 == 0)
			pixelX += deltaX;
		else
			pixelY += deltaY;
		iterator--;
	}
	return (0);
}

double	distance_between_points(double x1, double y1, double x2, double y2)
{
	double	distance;

	distance = sqrt(((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1)));
	return (distance);
}

double	render_line2(t_config *config, double player_x, double player_y, double angle)
{
	int is_ray_down;
	int is_ray_up;
	int is_ray_left;
	int is_ray_right;
	double y_intercept;
	double x_intercept;
	double y_step;
	double x_step;
	double next_horz_touch_x;
	double next_horz_touch_y;
	double distance;

	is_ray_down = 0;
	is_ray_up = 0;
	is_ray_left = 0;
	is_ray_right = 0;

	if(angle > 0 && angle < PI)
		is_ray_down = 1;
	else
		is_ray_up = 1;
	if(angle < 0.5 * PI || angle > 1.5 * PI)
		is_ray_right = 1;
	else
		is_ray_left = 1;
	
	y_intercept = floor(player_y / TILE_SIZE) * TILE_SIZE;
	y_intercept += is_ray_down ? TILE_SIZE : 0;

	x_intercept = player_x + (y_intercept - player_y) / tan(angle);

	y_step = TILE_SIZE;
	y_step *= is_ray_up ? -1 : 1;

	x_step = TILE_SIZE / tan(angle);
	x_step *= (is_ray_left && x_step > 0) ? -1 : 1;
	x_step *= (is_ray_right && x_step < 0) ? -1: 1;

	next_horz_touch_x = x_intercept;
	next_horz_touch_y = y_intercept;

	if(is_ray_up)
		next_horz_touch_y--;
	
	while(next_horz_touch_x >= 0 && next_horz_touch_x <= WINDOW_WIDTH
	&& next_horz_touch_y >= 0 &&  next_horz_touch_y <= WINDOW_HEIGHT)
	{
		if(config->map[(int)(next_horz_touch_y / TILE_SIZE)][(int)(next_horz_touch_x / TILE_SIZE)])
		{
			printf("x:%f, y:%f, dist: %f\n", next_horz_touch_x,
			next_horz_touch_y,
			distance_between_points(player_x,player_y, next_horz_touch_x, next_horz_touch_y));
			return(0);
		}
		next_horz_touch_x += x_step;
		next_horz_touch_y += y_step;
	}

}