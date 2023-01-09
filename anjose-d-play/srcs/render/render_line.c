/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 19:47:33 by anjose-d          #+#    #+#             */
/*   Updated: 2023/01/09 16:45:01 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
