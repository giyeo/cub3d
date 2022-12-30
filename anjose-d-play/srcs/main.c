/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 12:02:23 by rpaulino          #+#    #+#             */
/*   Updated: 2022/12/29 22:45:55 by anjose-d         ###   ########.fr       */
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
		config.window_width, config.window_height, "TEST");

	config.img.mlx_img = mlx_new_image(config.conn_mlx.mlx_ptr, config.window_width, config.window_height);
	config.img.addr = mlx_get_data_addr(config.img.mlx_img, &config.img.bpp, &config.img.line_len, &config.img.endian);

	config.player.height = 1;
	config.player.width = 1;
	config.player.x = config.player_position[0];
	config.player.y = config.player_position[1];
	config.player.rotation_angle = PI / 2;
	config.player.walk_speed = 100;
	config.player.turn_speed = 45 * (PI / 180);

	mlx_hook(config.conn_mlx.win_ptr, KeyPress, KeyPressMask, &key_mapping, &config);
	mlx_hook(config.conn_mlx.win_ptr, DestroyNotify, NoEventMask, &end_game, &config);
	mlx_loop_hook(config.conn_mlx.mlx_ptr, &load_game, &config);
	mlx_loop(config.conn_mlx.mlx_ptr);

	return (0);
}
