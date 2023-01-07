/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_and_validate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 12:09:44 by rpaulino          #+#    #+#             */
/*   Updated: 2023/01/07 16:17:29 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	player_init(t_config *config);
void	mlx_conn_init(t_config *config);
void	img_init(t_config *config);

void	parser_and_validate(char **buffer, t_config *config)
{
	int line_start_map;

	line_start_map = validate_config(buffer, config);
	check_struct(config, 0);
	validate_map(buffer + line_start_map, config);
	check_struct(config, 1);

	config->map_num_rows = ft_mtxlen(config->map);
	config->map_num_cols = ft_mtx_biggest_strlen(config->map);
	config->window_height = config->map_num_rows * TILE_SIZE;
	config->window_width = config->map_num_cols * TILE_SIZE;
	config->num_rays = config->window_width;
	config->rays = malloc(sizeof(t_ray) * config->num_rays);

	player_init(config);
	mlx_conn_init(config);
	img_init(config);
}

void	player_init(t_config *config)
{
	config->player.x = config->player_position[1];
	config->player.y = config->player_position[0];
	config->player.height = 50;
	config->player.width = 50;
	config->player.turn_direction = 0;
	config->player.walk_direction = 0;
	config->player.rotation_angle = PI / 2; // pointing down
	config->player.walk_speed = 1.0 / 40.0;
	config->player.turn_speed = 0.05 * (PI / 180); // ((PI / 180)) == converting to radians
	config->player.fov = 60.0 * (PI / 180);
}

void	mlx_conn_init(t_config *config)
{
	config->conn_mlx.mlx_ptr = mlx_init();
	config->conn_mlx.win_ptr = mlx_new_window(config->conn_mlx.mlx_ptr,
		config->window_width, config->window_height, "TEST");
}
void	img_init(t_config *config)
{
	config->img.mlx_img = mlx_new_image(config->conn_mlx.mlx_ptr,
		config->window_width,
		config->window_height
	);
	config->img.addr = mlx_get_data_addr(config->img.mlx_img,
		&config->img.bpp,
		&config->img.line_len,
		&config->img.endian
	);
}
