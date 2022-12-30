/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 01:12:15 by anjose-d          #+#    #+#             */
/*   Updated: 2022/12/29 22:16:51 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	load_game(t_config *config)
{
	(void)config;

	// TODO:
	// clear_window();
	// update_values();
	render_map(config);
	// render_rays();
	render_player(config);
	mlx_put_image_to_window(config->conn_mlx.mlx_ptr,
			config->conn_mlx.win_ptr,
			config->img.mlx_img, 0, 0
		);
	return (0);
}