/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaulino <rpaulino@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 19:47:33 by anjose-d          #+#    #+#             */
/*   Updated: 2023/01/04 23:09:25 by rpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	distance_between_points(double x1, double y1, double x2, double y2);

int		render_line(t_config *config, double x1, double y1, double x2, double y2, int color, int c)
{
	double deltaX = x2 - x1;
	double deltaY = y2 - y1;

	int pixels = sqrt((deltaX * deltaX) + (deltaY * deltaY));

	deltaX = deltaX / pixels;
	deltaY = deltaY / pixels;

	double pixelX = x1;
	double pixelY = y1;
	while (pixels)
	{
		if (config->map[(int)(pixelY / TILE_SIZE / MINIMAP_SCALE_FACTOR )][(int)(pixelX / TILE_SIZE / MINIMAP_SCALE_FACTOR)] == '1')
			return (distance_between_points(x1, y1, pixelX, pixelY));
		if (c == 1)
		img_pix_put(&config->img, pixelX, pixelY, color);
		pixelX += deltaX;
		pixelY += deltaY;
		--pixels;
	}
	return (0);
}

double	distance_between_points(double x1, double y1, double x2, double y2)
{
	double	distance;

	distance = sqrt(((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1)));
	return (distance);
}