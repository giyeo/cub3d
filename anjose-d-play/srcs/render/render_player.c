/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:12:18 by anjose-d          #+#    #+#             */
/*   Updated: 2022/12/30 12:42:56 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_player(t_config *config)
{
	char **map;
	int	i;
	int	j;

	map = config->map;

	if (config->conn_mlx.win_ptr != NULL)
	{
		i = 0;
		while (config->map[i])
		{
			j = 0;
			while (config->map[i][j])
			{
				int	tileX = config->player.y * TILE_SIZE;
				int	tileY = config->player.x * TILE_SIZE;
				int	tileColor = map[i][j] != 0 ? 255 : 0;

				if (config->map[i][j] == 'N')
				{
					render_rect(config->conn_mlx,
						tileX,
						tileY,
						TILE_SIZE / 4,
						TILE_SIZE / 4,
						0xFFFF00,
						&config->img
					);
				}
				j++;
			}
			i++;
		}
	}
}
