/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 01:12:15 by anjose-d          #+#    #+#             */
/*   Updated: 2022/12/30 12:47:37 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	load_game(t_config *config)
{
	(void)config;

	// TODO:
	// clear_window();
	render_background(config, BLACK_PIXEL, &config->img);
	// update_values();

	// if (config->map[(int)config->player.x] && config->map[(int)config->player.y])
	// {
	// 	config->player.x += 1 * 0.1;
	// 	config->player.y += 1 * 0.1;
	// }
	render_map(config);
	// render_rays();
	// render_player(config);
	mlx_put_image_to_window(config->conn_mlx.mlx_ptr,
			config->conn_mlx.win_ptr,
			config->img.mlx_img, 0, 0
		);
	return (0);
}