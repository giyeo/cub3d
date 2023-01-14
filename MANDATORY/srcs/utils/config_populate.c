/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_populate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 00:01:09 by anjose-d          #+#    #+#             */
/*   Updated: 2023/01/14 17:42:59 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	player_init(t_config *config);
static void	mlx_conn_init(t_config *config);
static void	img_init(t_config *config);

void	config_populate(t_config *config)
{
	config->map_num_rows = ft_mtxlen(config->map);
	config->map_num_cols = ft_mtx_biggest_strlen(config->map);
	player_init(config);
	mlx_conn_init(config);
	img_init(config);
}

static void	player_init(t_config *config)
{
	config->player.x = config->player_position[1] + 0.5;
	config->player.y = config->player_position[0] + 0.5;
	config->player.height = 50;
	config->player.width = 50;
	config->player.turn_direction = 0;
	config->player.walk_direction = 0;
	config->player.walk_side_direction = 0;
	if (config->player_direction == 'N')
		config->player.rotation_angle = PI + PI / 2;
	else if (config->player_direction == 'S')
		config->player.rotation_angle = PI / 2;
	else if (config->player_direction == 'W')
		config->player.rotation_angle = PI;
	else if (config->player_direction == 'E')
		config->player.rotation_angle = 0;
	config->player.walk_speed = 1.0 / 10.0;
	config->player.turn_speed = 2 * (PI / 180);
	config->player.interact = 0;
}

static void	mlx_conn_init(t_config *config)
{
	config->conn_mlx.mlx_ptr = mlx_init();
	config->conn_mlx.win_ptr = mlx_new_window(config->conn_mlx.mlx_ptr,
			WINDOW_WIDTH, WINDOW_HEIGHT, "TEST");
}

static void	img_init(t_config *config)
{
	config->img.mlx_img = mlx_new_image(
			config->conn_mlx.mlx_ptr,
			WINDOW_WIDTH,
			WINDOW_HEIGHT
			);
	config->img.addr = mlx_get_data_addr(
			config->img.mlx_img,
			&config->img.bpp,
			&config->img.line_len,
			&config->img.endian
			);
}
