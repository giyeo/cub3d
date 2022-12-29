/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 01:20:32 by anjose-d          #+#    #+#             */
/*   Updated: 2022/12/29 11:51:39 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define RED_PIXEL 0xFF0000
#define GREEN_PIXEL 0xFF00
#define WHITE_PIXEL 0xFFFFFF

#include "cub3d.h"

int		render_rect(t_conn conn_mlx, int x, int y, int rect_height, int rect_width, int color);
int		render_background(t_config *config, int color);

void	render_map(t_config *config)
{
	char **map;

	map = config->map;
	(void)map;
	if (config->conn_mlx.win_ptr != NULL)
	{
		render_background(config, WHITE_PIXEL);
		render_rect(config->conn_mlx,
			config->window_width - 100,
			config->window_height - 100,
			100,
			100,
			GREEN_PIXEL
		);
		render_rect(config->conn_mlx,
			0,
			0,
			100,
			100,
			RED_PIXEL
		);
	}
}

int	render_rect(t_conn conn_mlx, int x, int y, int rect_height, int rect_width, int color)
{
	int	i;
	int j;

	if (conn_mlx.win_ptr == NULL)
		return (1);
	i = y;
	while (i < y + rect_height)
	{
		j = x;
		while (j < x + rect_width)
			mlx_pixel_put(conn_mlx.mlx_ptr, conn_mlx.win_ptr,
				j++, i, color);
		i++;
	}
	return (0);
}

int	render_background(t_config *config, int color)
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
			mlx_pixel_put(config->conn_mlx.mlx_ptr, config->conn_mlx.win_ptr, j++, i, color);
		i++;
	}
	return (0);
}