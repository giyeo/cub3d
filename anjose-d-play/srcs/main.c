/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 12:02:23 by rpaulino          #+#    #+#             */
/*   Updated: 2022/12/29 11:22:46 by anjose-d         ###   ########.fr       */
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
	config.window_height = IMG_SIZE * ft_mtxlen(config.map); 
	config.window_width = IMG_SIZE * ft_mtx_biggest_strlen(config.map);
	config.conn_mlx.win_ptr = mlx_new_window(config.conn_mlx.mlx_ptr,
		config.window_width, config.window_height, "TEST");
	
	mlx_hook(config.conn_mlx.win_ptr, KeyPress, KeyPressMask, &key_mapping, &config);
	mlx_hook(config.conn_mlx.win_ptr, DestroyNotify, NoEventMask, &end_game, &config);
	mlx_loop_hook(config.conn_mlx.mlx_ptr, &load_game, &config);
	mlx_loop(config.conn_mlx.mlx_ptr);


	return (0);
}
