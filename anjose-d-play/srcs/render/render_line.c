/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 19:47:33 by anjose-d          #+#    #+#             */
/*   Updated: 2023/01/07 19:08:50 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		render_line(t_config *config, float x1, float y1, float x2, float y2, int color)
{
	float deltaX = x2 - x1;
	float deltaY = y2 - y1;

	int pixels = sqrt((deltaX * deltaX) + (deltaY * deltaY));

	deltaX = deltaX / pixels;
	deltaY = deltaY / pixels;

	float pixelX = x1;
	float pixelY = y1;

	while (pixels)
	{
		// if (config->map[(int)(pixelY / TILE_SIZE / MINIMAP_SCALE_FACTOR )][(int)(pixelX / TILE_SIZE / MINIMAP_SCALE_FACTOR)] == '1')
		// 	return (distance_between_points(x1, y1, pixelX, pixelY));
		if (pixelX < 0 || pixelY < 0)
			return (1);
		img_pix_put(config, pixelX, pixelY, color);
		pixelX += deltaX;
		pixelY += deltaY;
		pixels--;
	}
	return (0);
}
