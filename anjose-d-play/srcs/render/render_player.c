/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:12:18 by anjose-d          #+#    #+#             */
/*   Updated: 2022/12/29 22:20:01 by anjose-d         ###   ########.fr       */
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
				int	tileX = j * IMG_SIZE;
				int	tileY = i * IMG_SIZE;
				int	tileColor = map[i][j] != 0 ? 255 : 0;

				if (config->map[i][j] == 'N')
				{
					render_rect(config->conn_mlx,
						tileX,
						tileY,
						IMG_SIZE / 4,
						IMG_SIZE / 4,
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

void	move_player(t_config *config)
{
	float newPlayerX = config->player.x + 10;
	float newPlayerY = config->player.y + 10;

	// TODO:
	// perform wall collision
	config->player.x = newPlayerX;
	config->player.y = newPlayerY;
}