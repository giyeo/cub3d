/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 12:02:23 by rpaulino          #+#    #+#             */
/*   Updated: 2022/12/30 12:13:11 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	img_init(t_img *img, t_config *config);

int	main(int argc, char *argv[])
{
	t_config	config;
	char		**buffer;
	int			fd;

	config_init(&config);
	fd = file_validate(argv[1], argc);
	buffer = read_file(fd, argv[1]);
	close(fd);
	parser_and_validate(buffer, &config);
	ft_destroy_matrix(buffer);

	// init window
	config.conn_mlx.mlx_ptr = mlx_init();
	config.conn_mlx.win_ptr = mlx_new_window(config.conn_mlx.mlx_ptr,
		WINDOW_WIDTH, WINDOW_HEIGHT, "TEST");

	config.img.mlx_img = mlx_new_image(config.conn_mlx.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	config.img.addr = mlx_get_data_addr(config.img.mlx_img, &config.img.bpp, &config.img.line_len, &config.img.endian);

	config.player.x = config.player_position[0];
	config.player.y = config.player_position[1];
	config.player.height = 5;
	config.player.width = 5;
	config.player.turn_direction = 0;
	config.player.walk_direction = 0;
	config.player.rotation_angle = PI / 2; // pointing down
	config.player.walk_speed = 100;
	config.player.turn_speed = 45 * (PI / 180); // ((PI / 180)) == converting to radians

	mlx_hook(config.conn_mlx.win_ptr, KeyPress, KeyPressMask, &key_mapping, &config);
	mlx_hook(config.conn_mlx.win_ptr, DestroyNotify, NoEventMask, &end_game, &config);
	mlx_loop_hook(config.conn_mlx.mlx_ptr, &load_game, &config);
	mlx_loop(config.conn_mlx.mlx_ptr);

	return (0);
}
