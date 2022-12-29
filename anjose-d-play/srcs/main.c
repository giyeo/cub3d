/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 12:02:23 by rpaulino          #+#    #+#             */
/*   Updated: 2022/12/28 21:45:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char *argv[])
{
	t_config	config;
	char		**buffer;
	int			fd;
	t_conn		conn_mlx;

	config_init(&config);
	fd = file_validate(argv[1], argc);
	buffer = read_file(fd, argv[1]);
	close(fd);
	parser_and_validate(buffer, &config);

	// init window
	conn_mlx.mlx_ptr = mlx_init();
	int	WINDOW_WIDTH = IMG_SIZE * ft_mtx_biggest_strlen(config.map);
	int	WINDOW_HEIGHT = IMG_SIZE * ft_mtxlen(config.map);
	conn_mlx.win_ptr = mlx_new_window(conn_mlx.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "TEST");
	mlx_loop(conn_mlx.mlx_ptr);

	ft_destroy_matrix(buffer);
	free_config(&config);
	return (0);
}
