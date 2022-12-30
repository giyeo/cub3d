/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 01:20:32 by anjose-d          #+#    #+#             */
/*   Updated: 2022/12/29 17:54:07 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define RED_PIXEL 0xFF0000
#define GREEN_PIXEL 0xFF00
#define WHITE_PIXEL 0xFFFFFF

int		render_background(t_config *config, int color, t_img *img);

void	render_map(t_config *config)
{
	char **map;
	int	i;
	int	j;

	map = config->map;

	if (config->conn_mlx.win_ptr != NULL)
	{
		render_background(config, 0x0, &config->img);
		i = 0;
		while (config->map[i])
		{
			j = 0;
			while (config->map[i][j])
			{
				int	tileX = j * IMG_SIZE;
				int	tileY = i * IMG_SIZE;
				int	tileColor = map[i][j] != 0 ? 255 : 0;

				if (config->map[i][j] == '1')
				render_rect(config->conn_mlx,
					tileX,
					tileY,
					IMG_SIZE,
					IMG_SIZE,
					WHITE_PIXEL,
					&config->img
				);
				j++;
			}
			i++;
		}
	}
}

int	render_background(t_config *config, int color, t_img *img)
{
	int	i;
	int	j;

	if (config->conn_mlx.win_ptr == NULL)
		return (1);
	i = 0;
	while (i < config->window_height)
	{
		j = 0;
		while (j < config->window_width)
		{
			img_pix_put(img, j, i, color);
			j++;
		}
		i++;
	}
	return (0);
}


