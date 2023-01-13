/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaulino <rpaulino@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 19:47:33 by anjose-d          #+#    #+#             */
/*   Updated: 2023/01/13 19:19:20 by rpaulino         ###   ########.fr       */
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
	int posX = pixelX / TILE_SIZE;
	int posY = pixelY / TILE_SIZE;
	int iterator = pixels * 2;
	while (iterator)
	{
		int posX_old =  posX;
		int posY_old =  posY;
		posX = (pixelX / TILE_SIZE);
		posY = (pixelY / TILE_SIZE);
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
		
		int ite = 63;
		if((posX_old != posX || posY_old != posY)
			&& (posX == (int)((pixelX + deltaX * ite) / TILE_SIZE))
			&& (posY == (int)((pixelY + deltaY * ite) / TILE_SIZE)))
		{
			pixelX += deltaX * ite;
			pixelY += deltaY * ite;
		}
		
		if(iterator % 2 == 0)
			pixelX += deltaX;
		else
			pixelY += deltaY;
		iterator--;
		config->operations++;
	}
	return (0);
}

double	distance_between_points(double x1, double y1, double x2, double y2)
{
	double	distance;

	distance = sqrt(((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1)));
	return (distance);
}
