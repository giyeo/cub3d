/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 12:02:23 by rpaulino          #+#    #+#             */
/*   Updated: 2022/12/29 01:13:24 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	int	WINDOW_WIDTH = IMG_SIZE * ft_mtx_biggest_strlen(config.map);
	int	WINDOW_HEIGHT = IMG_SIZE * ft_mtxlen(config.map);
	config.conn_mlx.win_ptr = mlx_new_window(config.conn_mlx.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "TEST");
	
	mlx_hook(config.conn_mlx.win_ptr, KeyPress, KeyPressMask, &key_mapping, &config);
	mlx_hook(config.conn_mlx.win_ptr, DestroyNotify, NoEventMask, &end_game, &config);
	mlx_loop_hook(config.conn_mlx.mlx_ptr, &load_game, &config);
	mlx_loop(config.conn_mlx.mlx_ptr);


	return (0);
}
