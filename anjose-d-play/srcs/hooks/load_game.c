/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 01:12:15 by anjose-d          #+#    #+#             */
/*   Updated: 2023/01/09 12:21:49 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ray_init(t_config *config);

int	load_game(t_config *config)
{	
	update(config);
	// raycaster(config);
	ray_init(config);
	minimap(config);
	mlx_put_image_to_window(config->conn_mlx.mlx_ptr,
		config->conn_mlx.win_ptr,
		config->img.mlx_img, 0, 0);
	return (0);
}

void	ray_init(t_config *config)
{
	config->rays = malloc(sizeof(t_ray) * WINDOW_WIDTH);
	int i = 0;
	while (i < WINDOW_WIDTH)
	{
		config->rays[i].angle = 0;
		config->rays[i].wallHitX = 0;
		config->rays[i].wallHitY = 0;
		config->rays[i].distance = 0;
		config->rays[i].wasHitVertical = FALSE;
		config->rays[i].hitWallColor = 0;
		config->rays[i].is_fdown = 0;
		config->rays[i].is_fup = 0;
		config->rays[i].is_fright = 0;
		config->rays[i].is_fleft = 0;
		i++;
	}
}
