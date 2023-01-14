/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 01:12:15 by anjose-d          #+#    #+#             */
/*   Updated: 2023/01/14 20:13:10 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	load_game(t_config *config)
{
	(void)config;
	update(config);
	// raycaster(config);
	minimap(config);
	mlx_put_image_to_window(config->conn_mlx.mlx_ptr,
		config->conn_mlx.win_ptr,
		config->img.mlx_img, 0, 0);
	return (0);
}
