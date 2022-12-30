/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 01:20:32 by anjose-d          #+#    #+#             */
/*   Updated: 2022/12/30 12:41:13 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_map(t_config *config)
{
	char **map;
	int	i;
	int	j;

	map = config->map;

	if (config->conn_mlx.win_ptr != NULL)
	{
		i = 0;
		while (i < config->map[i])
		{
			j = 0;
			while (config->map[i][j]) 
			{
				int	tileX = j * TILE_SIZE;
				int	tileY = i * TILE_SIZE;
				int	tileColor = map[i][j] != 0 ? 255 : 0;

				if (config->map[i][j] == '1')
				render_rect(config->conn_mlx,
					tileX * MINIMAP_SCALE_FACTOR,
					tileY * MINIMAP_SCALE_FACTOR,
					TILE_SIZE * MINIMAP_SCALE_FACTOR,
					TILE_SIZE * MINIMAP_SCALE_FACTOR,
					WHITE_PIXEL,
					&config->img
				);
				else
					render_rect(config->conn_mlx,
						tileX * MINIMAP_SCALE_FACTOR,
						tileY * MINIMAP_SCALE_FACTOR,
						TILE_SIZE * MINIMAP_SCALE_FACTOR,
						TILE_SIZE * MINIMAP_SCALE_FACTOR,
						BLACK_PIXEL,
						&config->img
					);
				j++;
			}
			i++;
		}
	}
}

